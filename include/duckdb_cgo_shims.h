// Shim wrappers for DuckDB's extension API macros so CGO has real symbols.
#pragma once

#include <duckdb_extension.h>

// Stable functions: 356
// Unstable functions (skipped): 55
// Deprecated functions (skipped): 47

static inline duckdb_state duckdb_open_ext_(const char* path, duckdb_database* out_database, duckdb_config config, char** out_error) {
    return duckdb_open_ext(path, out_database, config, out_error);
}

static inline void duckdb_close_(duckdb_database* database) {
    duckdb_close(database);
}

static inline duckdb_state duckdb_connect_(duckdb_database database, duckdb_connection* out_connection) {
    return duckdb_connect(database, out_connection);
}

static inline void duckdb_interrupt_(duckdb_connection connection) {
    duckdb_interrupt(connection);
}

static inline duckdb_query_progress_type duckdb_query_progress_(duckdb_connection connection) {
    return duckdb_query_progress(connection);
}

static inline void duckdb_disconnect_(duckdb_connection* connection) {
    duckdb_disconnect(connection);
}

static inline const char* duckdb_library_version_() {
    return duckdb_library_version();
}

static inline duckdb_state duckdb_create_config_(duckdb_config* out_config) {
    return duckdb_create_config(out_config);
}

static inline size_t duckdb_config_count_() {
    return duckdb_config_count();
}

static inline duckdb_state duckdb_get_config_flag_(size_t index, const char** out_name, const char** out_description) {
    return duckdb_get_config_flag(index, out_name, out_description);
}

static inline duckdb_state duckdb_set_config_(duckdb_config config, const char* name, const char* option) {
    return duckdb_set_config(config, name, option);
}

static inline void duckdb_destroy_config_(duckdb_config* config) {
    duckdb_destroy_config(config);
}

static inline duckdb_state duckdb_query_(duckdb_connection connection, const char* query, duckdb_result* out_result) {
    return duckdb_query(connection, query, out_result);
}

static inline void duckdb_destroy_result_(duckdb_result* result) {
    duckdb_destroy_result(result);
}

static inline const char* duckdb_column_name_(duckdb_result* result, idx_t col) {
    return duckdb_column_name(result, col);
}

static inline duckdb_type duckdb_column_type_(duckdb_result* result, idx_t col) {
    return duckdb_column_type(result, col);
}

static inline duckdb_statement_type duckdb_result_statement_type_(duckdb_result result) {
    return duckdb_result_statement_type(result);
}

static inline duckdb_logical_type duckdb_column_logical_type_(duckdb_result* result, idx_t col) {
    return duckdb_column_logical_type(result, col);
}

static inline idx_t duckdb_column_count_(duckdb_result* result) {
    return duckdb_column_count(result);
}

static inline idx_t duckdb_rows_changed_(duckdb_result* result) {
    return duckdb_rows_changed(result);
}

static inline const char* duckdb_result_error_(duckdb_result* result) {
    return duckdb_result_error(result);
}

static inline duckdb_error_type duckdb_result_error_type_(duckdb_result* result) {
    return duckdb_result_error_type(result);
}

static inline duckdb_result_type duckdb_result_return_type_(duckdb_result result) {
    return duckdb_result_return_type(result);
}

static inline void* duckdb_malloc_(size_t size) {
    return duckdb_malloc(size);
}

static inline void duckdb_free_(void* ptr) {
    duckdb_free(ptr);
}

static inline idx_t duckdb_vector_size_() {
    return duckdb_vector_size();
}

static inline bool duckdb_string_is_inlined_(duckdb_string_t string) {
    return duckdb_string_is_inlined(string);
}

static inline uint32_t duckdb_string_t_length_(duckdb_string_t string) {
    return duckdb_string_t_length(string);
}

static inline const char* duckdb_string_t_data_(duckdb_string_t* string) {
    return duckdb_string_t_data(string);
}

static inline duckdb_date_struct duckdb_from_date_(duckdb_date date) {
    return duckdb_from_date(date);
}

static inline duckdb_date duckdb_to_date_(duckdb_date_struct date) {
    return duckdb_to_date(date);
}

static inline bool duckdb_is_finite_date_(duckdb_date date) {
    return duckdb_is_finite_date(date);
}

static inline duckdb_time_struct duckdb_from_time_(duckdb_time time) {
    return duckdb_from_time(time);
}

static inline duckdb_time_tz duckdb_create_time_tz_(int64_t micros, int32_t offset) {
    return duckdb_create_time_tz(micros, offset);
}

static inline duckdb_time_tz_struct duckdb_from_time_tz_(duckdb_time_tz micros) {
    return duckdb_from_time_tz(micros);
}

static inline duckdb_time duckdb_to_time_(duckdb_time_struct time) {
    return duckdb_to_time(time);
}

static inline duckdb_timestamp_struct duckdb_from_timestamp_(duckdb_timestamp ts) {
    return duckdb_from_timestamp(ts);
}

static inline duckdb_timestamp duckdb_to_timestamp_(duckdb_timestamp_struct ts) {
    return duckdb_to_timestamp(ts);
}

static inline bool duckdb_is_finite_timestamp_(duckdb_timestamp ts) {
    return duckdb_is_finite_timestamp(ts);
}

static inline double duckdb_hugeint_to_double_(duckdb_hugeint val) {
    return duckdb_hugeint_to_double(val);
}

static inline duckdb_hugeint duckdb_double_to_hugeint_(double val) {
    return duckdb_double_to_hugeint(val);
}

static inline double duckdb_uhugeint_to_double_(duckdb_uhugeint val) {
    return duckdb_uhugeint_to_double(val);
}

static inline duckdb_uhugeint duckdb_double_to_uhugeint_(double val) {
    return duckdb_double_to_uhugeint(val);
}

static inline duckdb_decimal duckdb_double_to_decimal_(double val, uint8_t width, uint8_t scale) {
    return duckdb_double_to_decimal(val, width, scale);
}

static inline double duckdb_decimal_to_double_(duckdb_decimal val) {
    return duckdb_decimal_to_double(val);
}

static inline duckdb_state duckdb_prepare_(duckdb_connection connection, const char* query, duckdb_prepared_statement* out_prepared_statement) {
    return duckdb_prepare(connection, query, out_prepared_statement);
}

static inline void duckdb_destroy_prepare_(duckdb_prepared_statement* prepared_statement) {
    duckdb_destroy_prepare(prepared_statement);
}

static inline const char* duckdb_prepare_error_(duckdb_prepared_statement prepared_statement) {
    return duckdb_prepare_error(prepared_statement);
}

static inline idx_t duckdb_nparams_(duckdb_prepared_statement prepared_statement) {
    return duckdb_nparams(prepared_statement);
}

static inline const char* duckdb_parameter_name_(duckdb_prepared_statement prepared_statement, idx_t index) {
    return duckdb_parameter_name(prepared_statement, index);
}

static inline duckdb_type duckdb_param_type_(duckdb_prepared_statement prepared_statement, idx_t param_idx) {
    return duckdb_param_type(prepared_statement, param_idx);
}

static inline duckdb_logical_type duckdb_param_logical_type_(duckdb_prepared_statement prepared_statement, idx_t param_idx) {
    return duckdb_param_logical_type(prepared_statement, param_idx);
}

static inline duckdb_state duckdb_clear_bindings_(duckdb_prepared_statement prepared_statement) {
    return duckdb_clear_bindings(prepared_statement);
}

