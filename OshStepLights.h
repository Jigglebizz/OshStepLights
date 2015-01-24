#ifndef OshStepLights_h
#define OshStepLights_h

#include "Arduino.h"

#define LIGHTS_PLAY   0
#define LIGHTS_RECORD 1
#define LIGHTS_SHIFT  2
#define LIGHTS_YES    3
#define LIGHTS_UP     4
#define LIGHTS_DOWN   5
#define LIGHTS_LEFT   6
#define LIGHTS_RIGHT  7

class OshStepLights {
  private:
    static const int seq_latch = 5;
    static const int seq_clock = 6;
    static const int seq_data  = 7;
    static const int func_latch = 8;
    static const int func_clock = 9;
    static const int func_data  = 10;

    uint16_t step_red, step_green;
    uint8_t  func_red, func_green;
  public:
    OshStepLights();
    ~OshStepLights();

    void update();

    void setStepRed( uint8_t, uint8_t);
    void clearStepRed();
    void setStepGreen( uint8_t, uint8_t);
    void clearStepGreen();
    void setFunctionRed( uint8_t, uint8_t);
    void clearFunctionRed();
    void setFunctionGreen( uint8_t, uint8_t);
    void clearFunctionGreen();
};

#endif