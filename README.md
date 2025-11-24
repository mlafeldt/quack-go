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
