#ifndef LunsjRegistreringApiClient_h
#define LunsjRegistreringApiClient_h

#include <Arduino.h>
#include <WiFiClientSecure.h>

class LunsjRegistreringApiClient
{

private:
    WiFiClientSecure *client;
    const char *hostName;
    int httpsPort;
    const char *certificateFingerprint;

    void readResponseBody();

public:
    LunsjRegistreringApiClient();
    LunsjRegistreringApiClient(const char *hostame, const int port, const char *fingerprint);
    void sendUid(String uid);
};

#endif
