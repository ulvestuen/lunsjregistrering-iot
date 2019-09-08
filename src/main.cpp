#include <Arduino.h>
#include <service/WifiConnectionService.h>
#include <api/LunsjRegistreringIotApi.h>
#include <model/LunsjRegistreringIotStatus.h>
#include <service/LunsjRegistreringIotService.h>

const std::vector<uint8_t> PUMP_PIN_LIST = {D8};

WifiConnectionService *wifiConnectionService;
LunsjRegistreringIotStatus *systemStatus;
LunsjRegistreringIotService *lunsjRegistreringIotService;
LunsjRegistreringIotApi *lunsjRegistreringIotApi;

void setup(void)
{
  // Connect to WiFi with details given in "secrets.h"
  wifiConnectionService = new WifiConnectionService();
  wifiConnectionService->connect();

  systemStatus = new LunsjRegistreringIotStatus();
  lunsjRegistreringIotService = new LunsjRegistreringIotService(systemStatus);

  // Setup API
  lunsjRegistreringIotApi = new LunsjRegistreringIotApi(systemStatus,
                                                        lunsjRegistreringIotService);
  lunsjRegistreringIotApi->setup();
}

void loop(void)
{
  lunsjRegistreringIotApi->handleClient();
  lunsjRegistreringIotService->handleLunsjRegistrering();
}
