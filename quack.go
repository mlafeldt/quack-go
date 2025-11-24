package main

/*
#include <duckdb_extension.h>
#include <stdlib.h>
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
		duckdb.Connection{Ptr: unsafe.Pointer(conn)},
		"quack",
		[]duckdb.Type{duckdb.TypeVarchar},
		duckdb.TypeVarchar,
		quack,
	)
	if err != nil {
		duckdbext.SetExtensionError(
			duckdbext.ExtensionAccess{Ptr: unsafe.Pointer(access)},
			duckdbext.ExtensionInfo{Ptr: unsafe.Pointer(info)},
			"Failed to register quack function: "+err.Error(),
		)
		return C.bool(false)
	}

	return C.bool(true)
}

func quack(info duckdb.FunctionInfo, input duckdb.DataChunk, output duckdb.Vector) {
	inputVec := duckdb.DataChunkGetVector(input, 0)
	inputData := (*[1 << 28]duckdb.StringT)(duckdb.VectorGetData(inputVec))
	inputValidity := duckdb.VectorGetValidity(inputVec)

	duckdb.VectorEnsureValidityWritable(output)
	outputValidity := duckdb.VectorGetValidity(output)

	numRows := duckdb.DataChunkGetSize(input)

	for row := range numRows {
		if !duckdb.ValidityRowIsValid(inputValidity, row) {
			duckdb.ValiditySetRowInvalid(outputValidity, row)
			continue
		}
		goStr := duckdb.StringTData(&inputData[row])
		result := prefix + goStr + suffix
		duckdb.VectorAssignStringElement(output, row, result)
	}
}

// Dummy main
func main() {}
