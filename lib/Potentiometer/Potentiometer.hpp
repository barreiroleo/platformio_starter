#pragma once

#include <Utils.hpp>

namespace Potentiometer {

using ADC_RAW = uint16_t;
using ADC_mV = uint16_t;
using ADC_pin = uint8_t;

[[nodiscard]]
/// @brief Read voltage in millivolts from potentiometer
/// @return Voltage in millivolts
constexpr auto raw_to_mV(ADC_RAW raw) -> ADC_mV
{
    constexpr ADC_RAW in_min = 0, in_max = 1023;
    constexpr ADC_mV out_min = 0, out_max = 5;
    return (raw - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

[[nodiscard]]
/// @brief Convert value to string
/// @return Error code
constexpr auto to_string(uint16_t raw, uint8_t id, char* buffer, size_t size) -> core::str::ERR_CODE
{
    const auto length = snprintf(buffer, size, "Pot_%d:%u", id, raw);
    return core::str::handle_snprintf(length, size);
}

class Potentiometer {
public:
    constexpr Potentiometer(uint8_t pin)
        : m_pin(pin)
    {
    }

    [[nodiscard]]
    /// @brief Read raw ADC value from potentiometer
    /// @return Raw ADC value
    auto read_raw() const -> ADC_RAW
    {
        return analogRead(m_pin);
    }

    [[nodiscard]]
    /// @brief Get the pin number
    /// @return Pin number - Internal representation
    constexpr auto get_pin() const -> ADC_pin
    {
        return m_pin;
    }

private:
    const uint8_t m_pin { A0 };
};

}
