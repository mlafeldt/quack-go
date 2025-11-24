package duckdbext

/*
#cgo CFLAGS: -I../include -DDUCKDB_BUILD_LOADABLE_EXTENSION=1

#include <duckdb_extension.h>
#include <stdint.h>
#include <stdlib.h>

extern duckdb_ext_api_v1 duckdb_ext_api;

void scalarFunctionWrapper(duckdb_function_info info, duckdb_data_chunk input, duckdb_vector output);
void extraInfoDestroy(void *ptr);
void extension_set_error(struct duckdb_extension_access *access, duckdb_extension_info info, const char *msg);
*/
import "C"

import (
	"errors"
	"runtime/cgo"
	"unsafe"

	duckdb "github.com/duckdb/duckdb-go-bindings"
)

type (
	// ScalarFuncImpl is the signature for Go scalar function implementations
	ScalarFuncImpl func(info duckdb.FunctionInfo, input duckdb.DataChunk, output duckdb.Vector)

	// ExtensionInfo wraps duckdb_extension_info
	ExtensionInfo struct {
		Ptr unsafe.Pointer
	}

	// ExtensionAccess wraps duckdb_extension_access
	ExtensionAccess struct {
		Ptr unsafe.Pointer
	}
)

// Dispatch looks up the Go function handle stored in DuckDB's extra_info and executes it.
func Dispatch(info duckdb.FunctionInfo, input duckdb.DataChunk, output duckdb.Vector) {
	extraInfo := duckdb.ScalarFunctionGetExtraInfo(info)
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
	conn duckdb.Connection,
	name string,
	paramTypes []duckdb.Type,
	returnType duckdb.Type,
	impl ScalarFuncImpl,
) error {
	funcHandle := duckdb.CreateScalarFunction()
	defer duckdb.DestroyScalarFunction(&funcHandle)

	duckdb.ScalarFunctionSetName(funcHandle, name)

	for _, paramType := range paramTypes {
		logicalType := duckdb.CreateLogicalType(paramType)
		duckdb.ScalarFunctionAddParameter(funcHandle, logicalType)
		duckdb.DestroyLogicalType(&logicalType)
	}

	returnLogicalType := duckdb.CreateLogicalType(returnType)
	duckdb.ScalarFunctionSetReturnType(funcHandle, returnLogicalType)
	duckdb.DestroyLogicalType(&returnLogicalType)

	handle := cgo.NewHandle(impl)
	handlePtr := C.malloc(C.sizeof_uintptr_t)
	if handlePtr == nil {
		handle.Delete()
		return errors.New("failed to allocate extra_info")
	}
	*(*C.uintptr_t)(handlePtr) = C.uintptr_t(handle)

	duckdb.ScalarFunctionSetExtraInfo(funcHandle, handlePtr, unsafe.Pointer(C.extraInfoDestroy))
	duckdb.ScalarFunctionSetFunction(funcHandle, unsafe.Pointer(C.scalarFunctionWrapper))

	state := duckdb.RegisterScalarFunction(conn, funcHandle)
	if state == duckdb.StateError {
		return errors.New("failed to register scalar function: " + name)
	}

	return nil
}

// SetExtensionError sets an error message for the extension initialization.
func SetExtensionError(access ExtensionAccess, info ExtensionInfo, message string) {
	errMsg := C.CString(message)
	defer C.free(unsafe.Pointer(errMsg))
	C.extension_set_error(
		(*C.struct_duckdb_extension_access)(access.Ptr),
		C.duckdb_extension_info(info.Ptr),
		errMsg,
	)
}
