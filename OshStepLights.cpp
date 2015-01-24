#include "Arduino.h"
#include "OshStepLights.h"

OshStepLights::OshStepLights() {
    pinMode(seq_latch, OUTPUT);
    pinMode(seq_clock, OUTPUT);
    pinMode(seq_data,  OUTPUT);
    pinMode(func_latch, OUTPUT);
    pinMode(func_clock, OUTPUT);
    pinMode(func_data,  OUTPUT);

    step_red   = 0xFFFF;
    step_green = 0xFFFF;
    func_red   = 0xFF;
    func_green = 0xFF;

    update();
}

OshStepLights::~OshStepLights() {

}

void OshStepLights::update() {
    uint8_t first_red   = step_red & 0xFF;
    uint8_t last_red    = (step_red >> 8) & 0xFF;
    uint8_t first_green = step_green & 0xFF;
    uint8_t last_green  = (step_green >> 8) & 0xFF;

    digitalWrite(seq_latch, LOW);
    shiftOut(seq_data, seq_clock, MSBFIRST, last_red);
    shiftOut(seq_data, seq_clock, MSBFIRST, first_red);
    shiftOut(seq_data, seq_clock, MSBFIRST, last_green);
    shiftOut(seq_data, seq_clock, MSBFIRST, first_green);
    digitalWrite(seq_latch, HIGH);

    digitalWrite(func_latch, LOW);
    shiftOut(func_data, func_clock, MSBFIRST, func_red);
    shiftOut(func_data, func_clock, MSBFIRST, func_green);
    digitalWrite(func_latch, HIGH);
}

void OshStepLights::setStepRed( uint8_t step, uint8_t value) {
    if (value)
        step_red &= ~(0x1 << step);
    else
        step_red |= 0x1 << step;
    update();
}

void OshStepLights::clearStepRed() {
    step_red = 0xFFFF;
}

void OshStepLights::setStepGreen( uint8_t step, uint8_t value) {
    if (value)
        step_green &= ~(0x1 << step);
    else
        step_green |= 0x1 << step;
    update();
}

void OshStepLights::clearStepGreen() {
    step_green = 0xFFFF;
}

void OshStepLights::setFunctionRed( uint8_t func, uint8_t value) {
    if (value) {
        func_red &= ~(0x1 << func);
    } else {
        func_red |= 0x1 << func;
    }
    update();
}

void OshStepLights::clearFunctionRed() {
    func_red = 0xFF;
}

void OshStepLights::setFunctionGreen( uint8_t func, uint8_t value) {
    if (value) {
        func_green &= ~(0x1 << func);
    } else {
        func_green |= 0x1 << func;
    }
    update();
}

void OshStepLights::clearFunctionGreen() {
    func_green = 0xFF;
}