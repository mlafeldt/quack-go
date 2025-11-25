EXTENSION_NAME := quack
EXTENSION_VERSION := v0.1.0

DUCKDB_VERSION := v1.4.2
C_API_VERSION := v1.2.0

# Detect host platform; override with PLATFORM=<duckdb platform string>
HOST_OS := $(shell uname -s | tr '[:upper:]' '[:lower:]')
HOST_ARCH := $(shell uname -m | sed 's/x86_64/amd64/;s/aarch64/arm64/')
PLATFORM ?= $(if $(filter darwin,$(HOST_OS)),osx,$(HOST_OS))_$(HOST_ARCH)

ifeq ($(PLATFORM),osx_arm64)
export GOOS := darwin
export GOARCH := arm64
LIB_PREFIX := lib
LIB_EXT := dylib
else ifeq ($(PLATFORM),osx_amd64)
export GOOS := darwin
export GOARCH := amd64
LIB_PREFIX := lib
LIB_EXT := dylib
else ifeq ($(PLATFORM),linux_amd64)
export GOOS := linux
export GOARCH := amd64
LIB_PREFIX := lib
LIB_EXT := so
GO_BUILD_TAGS := duckdb_use_lib
DUCKDB_LIB_PATH ?=
ifneq ($(strip $(DUCKDB_LIB_PATH)),)
export CGO_LDFLAGS := -L$(DUCKDB_LIB_PATH) -Wl,-rpath,$(DUCKDB_LIB_PATH)
endif
else ifeq ($(PLATFORM),linux_arm64)
export GOOS := linux
export GOARCH := arm64
LIB_PREFIX := lib
LIB_EXT := so
GO_BUILD_TAGS := duckdb_use_lib
DUCKDB_LIB_PATH ?=
ifneq ($(strip $(DUCKDB_LIB_PATH)),)
export CGO_LDFLAGS := -L$(DUCKDB_LIB_PATH) -Wl,-rpath,$(DUCKDB_LIB_PATH)
endif
else
$(error Unsupported platform: "$(PLATFORM)")
endif

export CGO_ENABLED := 1

BUILD_DIR := build
EXTENSION_LIB_FILE := $(BUILD_DIR)/$(PLATFORM)/$(LIB_PREFIX)$(EXTENSION_NAME).$(LIB_EXT)
EXTENSION_FILE := $(BUILD_DIR)/$(PLATFORM)/$(EXTENSION_NAME).duckdb_extension

all: $(EXTENSION_FILE)

$(EXTENSION_FILE): $(GO_SRCS) go.mod go.sum | $(BUILD_DIR)/$(PLATFORM)
	go build -tags="$(GO_BUILD_TAGS)" -buildmode=c-shared -o $(EXTENSION_LIB_FILE) .
	python3 append_metadata.py \
		--extension-name $(EXTENSION_NAME) \
		--extension-version $(EXTENSION_VERSION) \
		--duckdb-platform $(PLATFORM) \
		--duckdb-version $(C_API_VERSION) \
		--library-file $(EXTENSION_LIB_FILE) \
		--out-file $(EXTENSION_FILE)

$(BUILD_DIR)/$(PLATFORM):
	mkdir -p $(BUILD_DIR)/$(PLATFORM)

clean:
	rm -rf $(BUILD_DIR)

test: $(EXTENSION_FILE)
	duckdb -unsigned -c "LOAD '$(EXTENSION_FILE)'; SELECT quack('Go');"

.PHONY: all clean test
