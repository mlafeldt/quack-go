package main

/*
#cgo CFLAGS: -I./include -DDUCKDB_BUILD_LOADABLE_EXTENSION=1

#include <duckdb_extension.h>
#include <stdint.h>
#include <stdlib.h>

DUCKDB_EXTENSION_EXTERN

#include "duckdb_cgo_shims.h"

// Provided in cbridge.go
void extension_set_error(struct duckdb_extension_access *access, duckdb_extension_info info, const char *msg);
*/
import "C"

import (
	"unsafe"

	"github.com/mlafeldt/quack-go/duckdbext"
)

const (
	prefix = "Quack "
	suffix = " 🐥"
)

//export initExtension
func initExtension(conn C.duckdb_connection, info C.duckdb_extension_info, access *C.struct_duckdb_extension_access) C.bool {
	err := duckdbext.RegisterScalarFunction(
		unsafe.Pointer(conn),
		"quack",
		[]duckdbext.DType{duckdbext.DType(C.DUCKDB_TYPE_VARCHAR)},
		duckdbext.DType(C.DUCKDB_TYPE_VARCHAR),
		quack,
	)
	if err != nil {
		errMsg := C.CString("Failed to register quack function")
		defer C.free(unsafe.Pointer(errMsg))
		C.extension_set_error(access, info, errMsg)
		return C.bool(false)
	}
	return C.bool(true)
}

func quack(info unsafe.Pointer, input unsafe.Pointer, output unsafe.Pointer) {
	cInput := (C.duckdb_data_chunk)(input)
	cOutput := (C.duckdb_vector)(output)

	inputVector := C.duckdb_data_chunk_get_vector_(cInput, 0)
	inputData := (*[1 << 28]C.duckdb_string_t)(C.duckdb_vector_get_data_(inputVector))
	inputValidity := C.duckdb_vector_get_validity_(inputVector)

	C.duckdb_vector_ensure_validity_writable_(cOutput)
	outputValidity := C.duckdb_vector_get_validity_(cOutput)

	numRows := C.duckdb_data_chunk_get_size_(cInput)

	for row := range numRows {
		if !C.duckdb_validity_row_is_valid_(inputValidity, row) {
			C.duckdb_validity_set_row_invalid_(outputValidity, row)
			continue
		}

		inputStr := &inputData[row]
		cStr := C.duckdb_string_t_data_(inputStr)
		length := C.duckdb_string_t_length_(*inputStr)
		goStr := C.GoStringN(cStr, C.int(length))

		result := prefix + goStr + suffix

		resultCStr := C.CString(result)
		C.duckdb_vector_assign_string_element_len_(cOutput, row, resultCStr, C.idx_t(len(result)))
		C.free(unsafe.Pointer(resultCStr))
	}
}

// Dummy main
func main() {}
