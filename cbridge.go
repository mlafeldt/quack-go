package main

/*
#cgo CFLAGS: -I./include -DDUCKDB_EXTENSION_NAME=quack -DDUCKDB_BUILD_LOADABLE_EXTENSION=1
#cgo darwin,arm64 LDFLAGS: -Wl,-undefined,dynamic_lookup

#include <duckdb_extension.h>
#include <stdint.h>
#include <stdlib.h>

#undef DUCKDB_EXTENSION_GLOBAL
#define DUCKDB_EXTENSION_GLOBAL __attribute__((weak)) duckdb_ext_api_v1 duckdb_ext_api = {0};

#undef DUCKDB_CAPI_ENTRY_VISIBILITY
#define DUCKDB_CAPI_ENTRY_VISIBILITY __attribute__((visibility("default"), weak))

DUCKDB_EXTENSION_EXTERN
#include "duckdb_cgo_shims.h"

DUCKDB_CAPI_ENTRY_VISIBILITY __attribute__((used)) void extension_set_error(struct duckdb_extension_access *access, duckdb_extension_info info, const char *msg) {
    access->set_error(info, msg);
}

// Go entrypoints
extern bool initExtension(duckdb_connection connection, duckdb_extension_info info, struct duckdb_extension_access *access);
extern void goScalarDispatch(duckdb_function_info info, duckdb_data_chunk input, duckdb_vector output);
extern void goDeleteHandle(void *ptr);

// Trampoline + entrypoint
__attribute__((weak)) void scalarFunctionWrapper(duckdb_function_info info, duckdb_data_chunk input, duckdb_vector output) {
    goScalarDispatch(info, input, output);
}

__attribute__((weak)) void extraInfoDestroy(void *ptr) { goDeleteHandle(ptr); }

// DuckDB will set duckdb_ext_api for us and hand us an open connection.
DUCKDB_EXTENSION_ENTRYPOINT(duckdb_connection connection, duckdb_extension_info info, struct duckdb_extension_access *access) {
    return initExtension(connection, info, access);
}
*/
import "C"

import (
	"unsafe"

	"github.com/mlafeldt/quack-go/duckdbext"
)

//export goScalarDispatch
func goScalarDispatch(info C.duckdb_function_info, input C.duckdb_data_chunk, output C.duckdb_vector) {
	duckdbext.Dispatch(
		unsafe.Pointer(info),
		unsafe.Pointer(input),
		unsafe.Pointer(output),
	)
}

//export goDeleteHandle
func goDeleteHandle(ptr unsafe.Pointer) {
	duckdbext.DeleteHandle(ptr)
}
