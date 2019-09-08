#include <api/LunsjRegistreringIotApi.h>

LunsjRegistreringIotApi::LunsjRegistreringIotApi() {}
LunsjRegistreringIotApi::LunsjRegistreringIotApi(LunsjRegistreringIotStatus *status,
                                                 LunsjRegistreringIotService *service)
{
  server = new ESP8266WebServer(80);
  httpUpdater = new ESP8266HTTPUpdateServer();
  systemStatus = status;
  systemService = service;
}

void LunsjRegistreringIotApi::setup()
{
  server->on("/", [=]() -> void {
    server->send(200, "text/plain", "Lunsjregistrering IoT");
  });

  // Status
  server->on("/status/health", [=]() -> void {
    if (systemStatus->isHealthy())
    {
      server->send(200, "text/plain", "OK");
    }
    else
    {
      server->send(500, "text/plain", "Not OK");
    }
  });

  // Enable OTA update of firmware.
  httpUpdater->setup(server);

  server->begin();
  Serial.println("HTTP server started");
}

void LunsjRegistreringIotApi::handleClient()
{
  server->handleClient();
}

std::vector<int> LunsjRegistreringIotApi::toVector(String stringWithDelimiter, std::string delimiter)
{
  std::vector<int> list;
  std::string sList = std::string(stringWithDelimiter.c_str());

  size_t pos = 0;
  std::string token;
  while ((pos = sList.find(delimiter)) != std::string::npos)
  {
    token = sList.substr(0, pos);
    list.push_back(atoi(token.c_str()));
    sList.erase(0, pos + delimiter.length());
  }
  list.push_back(atoi(sList.c_str()));
  return list;
}