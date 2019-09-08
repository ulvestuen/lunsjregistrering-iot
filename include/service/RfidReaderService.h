#ifndef RfidReaderService_h
#define RfidReaderService_h

#include <properties.h>
#include <MFRC522.h>

class RfidReaderService
{

private:
    MFRC522 *mfrc522;

public:
    RfidReaderService(const uint8_t ssPin, const uint8_t rstPin);
    String readUid();
};

#endif
