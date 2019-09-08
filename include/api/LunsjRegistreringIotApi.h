#ifndef LunsjRegistreringIotApi_h
#define LunsjRegistreringIotApi_h

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <model/LunsjRegistreringIotStatus.h>
#include <service/LunsjRegistreringIotService.h>

class LunsjRegistreringIotApi
{

private:
  ESP8266WebServer *server;
  ESP8266HTTPUpdateServer *httpUpdater;
  LunsjRegistreringIotStatus *systemStatus;
  LunsjRegistreringIotService *systemService;
  std::vector<int> toVector(String stringWithDelimiter, std::string delimiter);

public:
  LunsjRegistreringIotApi();
  LunsjRegistreringIotApi(LunsjRegistreringIotStatus *status, LunsjRegistreringIotService *service);
  void setup();
  void handleClient();
};

#endif
