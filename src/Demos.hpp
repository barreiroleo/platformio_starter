#pragma once

#include <Potentiometer.hpp>
#include <Utils.hpp>

namespace Demos {

inline void adc_raw(const Potentiometer::Potentiometer& pot, char* buffer, size_t size)
{
    const auto raw = pot.read_raw();
    const auto id = pot.get_pin();
    print_buffer(buffer, Potentiometer::to_string(raw, id, buffer, size));
}

inline void adc_mv(const Potentiometer::Potentiometer& pot, char* buffer, size_t size)
{
    const auto mV = Potentiometer::raw_to_mV(pot.read_raw());
    const auto id = pot.get_pin();
    print_buffer(buffer, Potentiometer::to_string(mV, id, buffer, size));
}

inline void counter(char* buffer, size_t size)
{
    static uint8_t counter {};
    const size_t len = snprintf(buffer, size, "Counter:%u", counter++);
    print_buffer(buffer, core::str::handle_snprintf(len, size));
}

}
