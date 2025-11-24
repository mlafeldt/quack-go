EXTENSION_NAME := quack
EXTENSION_VERSION := v0.1.0

DUCKDB_VERSION := v1.4.2
C_API_VERSION := v1.2.0
PLATFORM := osx_arm64

BUILD_DIR := build
EXTENSION_LIB_FILE := $(BUILD_DIR)/$(PLATFORM)/lib$(EXTENSION_NAME).dylib
EXTENSION_FILE := $(BUILD_DIR)/$(PLATFORM)/$(EXTENSION_NAME).duckdb_extension

GO_SRCS := $(wildcard *.go) $(wildcard duckdbext/*.go)

GO_LDFLAGS :=

# TODO: Add support for other platforms
ifeq ($(PLATFORM),osx_arm64)
export GOOS := darwin
export GOARCH := arm64
endif

all: $(EXTENSION_FILE)

$(BUILD_DIR)/$(PLATFORM):
	mkdir -p $(BUILD_DIR)/$(PLATFORM)

$(EXTENSION_FILE): $(GO_SRCS) go.mod go.sum | $(BUILD_DIR)/$(PLATFORM)
	go build -buildmode=c-shared -ldflags="$(GO_LDFLAGS)" -o $(EXTENSION_LIB_FILE) .
	python3 append_metadata.py \
		--extension-name $(EXTENSION_NAME) \
		--extension-version $(EXTENSION_VERSION) \
		--duckdb-platform $(PLATFORM) \
		--duckdb-version $(C_API_VERSION) \
		--library-file $(EXTENSION_LIB_FILE) \
		--out-file $(EXTENSION_FILE)

clean:
	rm -rf $(BUILD_DIR)

test: $(EXTENSION_FILE)
	duckdb -unsigned -c "LOAD '$(EXTENSION_FILE)'; SELECT quack('Go');"
