#include "Demos.hpp"

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    char buffer[64] {};

    // Potentiometer demo
    {
        static constexpr Potentiometer::Potentiometer pot(A0);
        Demos::adc_raw(pot, buffer, sizeof(buffer));
        Demos::adc_mv(pot, buffer, sizeof(buffer));
    }

    // Counter demo
    {
        Demos::counter(buffer, sizeof(buffer));
    }

    delay(1000);
}
