# quack-go

Highly experimental Go implementation of the [DuckDB quack extension](https://duckdb.org/community_extensions/extensions/quack)

## Usage

Run `make` to build the extension or `make test` to build then load the extension into DuckDB and run the quack function.

## Project layout

- `cbridge.go` (package `main`): CGO preamble, DuckDB entrypoint macro, and `//export` trampolines. Must be in `package main` so the shared library exports the right symbols.
- `quack.go` (package `main`): extension-specific wiring and the `quack` scalar implementation.
- `duckdbext/`: reusable Go helpers for registering scalar functions and dispatching Go callbacks.
- `include/duckdb_cgo_shims.h`: generated shims that turn DuckDB macro APIs into real symbols CGO can call.

## CGO quirks

- DuckDB's extension APIs are macro aliases into a function-pointer struct (`duckdb_ext_api_v1`), not exported symbols, so CGO needs real C shim functions; C/Zig can expand the macros inline, Go cannot.
- CGO can't directly invoke a function pointer stored in a struct field (e.g., `access->set_error`) from Go; it wants a callable symbol. We expose small C helpers/trampolines (see `cbridge.go` and generated shims) to bridge this.
