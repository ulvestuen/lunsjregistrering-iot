#include <service/LunsjRegistreringIotService.h>

LunsjRegistreringIotService::LunsjRegistreringIotService() {}

LunsjRegistreringIotService::LunsjRegistreringIotService(LunsjRegistreringIotStatus *status)
{
    systemStatus = status;
    lunsjRegistreringApiClient = new LunsjRegistreringApiClient(LUNCH_HOST, 443, LUNCH_FINGERPRINT);
    rfidReaderService = new RfidReaderService(SS_PIN, RST_PIN);
}

void LunsjRegistreringIotService::handleLunsjRegistrering()
{
    String uid = rfidReaderService->readUid();
    if (!uid.equals("") && !uid.equals(lastUid))
    {
        Serial.println("New RFID-chip registered with uid: " + uid);
        lunsjRegistreringApiClient->sendUid(uid);
        lastUid = uid;
    }
}