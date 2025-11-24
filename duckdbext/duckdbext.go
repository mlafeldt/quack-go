package duckdbext

/*
#cgo CFLAGS: -I../include -DDUCKDB_BUILD_LOADABLE_EXTENSION=1

#include <duckdb_extension.h>
#include <stdint.h>
#include <stdlib.h>

extern duckdb_ext_api_v1 duckdb_ext_api;

#include "duckdb_cgo_shims.h"

void scalarFunctionWrapper(duckdb_function_info info, duckdb_data_chunk input, duckdb_vector output);
void extraInfoDestroy(void *ptr);
*/
import "C"

import (
	"errors"
	"runtime/cgo"
	"unsafe"
)

type (
	// Raw C pointers to avoid cross-package C type coupling
	ScalarFuncImpl func(info unsafe.Pointer, input unsafe.Pointer, output unsafe.Pointer)
	DType          uint32
)

// Dispatch looks up the Go function handle stored in DuckDB's extra_info and executes it.
func Dispatch(info unsafe.Pointer, input unsafe.Pointer, output unsafe.Pointer) {
	cInfo := (C.duckdb_function_info)(info)
	extraInfo := C.duckdb_scalar_function_get_extra_info_(cInfo)
	if extraInfo == nil {
		return
	}

	h := cgo.Handle(*(*C.uintptr_t)(extraInfo))
	impl, ok := h.Value().(ScalarFuncImpl)
	if !ok {
		return
	}

	impl(info, input, output)
}

// DeleteHandle releases a Go handle allocated for DuckDB extra_info.
func DeleteHandle(ptr unsafe.Pointer) {
	if ptr == nil {
		return
	}
	h := cgo.Handle(*(*C.uintptr_t)(ptr))
	h.Delete()
	C.free(ptr)
}

// RegisterScalarFunction registers a scalar function with DuckDB using the C API.
func RegisterScalarFunction(
	conn unsafe.Pointer,
	name string,
	paramTypes []DType,
	returnType DType,
	impl ScalarFuncImpl,
) error {
	cConn := (C.duckdb_connection)(conn)
	funcHandle := C.duckdb_create_scalar_function_()

	funcName := C.CString(name)
	defer C.free(unsafe.Pointer(funcName))
	C.duckdb_scalar_function_set_name_(funcHandle, funcName)

	for _, paramType := range paramTypes {
		logicalType := C.duckdb_create_logical_type_(C.duckdb_type(paramType))
		C.duckdb_scalar_function_add_parameter_(funcHandle, logicalType)
		C.duckdb_destroy_logical_type_(&logicalType)
	}

	returnLogicalType := C.duckdb_create_logical_type_(C.duckdb_type(returnType))
	C.duckdb_scalar_function_set_return_type_(funcHandle, returnLogicalType)
	C.duckdb_destroy_logical_type_(&returnLogicalType)

	handle := cgo.NewHandle(impl)

	handlePtr := C.malloc(C.sizeof_uintptr_t)
	if handlePtr == nil {
		handle.Delete()
		return errors.New("failed to allocate extra_info")
	}
	*(*C.uintptr_t)(handlePtr) = C.uintptr_t(handle)

	C.duckdb_scalar_function_set_extra_info_(funcHandle, handlePtr, C.duckdb_delete_callback_t(C.extraInfoDestroy))
	C.duckdb_scalar_function_set_function_(funcHandle, C.duckdb_scalar_function_t(C.scalarFunctionWrapper))

	state := C.duckdb_register_scalar_function_(cConn, funcHandle)
	C.duckdb_destroy_scalar_function_(&funcHandle)

	if state == C.DuckDBError {
		return errors.New("failed to register scalar function: " + name)
	}
	return nil
}
