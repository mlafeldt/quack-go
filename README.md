# quack-go

Highly experimental Go implementation of the [DuckDB quack extension](https://duckdb.org/community_extensions/extensions/quack).

## Usage

Run `make` to build the extension or `make test` to build then load the extension into DuckDB and run the quack function.

## Project Layout

- `quack.go`: Pure extension logic - the `quack` scalar function implementation
- `duckdbext/`: Reusable framework for registering scalar functions, and dispatching callbacks
- `cbridge.go`: Extension entry point, initialization, function registration, and CGO trampolines
- Uses [duckdb-go-bindings](https://github.com/duckdb/duckdb-go-bindings) for all DuckDB C API calls
  - Type-safe wrappers for `Vector`, `DataChunk`, `LogicalType`, etc.
  - All data manipulation APIs (no manual C pointer arithmetic!)
  - Memory-safe string handling (no manual `C.CString`/`C.free`)
  - Function registration APIs

## Platform Notes

- macOS (`PLATFORM=osx_arm64` or `osx_amd64`):

  - Uses `-Wl,-undefined,dynamic_lookup` so DuckDB resolves API symbols at load time.
  - Build: `make` (auto-detects host), or `PLATFORM=osx_arm64 make`.

- Linux (`PLATFORM=linux_arm64` or `linux_amd64`):

  - Go build tag `duckdb_use_lib` links against `libduckdb.so`; the host DuckDB must match.
  - Ensure `libduckdb.so` is on the default search path or set `DUCKDB_LIB_PATH=/path/to/libduckdb.so`.

- Windows:
  - Not supported here because Windows requires all DuckDB C API symbols to be resolved at link time; the current build is designed around runtime symbol resolution (macOS) or linking to `libduckdb.so` (Linux).
