#ifndef LunsjRegistreringIotStatus_h
#define LunsjRegistreringIotStatus_h

#include <Arduino.h>
#include <ArduinoJson.h>

class LunsjRegistreringIotStatus
{

private:
    DynamicJsonDocument *jsonStatus;

public:
    LunsjRegistreringIotStatus();
    boolean isHealthy();
};

#endif
