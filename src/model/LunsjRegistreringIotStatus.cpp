#include <model/LunsjRegistreringIotStatus.h>

LunsjRegistreringIotStatus::LunsjRegistreringIotStatus()
{
    jsonStatus = new DynamicJsonDocument(1024);
}

boolean LunsjRegistreringIotStatus::isHealthy()
{
    return true;
}
