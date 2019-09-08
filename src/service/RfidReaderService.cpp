#include <service/RfidReaderService.h>

RfidReaderService::RfidReaderService(const uint8_t ssPin, const uint8_t rstPin)
{
    mfrc522 = new MFRC522(ssPin, rstPin);
    SPI.begin();                        // Init SPI bus
    mfrc522->PCD_Init();                // Init MFRC522
    mfrc522->PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
}

String RfidReaderService::readUid()
{
    // Look for new cards
    if (!mfrc522->PICC_IsNewCardPresent())
    {
        return String("");
    }
    // Select one of the cards
    if (!mfrc522->PICC_ReadCardSerial())
    {
        return String("");
    }

    String content = "";
    for (byte i = 0; i < mfrc522->uid.size; i++)
    {
        content.concat(String(mfrc522->uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522->uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    return content.substring(1);
}
