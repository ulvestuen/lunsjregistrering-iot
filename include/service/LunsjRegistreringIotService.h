#ifndef LunsjRegistreringIotService_h
#define LunsjRegistreringIotService_h

#include <properties.h>
#include <model/LunsjRegistreringIotStatus.h>
#include <service/RfidReaderService.h>
#include <client/LunsjRegistreringApiClient.h>

class LunsjRegistreringIotService
{

private:
    LunsjRegistreringIotStatus *systemStatus;
    LunsjRegistreringApiClient *lunsjRegistreringApiClient;
    RfidReaderService *rfidReaderService;
    String lastUid = "";

public:
    LunsjRegistreringIotService();
    LunsjRegistreringIotService(LunsjRegistreringIotStatus *status);
    void handleLunsjRegistrering();
};

#endif
