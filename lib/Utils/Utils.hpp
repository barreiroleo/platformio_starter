#pragma once

#include <Arduino.h>

namespace core::str {

enum class ERR_CODE : uint8_t {
    OK = 0,
    ENCODE_ERROR,
    TRUNC_WARN,
};

/// @brief Print buffer to Serial, optionally print error code
/// @param buffer Buffer to print
/// @param code Error code, default is OK
inline void print_buffer(const char* buffer, ERR_CODE code = ERR_CODE::OK)
{
    if (ERR_CODE::OK != code) {
        Serial.print(F("Error code: ")), Serial.println(static_cast<char>(code));
    }
    Serial.println(buffer);
}

[[nodiscard]]
/// @brief Handle snprintf return value
/// @param str_length Return value from snprintf
/// @param buffer_size Size of the buffer passed to snprintf
/// @return Error code
constexpr auto handle_snprintf(int16_t str_length, size_t buffer_size) -> ERR_CODE
{
    if (str_length < 0) {
        return ERR_CODE::ENCODE_ERROR;
    }
    if (str_length >= static_cast<decltype(str_length)>(buffer_size)) {
        return ERR_CODE::TRUNC_WARN;
    }
    return ERR_CODE::OK;
}

}
