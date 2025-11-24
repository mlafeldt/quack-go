package main

/*
#include <duckdb_extension.h>
#include <stdlib.h>

void extension_set_error(struct duckdb_extension_access *access, duckdb_extension_info info, const char *msg);
*/
import "C"

import (
	"unsafe"

	duckdb "github.com/duckdb/duckdb-go-bindings"
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
		[]duckdb.Type{duckdb.TypeVarchar},
		duckdb.TypeVarchar,
		quackImpl,
	)
	if err != nil {
		errMsg := C.CString("Failed to register quack function: " + err.Error())
		defer C.free(unsafe.Pointer(errMsg))
		C.extension_set_error(access, info, errMsg)
		return C.bool(false)
	}

	return C.bool(true)
}

// quackImpl implements the quack scalar function.
// It takes a VARCHAR input and returns "Quack <input> 🐥".
func quackImpl(info unsafe.Pointer, input unsafe.Pointer, output unsafe.Pointer) {
	// Wrap raw pointers in type-safe structs
	chunk := duckdb.DataChunk{Ptr: input}
	outputVec := duckdb.Vector{Ptr: output}

	// Get input vector and data
	inputVec := duckdb.DataChunkGetVector(chunk, 0)
	inputData := (*[1 << 28]duckdb.StringT)(duckdb.VectorGetData(inputVec))
	inputValidity := duckdb.VectorGetValidity(inputVec)

	// Prepare output validity
	duckdb.VectorEnsureValidityWritable(outputVec)
	outputValidity := duckdb.VectorGetValidity(outputVec)

	numRows := duckdb.DataChunkGetSize(chunk)

	for row := range numRows {
		// Handle NULL values
		if !duckdb.ValidityRowIsValid(inputValidity, row) {
			duckdb.ValiditySetRowInvalid(outputValidity, row)
			continue
		}

		// Extract input string (no manual C.GoStringN needed!)
		goStr := duckdb.StringTData(&inputData[row])

		// Apply transformation
		result := prefix + goStr + suffix

		// Assign result (no manual C.CString/C.free needed!)
		duckdb.VectorAssignStringElement(outputVec, row, result)
	}
}

// Dummy main
func main() {}