static inline duckdb_statement_type duckdb_prepared_statement_type_(duckdb_prepared_statement statement) {
    return duckdb_prepared_statement_type(statement);
}

static inline duckdb_state duckdb_bind_value_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_value val) {
    return duckdb_bind_value(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_parameter_index_(duckdb_prepared_statement prepared_statement, idx_t* param_idx_out, const char* name) {
    return duckdb_bind_parameter_index(prepared_statement, param_idx_out, name);
}

static inline duckdb_state duckdb_bind_boolean_(duckdb_prepared_statement prepared_statement, idx_t param_idx, bool val) {
    return duckdb_bind_boolean(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_int8_(duckdb_prepared_statement prepared_statement, idx_t param_idx, int8_t val) {
    return duckdb_bind_int8(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_int16_(duckdb_prepared_statement prepared_statement, idx_t param_idx, int16_t val) {
    return duckdb_bind_int16(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_int32_(duckdb_prepared_statement prepared_statement, idx_t param_idx, int32_t val) {
    return duckdb_bind_int32(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_int64_(duckdb_prepared_statement prepared_statement, idx_t param_idx, int64_t val) {
    return duckdb_bind_int64(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_hugeint_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_hugeint val) {
    return duckdb_bind_hugeint(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_uhugeint_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_uhugeint val) {
    return duckdb_bind_uhugeint(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_decimal_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_decimal val) {
    return duckdb_bind_decimal(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_uint8_(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint8_t val) {
    return duckdb_bind_uint8(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_uint16_(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint16_t val) {
    return duckdb_bind_uint16(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_uint32_(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint32_t val) {
    return duckdb_bind_uint32(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_uint64_(duckdb_prepared_statement prepared_statement, idx_t param_idx, uint64_t val) {
    return duckdb_bind_uint64(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_float_(duckdb_prepared_statement prepared_statement, idx_t param_idx, float val) {
    return duckdb_bind_float(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_double_(duckdb_prepared_statement prepared_statement, idx_t param_idx, double val) {
    return duckdb_bind_double(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_date_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_date val) {
    return duckdb_bind_date(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_time_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_time val) {
    return duckdb_bind_time(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_timestamp_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_timestamp val) {
    return duckdb_bind_timestamp(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_timestamp_tz_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_timestamp val) {
    return duckdb_bind_timestamp_tz(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_interval_(duckdb_prepared_statement prepared_statement, idx_t param_idx, duckdb_interval val) {
    return duckdb_bind_interval(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_varchar_(duckdb_prepared_statement prepared_statement, idx_t param_idx, const char* val) {
    return duckdb_bind_varchar(prepared_statement, param_idx, val);
}

static inline duckdb_state duckdb_bind_varchar_length_(duckdb_prepared_statement prepared_statement, idx_t param_idx, const char* val, idx_t length) {
    return duckdb_bind_varchar_length(prepared_statement, param_idx, val, length);
}

static inline duckdb_state duckdb_bind_blob_(duckdb_prepared_statement prepared_statement, idx_t param_idx, const void* data, idx_t length) {
    return duckdb_bind_blob(prepared_statement, param_idx, data, length);
}

static inline duckdb_state duckdb_bind_null_(duckdb_prepared_statement prepared_statement, idx_t param_idx) {
    return duckdb_bind_null(prepared_statement, param_idx);
}

static inline duckdb_state duckdb_execute_prepared_(duckdb_prepared_statement prepared_statement, duckdb_result* out_result) {
    return duckdb_execute_prepared(prepared_statement, out_result);
}

static inline idx_t duckdb_extract_statements_(duckdb_connection connection, const char* query, duckdb_extracted_statements* out_extracted_statements) {
    return duckdb_extract_statements(connection, query, out_extracted_statements);
}

static inline duckdb_state duckdb_prepare_extracted_statement_(duckdb_connection connection, duckdb_extracted_statements extracted_statements, idx_t index, duckdb_prepared_statement* out_prepared_statement) {
    return duckdb_prepare_extracted_statement(connection, extracted_statements, index, out_prepared_statement);
}

static inline const char* duckdb_extract_statements_error_(duckdb_extracted_statements extracted_statements) {
    return duckdb_extract_statements_error(extracted_statements);
}

static inline void duckdb_destroy_extracted_(duckdb_extracted_statements* extracted_statements) {
    duckdb_destroy_extracted(extracted_statements);
}

static inline duckdb_state duckdb_pending_prepared_(duckdb_prepared_statement prepared_statement, duckdb_pending_result* out_result) {
    return duckdb_pending_prepared(prepared_statement, out_result);
}

static inline void duckdb_destroy_pending_(duckdb_pending_result* pending_result) {
    duckdb_destroy_pending(pending_result);
}

static inline const char* duckdb_pending_error_(duckdb_pending_result pending_result) {
    return duckdb_pending_error(pending_result);
}

static inline duckdb_pending_state duckdb_pending_execute_task_(duckdb_pending_result pending_result) {
    return duckdb_pending_execute_task(pending_result);
}

static inline duckdb_pending_state duckdb_pending_execute_check_state_(duckdb_pending_result pending_result) {
    return duckdb_pending_execute_check_state(pending_result);
}

static inline duckdb_state duckdb_execute_pending_(duckdb_pending_result pending_result, duckdb_result* out_result) {
    return duckdb_execute_pending(pending_result, out_result);
}

static inline bool duckdb_pending_execution_is_finished_(duckdb_pending_state pending_state) {
    return duckdb_pending_execution_is_finished(pending_state);
}

static inline void duckdb_destroy_value_(duckdb_value* value) {
    duckdb_destroy_value(value);
}

static inline duckdb_value duckdb_create_varchar_(const char* text) {
    return duckdb_create_varchar(text);
}

static inline duckdb_value duckdb_create_varchar_length_(const char* text, idx_t length) {
    return duckdb_create_varchar_length(text, length);
}

static inline duckdb_value duckdb_create_bool_(bool input) {
    return duckdb_create_bool(input);
}

static inline duckdb_value duckdb_create_int8_(int8_t input) {
    return duckdb_create_int8(input);
}

static inline duckdb_value duckdb_create_uint8_(uint8_t input) {
    return duckdb_create_uint8(input);
}

static inline duckdb_value duckdb_create_int16_(int16_t input) {
    return duckdb_create_int16(input);
}

static inline duckdb_value duckdb_create_uint16_(uint16_t input) {
    return duckdb_create_uint16(input);
}

static inline duckdb_value duckdb_create_int32_(int32_t input) {
    return duckdb_create_int32(input);
}

static inline duckdb_value duckdb_create_uint32_(uint32_t input) {
    return duckdb_create_uint32(input);
}

static inline duckdb_value duckdb_create_uint64_(uint64_t input) {
    return duckdb_create_uint64(input);
}

static inline duckdb_value duckdb_create_int64_(int64_t val) {
    return duckdb_create_int64(val);
}

static inline duckdb_value duckdb_create_hugeint_(duckdb_hugeint input) {
    return duckdb_create_hugeint(input);
}

static inline duckdb_value duckdb_create_uhugeint_(duckdb_uhugeint input) {
    return duckdb_create_uhugeint(input);
}

static inline duckdb_value duckdb_create_float_(float input) {
    return duckdb_create_float(input);
}

static inline duckdb_value duckdb_create_double_(double input) {
    return duckdb_create_double(input);
}

static inline duckdb_value duckdb_create_date_(duckdb_date input) {
    return duckdb_create_date(input);
}

static inline duckdb_value duckdb_create_time_(duckdb_time input) {
    return duckdb_create_time(input);
}

static inline duckdb_value duckdb_create_time_tz_value_(duckdb_time_tz value) {
    return duckdb_create_time_tz_value(value);
}

static inline duckdb_value duckdb_create_timestamp_(duckdb_timestamp input) {
    return duckdb_create_timestamp(input);
}

static inline duckdb_value duckdb_create_interval_(duckdb_interval input) {
    return duckdb_create_interval(input);
}

static inline duckdb_value duckdb_create_blob_(const uint8_t* data, idx_t length) {
    return duckdb_create_blob(data, length);
}

static inline duckdb_value duckdb_create_bignum_(duckdb_bignum input) {
    return duckdb_create_bignum(input);
}

static inline duckdb_value duckdb_create_decimal_(duckdb_decimal input) {
    return duckdb_create_decimal(input);
}

static inline duckdb_value duckdb_create_bit_(duckdb_bit input) {
    return duckdb_create_bit(input);
}

static inline duckdb_value duckdb_create_uuid_(duckdb_uhugeint input) {
    return duckdb_create_uuid(input);
}

static inline bool duckdb_get_bool_(duckdb_value val) {
    return duckdb_get_bool(val);
}

static inline int8_t duckdb_get_int8_(duckdb_value val) {
    return duckdb_get_int8(val);
}

static inline uint8_t duckdb_get_uint8_(duckdb_value val) {
    return duckdb_get_uint8(val);
}

static inline int16_t duckdb_get_int16_(duckdb_value val) {
    return duckdb_get_int16(val);
}

static inline uint16_t duckdb_get_uint16_(duckdb_value val) {
    return duckdb_get_uint16(val);
}

static inline int32_t duckdb_get_int32_(duckdb_value val) {
    return duckdb_get_int32(val);
}

static inline uint32_t duckdb_get_uint32_(duckdb_value val) {
    return duckdb_get_uint32(val);
}

static inline int64_t duckdb_get_int64_(duckdb_value val) {
    return duckdb_get_int64(val);
}

static inline uint64_t duckdb_get_uint64_(duckdb_value val) {
    return duckdb_get_uint64(val);
}

static inline duckdb_hugeint duckdb_get_hugeint_(duckdb_value val) {
    return duckdb_get_hugeint(val);
}

static inline duckdb_uhugeint duckdb_get_uhugeint_(duckdb_value val) {
    return duckdb_get_uhugeint(val);
}

static inline float duckdb_get_float_(duckdb_value val) {
    return duckdb_get_float(val);
}

static inline double duckdb_get_double_(duckdb_value val) {
    return duckdb_get_double(val);
}

static inline duckdb_date duckdb_get_date_(duckdb_value val) {
    return duckdb_get_date(val);
}

static inline duckdb_time duckdb_get_time_(duckdb_value val) {
    return duckdb_get_time(val);
}

static inline duckdb_time_tz duckdb_get_time_tz_(duckdb_value val) {
    return duckdb_get_time_tz(val);
}

static inline duckdb_timestamp duckdb_get_timestamp_(duckdb_value val) {
    return duckdb_get_timestamp(val);
}

static inline duckdb_interval duckdb_get_interval_(duckdb_value val) {
    return duckdb_get_interval(val);
}

static inline duckdb_logical_type duckdb_get_value_type_(duckdb_value val) {
    return duckdb_get_value_type(val);
}

static inline duckdb_blob duckdb_get_blob_(duckdb_value val) {
    return duckdb_get_blob(val);
}

static inline duckdb_bignum duckdb_get_bignum_(duckdb_value val) {
    return duckdb_get_bignum(val);
}

static inline duckdb_decimal duckdb_get_decimal_(duckdb_value val) {
    return duckdb_get_decimal(val);
}

static inline duckdb_bit duckdb_get_bit_(duckdb_value val) {
    return duckdb_get_bit(val);
}

static inline duckdb_uhugeint duckdb_get_uuid_(duckdb_value val) {
    return duckdb_get_uuid(val);
}

static inline char* duckdb_get_varchar_(duckdb_value value) {
    return duckdb_get_varchar(value);
}

static inline duckdb_value duckdb_create_struct_value_(duckdb_logical_type type, duckdb_value* values) {
    return duckdb_create_struct_value(type, values);
}

static inline duckdb_value duckdb_create_list_value_(duckdb_logical_type type, duckdb_value* values, idx_t value_count) {
    return duckdb_create_list_value(type, values, value_count);
}

static inline duckdb_value duckdb_create_array_value_(duckdb_logical_type type, duckdb_value* values, idx_t value_count) {
    return duckdb_create_array_value(type, values, value_count);
}

static inline idx_t duckdb_get_map_size_(duckdb_value value) {
    return duckdb_get_map_size(value);
}

static inline duckdb_value duckdb_get_map_key_(duckdb_value value, idx_t index) {
    return duckdb_get_map_key(value, index);
}

static inline duckdb_value duckdb_get_map_value_(duckdb_value value, idx_t index) {
    return duckdb_get_map_value(value, index);
}

static inline bool duckdb_is_null_value_(duckdb_value value) {
    return duckdb_is_null_value(value);
}

static inline duckdb_value duckdb_create_null_value_() {
    return duckdb_create_null_value();
}

static inline idx_t duckdb_get_list_size_(duckdb_value value) {
    return duckdb_get_list_size(value);
}

static inline duckdb_value duckdb_get_list_child_(duckdb_value value, idx_t index) {
    return duckdb_get_list_child(value, index);
}

static inline duckdb_value duckdb_create_enum_value_(duckdb_logical_type type, uint64_t value) {
    return duckdb_create_enum_value(type, value);
}

static inline uint64_t duckdb_get_enum_value_(duckdb_value value) {
    return duckdb_get_enum_value(value);
}

static inline duckdb_value duckdb_get_struct_child_(duckdb_value value, idx_t index) {
    return duckdb_get_struct_child(value, index);
}

static inline duckdb_logical_type duckdb_create_logical_type_(duckdb_type type) {
    return duckdb_create_logical_type(type);
}

static inline char* duckdb_logical_type_get_alias_(duckdb_logical_type type) {
    return duckdb_logical_type_get_alias(type);
}

static inline void duckdb_logical_type_set_alias_(duckdb_logical_type type, const char* alias) {
    duckdb_logical_type_set_alias(type, alias);
}

static inline duckdb_logical_type duckdb_create_list_type_(duckdb_logical_type type) {
    return duckdb_create_list_type(type);
}

static inline duckdb_logical_type duckdb_create_array_type_(duckdb_logical_type type, idx_t array_size) {
    return duckdb_create_array_type(type, array_size);
}

static inline duckdb_logical_type duckdb_create_map_type_(duckdb_logical_type key_type, duckdb_logical_type value_type) {
    return duckdb_create_map_type(key_type, value_type);
}

static inline duckdb_logical_type duckdb_create_union_type_(duckdb_logical_type* member_types, const char** member_names, idx_t member_count) {
    return duckdb_create_union_type(member_types, member_names, member_count);
}

static inline duckdb_logical_type duckdb_create_struct_type_(duckdb_logical_type* member_types, const char** member_names, idx_t member_count) {
    return duckdb_create_struct_type(member_types, member_names, member_count);
}

static inline duckdb_logical_type duckdb_create_enum_type_(const char** member_names, idx_t member_count) {
    return duckdb_create_enum_type(member_names, member_count);
}

static inline duckdb_logical_type duckdb_create_decimal_type_(uint8_t width, uint8_t scale) {
    return duckdb_create_decimal_type(width, scale);
}

static inline duckdb_type duckdb_get_type_id_(duckdb_logical_type type) {
    return duckdb_get_type_id(type);
}

static inline uint8_t duckdb_decimal_width_(duckdb_logical_type type) {
    return duckdb_decimal_width(type);
}

static inline uint8_t duckdb_decimal_scale_(duckdb_logical_type type) {
    return duckdb_decimal_scale(type);
}

static inline duckdb_type duckdb_decimal_internal_type_(duckdb_logical_type type) {
    return duckdb_decimal_internal_type(type);
}

static inline duckdb_type duckdb_enum_internal_type_(duckdb_logical_type type) {
    return duckdb_enum_internal_type(type);
}

static inline uint32_t duckdb_enum_dictionary_size_(duckdb_logical_type type) {
    return duckdb_enum_dictionary_size(type);
}

static inline char* duckdb_enum_dictionary_value_(duckdb_logical_type type, idx_t index) {
    return duckdb_enum_dictionary_value(type, index);
}

static inline duckdb_logical_type duckdb_list_type_child_type_(duckdb_logical_type type) {
    return duckdb_list_type_child_type(type);
}

static inline duckdb_logical_type duckdb_array_type_child_type_(duckdb_logical_type type) {
    return duckdb_array_type_child_type(type);
}

static inline idx_t duckdb_array_type_array_size_(duckdb_logical_type type) {
    return duckdb_array_type_array_size(type);
}

static inline duckdb_logical_type duckdb_map_type_key_type_(duckdb_logical_type type) {
    return duckdb_map_type_key_type(type);
}

static inline duckdb_logical_type duckdb_map_type_value_type_(duckdb_logical_type type) {
    return duckdb_map_type_value_type(type);
}

static inline idx_t duckdb_struct_type_child_count_(duckdb_logical_type type) {
    return duckdb_struct_type_child_count(type);
}

static inline char* duckdb_struct_type_child_name_(duckdb_logical_type type, idx_t index) {
    return duckdb_struct_type_child_name(type, index);
}

static inline duckdb_logical_type duckdb_struct_type_child_type_(duckdb_logical_type type, idx_t index) {
    return duckdb_struct_type_child_type(type, index);
}

static inline idx_t duckdb_union_type_member_count_(duckdb_logical_type type) {
    return duckdb_union_type_member_count(type);
}

static inline char* duckdb_union_type_member_name_(duckdb_logical_type type, idx_t index) {
    return duckdb_union_type_member_name(type, index);
}

static inline duckdb_logical_type duckdb_union_type_member_type_(duckdb_logical_type type, idx_t index) {
    return duckdb_union_type_member_type(type, index);
}

static inline void duckdb_destroy_logical_type_(duckdb_logical_type* type) {
    duckdb_destroy_logical_type(type);
}

static inline duckdb_state duckdb_register_logical_type_(duckdb_connection con, duckdb_logical_type type, duckdb_create_type_info info) {
    return duckdb_register_logical_type(con, type, info);
}

static inline duckdb_data_chunk duckdb_create_data_chunk_(duckdb_logical_type* types, idx_t column_count) {
    return duckdb_create_data_chunk(types, column_count);
}

static inline void duckdb_destroy_data_chunk_(duckdb_data_chunk* chunk) {
    duckdb_destroy_data_chunk(chunk);
}

static inline void duckdb_data_chunk_reset_(duckdb_data_chunk chunk) {
    duckdb_data_chunk_reset(chunk);
}

static inline idx_t duckdb_data_chunk_get_column_count_(duckdb_data_chunk chunk) {
    return duckdb_data_chunk_get_column_count(chunk);
}

static inline duckdb_vector duckdb_data_chunk_get_vector_(duckdb_data_chunk chunk, idx_t col_idx) {
    return duckdb_data_chunk_get_vector(chunk, col_idx);
}

static inline idx_t duckdb_data_chunk_get_size_(duckdb_data_chunk chunk) {
    return duckdb_data_chunk_get_size(chunk);
}

static inline void duckdb_data_chunk_set_size_(duckdb_data_chunk chunk, idx_t size) {
    duckdb_data_chunk_set_size(chunk, size);
}

static inline duckdb_logical_type duckdb_vector_get_column_type_(duckdb_vector vector) {
    return duckdb_vector_get_column_type(vector);
}

static inline void* duckdb_vector_get_data_(duckdb_vector vector) {
    return duckdb_vector_get_data(vector);
}

static inline uint64_t* duckdb_vector_get_validity_(duckdb_vector vector) {
    return duckdb_vector_get_validity(vector);
}

static inline void duckdb_vector_ensure_validity_writable_(duckdb_vector vector) {
    duckdb_vector_ensure_validity_writable(vector);
}

static inline void duckdb_vector_assign_string_element_(duckdb_vector vector, idx_t index, const char* str) {
    duckdb_vector_assign_string_element(vector, index, str);
}

static inline void duckdb_vector_assign_string_element_len_(duckdb_vector vector, idx_t index, const char* str, idx_t str_len) {
    duckdb_vector_assign_string_element_len(vector, index, str, str_len);
}

static inline duckdb_vector duckdb_list_vector_get_child_(duckdb_vector vector) {
    return duckdb_list_vector_get_child(vector);
}

static inline idx_t duckdb_list_vector_get_size_(duckdb_vector vector) {
    return duckdb_list_vector_get_size(vector);
}

static inline duckdb_state duckdb_list_vector_set_size_(duckdb_vector vector, idx_t size) {
    return duckdb_list_vector_set_size(vector, size);
}

static inline duckdb_state duckdb_list_vector_reserve_(duckdb_vector vector, idx_t required_capacity) {
    return duckdb_list_vector_reserve(vector, required_capacity);
}

static inline duckdb_vector duckdb_struct_vector_get_child_(duckdb_vector vector, idx_t index) {
    return duckdb_struct_vector_get_child(vector, index);
}

static inline duckdb_vector duckdb_array_vector_get_child_(duckdb_vector vector) {
    return duckdb_array_vector_get_child(vector);
}

static inline bool duckdb_validity_row_is_valid_(uint64_t* validity, idx_t row) {
    return duckdb_validity_row_is_valid(validity, row);
}

static inline void duckdb_validity_set_row_validity_(uint64_t* validity, idx_t row, bool valid) {
    duckdb_validity_set_row_validity(validity, row, valid);
}

static inline void duckdb_validity_set_row_invalid_(uint64_t* validity, idx_t row) {
    duckdb_validity_set_row_invalid(validity, row);
}

static inline void duckdb_validity_set_row_valid_(uint64_t* validity, idx_t row) {
    duckdb_validity_set_row_valid(validity, row);
}

static inline duckdb_scalar_function duckdb_create_scalar_function_() {
    return duckdb_create_scalar_function();
}

static inline void duckdb_destroy_scalar_function_(duckdb_scalar_function* scalar_function) {
    duckdb_destroy_scalar_function(scalar_function);
}

static inline void duckdb_scalar_function_set_name_(duckdb_scalar_function scalar_function, const char* name) {
    duckdb_scalar_function_set_name(scalar_function, name);
}

static inline void duckdb_scalar_function_set_varargs_(duckdb_scalar_function scalar_function, duckdb_logical_type type) {
    duckdb_scalar_function_set_varargs(scalar_function, type);
}

static inline void duckdb_scalar_function_set_special_handling_(duckdb_scalar_function scalar_function) {
    duckdb_scalar_function_set_special_handling(scalar_function);
}

static inline void duckdb_scalar_function_set_volatile_(duckdb_scalar_function scalar_function) {
    duckdb_scalar_function_set_volatile(scalar_function);
}

static inline void duckdb_scalar_function_add_parameter_(duckdb_scalar_function scalar_function, duckdb_logical_type type) {
    duckdb_scalar_function_add_parameter(scalar_function, type);
}

static inline void duckdb_scalar_function_set_return_type_(duckdb_scalar_function scalar_function, duckdb_logical_type type) {
    duckdb_scalar_function_set_return_type(scalar_function, type);
}

static inline void duckdb_scalar_function_set_extra_info_(duckdb_scalar_function scalar_function, void* extra_info, duckdb_delete_callback_t destroy) {
    duckdb_scalar_function_set_extra_info(scalar_function, extra_info, destroy);
}

static inline void duckdb_scalar_function_set_function_(duckdb_scalar_function scalar_function, duckdb_scalar_function_t function) {
    duckdb_scalar_function_set_function(scalar_function, function);
}

static inline duckdb_state duckdb_register_scalar_function_(duckdb_connection con, duckdb_scalar_function scalar_function) {
    return duckdb_register_scalar_function(con, scalar_function);
}

static inline void* duckdb_scalar_function_get_extra_info_(duckdb_function_info info) {
    return duckdb_scalar_function_get_extra_info(info);
}

static inline void duckdb_scalar_function_set_error_(duckdb_function_info info, const char* error) {
    duckdb_scalar_function_set_error(info, error);
}

static inline duckdb_scalar_function_set duckdb_create_scalar_function_set_(const char* name) {
    return duckdb_create_scalar_function_set(name);
}

static inline void duckdb_destroy_scalar_function_set_(duckdb_scalar_function_set* scalar_function_set) {
    duckdb_destroy_scalar_function_set(scalar_function_set);
}

static inline duckdb_state duckdb_add_scalar_function_to_set_(duckdb_scalar_function_set set, duckdb_scalar_function function) {
    return duckdb_add_scalar_function_to_set(set, function);
}

static inline duckdb_state duckdb_register_scalar_function_set_(duckdb_connection con, duckdb_scalar_function_set set) {
    return duckdb_register_scalar_function_set(con, set);
}

static inline duckdb_aggregate_function duckdb_create_aggregate_function_() {
    return duckdb_create_aggregate_function();
}

static inline void duckdb_destroy_aggregate_function_(duckdb_aggregate_function* aggregate_function) {
    duckdb_destroy_aggregate_function(aggregate_function);
}

static inline void duckdb_aggregate_function_set_name_(duckdb_aggregate_function aggregate_function, const char* name) {
    duckdb_aggregate_function_set_name(aggregate_function, name);
}

static inline void duckdb_aggregate_function_add_parameter_(duckdb_aggregate_function aggregate_function, duckdb_logical_type type) {
    duckdb_aggregate_function_add_parameter(aggregate_function, type);
}

static inline void duckdb_aggregate_function_set_return_type_(duckdb_aggregate_function aggregate_function, duckdb_logical_type type) {
    duckdb_aggregate_function_set_return_type(aggregate_function, type);
}

static inline void duckdb_aggregate_function_set_functions_(duckdb_aggregate_function aggregate_function, duckdb_aggregate_state_size state_size, duckdb_aggregate_init_t state_init, duckdb_aggregate_update_t update, duckdb_aggregate_combine_t combine, duckdb_aggregate_finalize_t finalize) {
    duckdb_aggregate_function_set_functions(aggregate_function, state_size, state_init, update, combine, finalize);
}

static inline void duckdb_aggregate_function_set_destructor_(duckdb_aggregate_function aggregate_function, duckdb_aggregate_destroy_t destroy) {
    duckdb_aggregate_function_set_destructor(aggregate_function, destroy);
}

static inline duckdb_state duckdb_register_aggregate_function_(duckdb_connection con, duckdb_aggregate_function aggregate_function) {
    return duckdb_register_aggregate_function(con, aggregate_function);
}

static inline void duckdb_aggregate_function_set_special_handling_(duckdb_aggregate_function aggregate_function) {
    duckdb_aggregate_function_set_special_handling(aggregate_function);
}

static inline void duckdb_aggregate_function_set_extra_info_(duckdb_aggregate_function aggregate_function, void* extra_info, duckdb_delete_callback_t destroy) {
    duckdb_aggregate_function_set_extra_info(aggregate_function, extra_info, destroy);
}

static inline void* duckdb_aggregate_function_get_extra_info_(duckdb_function_info info) {
    return duckdb_aggregate_function_get_extra_info(info);
}

static inline void duckdb_aggregate_function_set_error_(duckdb_function_info info, const char* error) {
    duckdb_aggregate_function_set_error(info, error);
}

static inline duckdb_aggregate_function_set duckdb_create_aggregate_function_set_(const char* name) {
    return duckdb_create_aggregate_function_set(name);
}

static inline void duckdb_destroy_aggregate_function_set_(duckdb_aggregate_function_set* aggregate_function_set) {
    duckdb_destroy_aggregate_function_set(aggregate_function_set);
}

static inline duckdb_state duckdb_add_aggregate_function_to_set_(duckdb_aggregate_function_set set, duckdb_aggregate_function function) {
    return duckdb_add_aggregate_function_to_set(set, function);
}

static inline duckdb_state duckdb_register_aggregate_function_set_(duckdb_connection con, duckdb_aggregate_function_set set) {
    return duckdb_register_aggregate_function_set(con, set);
}

static inline duckdb_table_function duckdb_create_table_function_() {
    return duckdb_create_table_function();
}

static inline void duckdb_destroy_table_function_(duckdb_table_function* table_function) {
    duckdb_destroy_table_function(table_function);
}

static inline void duckdb_table_function_set_name_(duckdb_table_function table_function, const char* name) {
    duckdb_table_function_set_name(table_function, name);
}

static inline void duckdb_table_function_add_parameter_(duckdb_table_function table_function, duckdb_logical_type type) {
    duckdb_table_function_add_parameter(table_function, type);
}

static inline void duckdb_table_function_add_named_parameter_(duckdb_table_function table_function, const char* name, duckdb_logical_type type) {
    duckdb_table_function_add_named_parameter(table_function, name, type);
}

static inline void duckdb_table_function_set_extra_info_(duckdb_table_function table_function, void* extra_info, duckdb_delete_callback_t destroy) {
    duckdb_table_function_set_extra_info(table_function, extra_info, destroy);
}

static inline void duckdb_table_function_set_bind_(duckdb_table_function table_function, duckdb_table_function_bind_t bind) {
    duckdb_table_function_set_bind(table_function, bind);
}

static inline void duckdb_table_function_set_init_(duckdb_table_function table_function, duckdb_table_function_init_t init) {
    duckdb_table_function_set_init(table_function, init);
}

static inline void duckdb_table_function_set_local_init_(duckdb_table_function table_function, duckdb_table_function_init_t init) {
    duckdb_table_function_set_local_init(table_function, init);
}

static inline void duckdb_table_function_set_function_(duckdb_table_function table_function, duckdb_table_function_t function) {
    duckdb_table_function_set_function(table_function, function);
}

static inline void duckdb_table_function_supports_projection_pushdown_(duckdb_table_function table_function, bool pushdown) {
    duckdb_table_function_supports_projection_pushdown(table_function, pushdown);
}

static inline duckdb_state duckdb_register_table_function_(duckdb_connection con, duckdb_table_function function) {
    return duckdb_register_table_function(con, function);
}

static inline void* duckdb_bind_get_extra_info_(duckdb_bind_info info) {
    return duckdb_bind_get_extra_info(info);
}

static inline void duckdb_bind_add_result_column_(duckdb_bind_info info, const char* name, duckdb_logical_type type) {
    duckdb_bind_add_result_column(info, name, type);
}

static inline idx_t duckdb_bind_get_parameter_count_(duckdb_bind_info info) {
    return duckdb_bind_get_parameter_count(info);
}

static inline duckdb_value duckdb_bind_get_parameter_(duckdb_bind_info info, idx_t index) {
    return duckdb_bind_get_parameter(info, index);
}

static inline duckdb_value duckdb_bind_get_named_parameter_(duckdb_bind_info info, const char* name) {
    return duckdb_bind_get_named_parameter(info, name);
}

static inline void duckdb_bind_set_bind_data_(duckdb_bind_info info, void* bind_data, duckdb_delete_callback_t destroy) {
    duckdb_bind_set_bind_data(info, bind_data, destroy);
}

static inline void duckdb_bind_set_cardinality_(duckdb_bind_info info, idx_t cardinality, bool is_exact) {
    duckdb_bind_set_cardinality(info, cardinality, is_exact);
}

static inline void duckdb_bind_set_error_(duckdb_bind_info info, const char* error) {
    duckdb_bind_set_error(info, error);
}

static inline void* duckdb_init_get_extra_info_(duckdb_init_info info) {
    return duckdb_init_get_extra_info(info);
}

static inline void* duckdb_init_get_bind_data_(duckdb_init_info info) {
    return duckdb_init_get_bind_data(info);
}

static inline void duckdb_init_set_init_data_(duckdb_init_info info, void* init_data, duckdb_delete_callback_t destroy) {
    duckdb_init_set_init_data(info, init_data, destroy);
}

static inline idx_t duckdb_init_get_column_count_(duckdb_init_info info) {
    return duckdb_init_get_column_count(info);
}

static inline idx_t duckdb_init_get_column_index_(duckdb_init_info info, idx_t column_index) {
    return duckdb_init_get_column_index(info, column_index);
}

static inline void duckdb_init_set_max_threads_(duckdb_init_info info, idx_t max_threads) {
    duckdb_init_set_max_threads(info, max_threads);
}

static inline void duckdb_init_set_error_(duckdb_init_info info, const char* error) {
    duckdb_init_set_error(info, error);
}

static inline void* duckdb_function_get_extra_info_(duckdb_function_info info) {
    return duckdb_function_get_extra_info(info);
}

static inline void* duckdb_function_get_bind_data_(duckdb_function_info info) {
    return duckdb_function_get_bind_data(info);
}

static inline void* duckdb_function_get_init_data_(duckdb_function_info info) {
    return duckdb_function_get_init_data(info);
}

static inline void* duckdb_function_get_local_init_data_(duckdb_function_info info) {
    return duckdb_function_get_local_init_data(info);
}

static inline void duckdb_function_set_error_(duckdb_function_info info, const char* error) {
    duckdb_function_set_error(info, error);
}

static inline void duckdb_add_replacement_scan_(duckdb_database db, duckdb_replacement_callback_t replacement, void* extra_data, duckdb_delete_callback_t delete_callback) {
    duckdb_add_replacement_scan(db, replacement, extra_data, delete_callback);
}

static inline void duckdb_replacement_scan_set_function_name_(duckdb_replacement_scan_info info, const char* function_name) {
    duckdb_replacement_scan_set_function_name(info, function_name);
}

static inline void duckdb_replacement_scan_add_parameter_(duckdb_replacement_scan_info info, duckdb_value parameter) {
    duckdb_replacement_scan_add_parameter(info, parameter);
}

static inline void duckdb_replacement_scan_set_error_(duckdb_replacement_scan_info info, const char* error) {
    duckdb_replacement_scan_set_error(info, error);
}

static inline duckdb_value duckdb_profiling_info_get_metrics_(duckdb_profiling_info info) {
    return duckdb_profiling_info_get_metrics(info);
}

static inline idx_t duckdb_profiling_info_get_child_count_(duckdb_profiling_info info) {
    return duckdb_profiling_info_get_child_count(info);
}

static inline duckdb_profiling_info duckdb_profiling_info_get_child_(duckdb_profiling_info info, idx_t index) {
    return duckdb_profiling_info_get_child(info, index);
}

static inline duckdb_state duckdb_appender_create_(duckdb_connection connection, const char* schema, const char* table, duckdb_appender* out_appender) {
    return duckdb_appender_create(connection, schema, table, out_appender);
}

static inline duckdb_state duckdb_appender_create_ext_(duckdb_connection connection, const char* catalog, const char* schema, const char* table, duckdb_appender* out_appender) {
    return duckdb_appender_create_ext(connection, catalog, schema, table, out_appender);
}

static inline idx_t duckdb_appender_column_count_(duckdb_appender appender) {
    return duckdb_appender_column_count(appender);
}

static inline duckdb_logical_type duckdb_appender_column_type_(duckdb_appender appender, idx_t col_idx) {
    return duckdb_appender_column_type(appender, col_idx);
}

static inline const char* duckdb_appender_error_(duckdb_appender appender) {
    return duckdb_appender_error(appender);
}

static inline duckdb_state duckdb_appender_flush_(duckdb_appender appender) {
    return duckdb_appender_flush(appender);
}

static inline duckdb_state duckdb_appender_close_(duckdb_appender appender) {
    return duckdb_appender_close(appender);
}

static inline duckdb_state duckdb_appender_destroy_(duckdb_appender* appender) {
    return duckdb_appender_destroy(appender);
}

static inline duckdb_state duckdb_appender_add_column_(duckdb_appender appender, const char* name) {
    return duckdb_appender_add_column(appender, name);
}

static inline duckdb_state duckdb_appender_clear_columns_(duckdb_appender appender) {
    return duckdb_appender_clear_columns(appender);
}

static inline duckdb_state duckdb_append_data_chunk_(duckdb_appender appender, duckdb_data_chunk chunk) {
    return duckdb_append_data_chunk(appender, chunk);
}

static inline duckdb_state duckdb_table_description_create_(duckdb_connection connection, const char* schema, const char* table, duckdb_table_description* out) {
    return duckdb_table_description_create(connection, schema, table, out);
}

static inline duckdb_state duckdb_table_description_create_ext_(duckdb_connection connection, const char* catalog, const char* schema, const char* table, duckdb_table_description* out) {
    return duckdb_table_description_create_ext(connection, catalog, schema, table, out);
}

static inline void duckdb_table_description_destroy_(duckdb_table_description* table_description) {
    duckdb_table_description_destroy(table_description);
}

static inline const char* duckdb_table_description_error_(duckdb_table_description table_description) {
    return duckdb_table_description_error(table_description);
}

static inline duckdb_state duckdb_column_has_default_(duckdb_table_description table_description, idx_t index, bool* out) {
    return duckdb_column_has_default(table_description, index, out);
}

static inline char* duckdb_table_description_get_column_name_(duckdb_table_description table_description, idx_t index) {
    return duckdb_table_description_get_column_name(table_description, index);
}

static inline void duckdb_execute_tasks_(duckdb_database database, idx_t max_tasks) {
    duckdb_execute_tasks(database, max_tasks);
}

static inline duckdb_task_state duckdb_create_task_state_(duckdb_database database) {
    return duckdb_create_task_state(database);
}

static inline void duckdb_execute_tasks_state_(duckdb_task_state state) {
    duckdb_execute_tasks_state(state);
}

static inline idx_t duckdb_execute_n_tasks_state_(duckdb_task_state state, idx_t max_tasks) {
    return duckdb_execute_n_tasks_state(state, max_tasks);
}

static inline void duckdb_finish_execution_(duckdb_task_state state) {
    duckdb_finish_execution(state);
}

static inline bool duckdb_task_state_is_finished_(duckdb_task_state state) {
    return duckdb_task_state_is_finished(state);
}

static inline void duckdb_destroy_task_state_(duckdb_task_state state) {
    duckdb_destroy_task_state(state);
}

static inline bool duckdb_execution_is_finished_(duckdb_connection con) {
    return duckdb_execution_is_finished(con);
}

static inline duckdb_data_chunk duckdb_fetch_chunk_(duckdb_result result) {
    return duckdb_fetch_chunk(result);
}

static inline duckdb_cast_function duckdb_create_cast_function_() {
    return duckdb_create_cast_function();
}

static inline void duckdb_cast_function_set_source_type_(duckdb_cast_function cast_function, duckdb_logical_type source_type) {
    duckdb_cast_function_set_source_type(cast_function, source_type);
}

static inline void duckdb_cast_function_set_target_type_(duckdb_cast_function cast_function, duckdb_logical_type target_type) {
    duckdb_cast_function_set_target_type(cast_function, target_type);
}

static inline void duckdb_cast_function_set_implicit_cast_cost_(duckdb_cast_function cast_function, int64_t cost) {
    duckdb_cast_function_set_implicit_cast_cost(cast_function, cost);
}

static inline void duckdb_cast_function_set_function_(duckdb_cast_function cast_function, duckdb_cast_function_t function) {
    duckdb_cast_function_set_function(cast_function, function);
}

static inline void duckdb_cast_function_set_extra_info_(duckdb_cast_function cast_function, void* extra_info, duckdb_delete_callback_t destroy) {
    duckdb_cast_function_set_extra_info(cast_function, extra_info, destroy);
}

static inline void* duckdb_cast_function_get_extra_info_(duckdb_function_info info) {
    return duckdb_cast_function_get_extra_info(info);
}

static inline duckdb_cast_mode duckdb_cast_function_get_cast_mode_(duckdb_function_info info) {
    return duckdb_cast_function_get_cast_mode(info);
}

static inline void duckdb_cast_function_set_error_(duckdb_function_info info, const char* error) {
    duckdb_cast_function_set_error(info, error);
}

static inline void duckdb_cast_function_set_row_error_(duckdb_function_info info, const char* error, idx_t row, duckdb_vector output) {
    duckdb_cast_function_set_row_error(info, error, row, output);
}

static inline duckdb_state duckdb_register_cast_function_(duckdb_connection con, duckdb_cast_function cast_function) {
    return duckdb_register_cast_function(con, cast_function);
}

static inline void duckdb_destroy_cast_function_(duckdb_cast_function* cast_function) {
    duckdb_destroy_cast_function(cast_function);
}

static inline bool duckdb_is_finite_timestamp_s_(duckdb_timestamp_s ts) {
    return duckdb_is_finite_timestamp_s(ts);
}

static inline bool duckdb_is_finite_timestamp_ms_(duckdb_timestamp_ms ts) {
    return duckdb_is_finite_timestamp_ms(ts);
}

static inline bool duckdb_is_finite_timestamp_ns_(duckdb_timestamp_ns ts) {
    return duckdb_is_finite_timestamp_ns(ts);
}

static inline duckdb_value duckdb_create_timestamp_tz_(duckdb_timestamp input) {
    return duckdb_create_timestamp_tz(input);
}

static inline duckdb_value duckdb_create_timestamp_s_(duckdb_timestamp_s input) {
    return duckdb_create_timestamp_s(input);
}

static inline duckdb_value duckdb_create_timestamp_ms_(duckdb_timestamp_ms input) {
    return duckdb_create_timestamp_ms(input);
}

static inline duckdb_value duckdb_create_timestamp_ns_(duckdb_timestamp_ns input) {
    return duckdb_create_timestamp_ns(input);
}

static inline duckdb_timestamp duckdb_get_timestamp_tz_(duckdb_value val) {
    return duckdb_get_timestamp_tz(val);
}

static inline duckdb_timestamp_s duckdb_get_timestamp_s_(duckdb_value val) {
    return duckdb_get_timestamp_s(val);
}

static inline duckdb_timestamp_ms duckdb_get_timestamp_ms_(duckdb_value val) {
    return duckdb_get_timestamp_ms(val);
}

static inline duckdb_timestamp_ns duckdb_get_timestamp_ns_(duckdb_value val) {
    return duckdb_get_timestamp_ns(val);
}

static inline duckdb_state duckdb_append_value_(duckdb_appender appender, duckdb_value value) {
    return duckdb_append_value(appender, value);
}

static inline duckdb_profiling_info duckdb_get_profiling_info_(duckdb_connection connection) {
    return duckdb_get_profiling_info(connection);
}

static inline duckdb_value duckdb_profiling_info_get_value_(duckdb_profiling_info info, const char* key) {
    return duckdb_profiling_info_get_value(info, key);
}

static inline duckdb_state duckdb_appender_begin_row_(duckdb_appender appender) {
    return duckdb_appender_begin_row(appender);
}

static inline duckdb_state duckdb_appender_end_row_(duckdb_appender appender) {
    return duckdb_appender_end_row(appender);
}

static inline duckdb_state duckdb_append_default_(duckdb_appender appender) {
    return duckdb_append_default(appender);
}

static inline duckdb_state duckdb_append_bool_(duckdb_appender appender, bool value) {
    return duckdb_append_bool(appender, value);
}

static inline duckdb_state duckdb_append_int8_(duckdb_appender appender, int8_t value) {
    return duckdb_append_int8(appender, value);
}

static inline duckdb_state duckdb_append_int16_(duckdb_appender appender, int16_t value) {
    return duckdb_append_int16(appender, value);
}

static inline duckdb_state duckdb_append_int32_(duckdb_appender appender, int32_t value) {
    return duckdb_append_int32(appender, value);
}

static inline duckdb_state duckdb_append_int64_(duckdb_appender appender, int64_t value) {
    return duckdb_append_int64(appender, value);
}

static inline duckdb_state duckdb_append_hugeint_(duckdb_appender appender, duckdb_hugeint value) {
    return duckdb_append_hugeint(appender, value);
}

static inline duckdb_state duckdb_append_uint8_(duckdb_appender appender, uint8_t value) {
    return duckdb_append_uint8(appender, value);
}

static inline duckdb_state duckdb_append_uint16_(duckdb_appender appender, uint16_t value) {
    return duckdb_append_uint16(appender, value);
}

static inline duckdb_state duckdb_append_uint32_(duckdb_appender appender, uint32_t value) {
    return duckdb_append_uint32(appender, value);
}

static inline duckdb_state duckdb_append_uint64_(duckdb_appender appender, uint64_t value) {
    return duckdb_append_uint64(appender, value);
}

static inline duckdb_state duckdb_append_uhugeint_(duckdb_appender appender, duckdb_uhugeint value) {
    return duckdb_append_uhugeint(appender, value);
}

static inline duckdb_state duckdb_append_float_(duckdb_appender appender, float value) {
    return duckdb_append_float(appender, value);
}

static inline duckdb_state duckdb_append_double_(duckdb_appender appender, double value) {
    return duckdb_append_double(appender, value);
}

static inline duckdb_state duckdb_append_date_(duckdb_appender appender, duckdb_date value) {
    return duckdb_append_date(appender, value);
}

static inline duckdb_state duckdb_append_time_(duckdb_appender appender, duckdb_time value) {
    return duckdb_append_time(appender, value);
}

static inline duckdb_state duckdb_append_timestamp_(duckdb_appender appender, duckdb_timestamp value) {
    return duckdb_append_timestamp(appender, value);
}

static inline duckdb_state duckdb_append_interval_(duckdb_appender appender, duckdb_interval value) {
    return duckdb_append_interval(appender, value);
}

static inline duckdb_state duckdb_append_varchar_(duckdb_appender appender, const char* val) {
    return duckdb_append_varchar(appender, val);
}

static inline duckdb_state duckdb_append_varchar_length_(duckdb_appender appender, const char* val, idx_t length) {
    return duckdb_append_varchar_length(appender, val, length);
}

static inline duckdb_state duckdb_append_blob_(duckdb_appender appender, const void* data, idx_t length) {
    return duckdb_append_blob(appender, data, length);
}

static inline duckdb_state duckdb_append_null_(duckdb_appender appender) {
    return duckdb_append_null(appender);
}

// skipped deprecated: duckdb_row_count
// skipped deprecated: duckdb_column_data
// skipped deprecated: duckdb_nullmask_data
// skipped deprecated: duckdb_result_get_chunk
// skipped deprecated: duckdb_result_is_streaming
// skipped deprecated: duckdb_result_chunk_count
// skipped deprecated: duckdb_value_boolean
// skipped deprecated: duckdb_value_int8
// skipped deprecated: duckdb_value_int16
// skipped deprecated: duckdb_value_int32
// skipped deprecated: duckdb_value_int64
// skipped deprecated: duckdb_value_hugeint
// skipped deprecated: duckdb_value_uhugeint
// skipped deprecated: duckdb_value_decimal
// skipped deprecated: duckdb_value_uint8
// skipped deprecated: duckdb_value_uint16
// skipped deprecated: duckdb_value_uint32
// skipped deprecated: duckdb_value_uint64
// skipped deprecated: duckdb_value_float
// skipped deprecated: duckdb_value_double
// skipped deprecated: duckdb_value_date
// skipped deprecated: duckdb_value_time
// skipped deprecated: duckdb_value_timestamp
// skipped deprecated: duckdb_value_interval
// skipped deprecated: duckdb_value_varchar
// skipped deprecated: duckdb_value_string
// skipped deprecated: duckdb_value_varchar_internal
// skipped deprecated: duckdb_value_string_internal
// skipped deprecated: duckdb_value_blob
// skipped deprecated: duckdb_value_is_null
// skipped deprecated: duckdb_execute_prepared_streaming
// skipped deprecated: duckdb_pending_prepared_streaming
// skipped deprecated: duckdb_query_arrow
// skipped deprecated: duckdb_query_arrow_schema
// skipped deprecated: duckdb_prepared_arrow_schema
// skipped deprecated: duckdb_result_arrow_array
// skipped deprecated: duckdb_query_arrow_array
// skipped deprecated: duckdb_arrow_column_count
// skipped deprecated: duckdb_arrow_row_count
// skipped deprecated: duckdb_arrow_rows_changed
// skipped deprecated: duckdb_query_arrow_error
// skipped deprecated: duckdb_destroy_arrow
// skipped deprecated: duckdb_destroy_arrow_stream
// skipped deprecated: duckdb_execute_prepared_arrow
// skipped deprecated: duckdb_arrow_scan
// skipped deprecated: duckdb_arrow_array_scan
// skipped deprecated: duckdb_stream_fetch_chunk
// skipped unstable: duckdb_create_instance_cache
// skipped unstable: duckdb_get_or_create_from_cache
// skipped unstable: duckdb_destroy_instance_cache
// skipped unstable: duckdb_append_default_to_chunk
// skipped unstable: duckdb_appender_error_data
// skipped unstable: duckdb_appender_create_query
// skipped unstable: duckdb_to_arrow_schema
// skipped unstable: duckdb_data_chunk_to_arrow
// skipped unstable: duckdb_schema_from_arrow
// skipped unstable: duckdb_data_chunk_from_arrow
// skipped unstable: duckdb_destroy_arrow_converted_schema
// skipped unstable: duckdb_create_error_data
// skipped unstable: duckdb_destroy_error_data
// skipped unstable: duckdb_error_data_error_type
// skipped unstable: duckdb_error_data_message
// skipped unstable: duckdb_error_data_has_error
// skipped unstable: duckdb_destroy_expression
// skipped unstable: duckdb_expression_return_type
// skipped unstable: duckdb_expression_is_foldable
// skipped unstable: duckdb_expression_fold
// skipped unstable: duckdb_client_context_get_connection_id
// skipped unstable: duckdb_destroy_client_context
// skipped unstable: duckdb_connection_get_client_context
// skipped unstable: duckdb_get_table_names
// skipped unstable: duckdb_connection_get_arrow_options
// skipped unstable: duckdb_destroy_arrow_options
// skipped unstable: duckdb_prepared_statement_column_count
// skipped unstable: duckdb_prepared_statement_column_name
// skipped unstable: duckdb_prepared_statement_column_logical_type
// skipped unstable: duckdb_prepared_statement_column_type
// skipped unstable: duckdb_result_get_arrow_options
// skipped unstable: duckdb_scalar_function_set_bind
// skipped unstable: duckdb_scalar_function_bind_set_error
// skipped unstable: duckdb_scalar_function_get_client_context
// skipped unstable: duckdb_scalar_function_set_bind_data
// skipped unstable: duckdb_scalar_function_get_bind_data
// skipped unstable: duckdb_scalar_function_bind_get_extra_info
// skipped unstable: duckdb_scalar_function_bind_get_argument_count
// skipped unstable: duckdb_scalar_function_bind_get_argument
// skipped unstable: duckdb_scalar_function_set_bind_data_copy
// skipped unstable: duckdb_value_to_string
// skipped unstable: duckdb_table_function_get_client_context
// skipped unstable: duckdb_create_map_value
// skipped unstable: duckdb_create_union_value
// skipped unstable: duckdb_create_time_ns
// skipped unstable: duckdb_get_time_ns
// skipped unstable: duckdb_create_vector
// skipped unstable: duckdb_destroy_vector
// skipped unstable: duckdb_slice_vector
// skipped unstable: duckdb_vector_reference_value
// skipped unstable: duckdb_vector_reference_vector
// skipped unstable: duckdb_create_selection_vector
// skipped unstable: duckdb_destroy_selection_vector
// skipped unstable: duckdb_selection_vector_get_data_ptr
// skipped unstable: duckdb_vector_copy_sel
