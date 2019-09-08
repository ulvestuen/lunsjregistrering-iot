#include <client/LunsjRegistreringApiClient.h>

LunsjRegistreringApiClient::LunsjRegistreringApiClient() {}
LunsjRegistreringApiClient::LunsjRegistreringApiClient(const char *hostname,
                                                       const int port,
                                                       const char *fingerprint)
{
  hostName = hostname;
  httpsPort = port;
  certificateFingerprint = fingerprint;

  // Setup client
  client = new WiFiClientSecure();
  client->setFingerprint(certificateFingerprint);
}

void LunsjRegistreringApiClient::sendUid(String uid)
{
  if (!client->connect(hostName, httpsPort))
  {
    Serial.println("Connection failed");
  }

  String urlPath = "/post";
  Serial.print("Requesting URL: ");
  Serial.println(urlPath);
  String httpMessageBody = "{\"uid\": \"" + uid + "\"}";

  client->print("POST " + urlPath + " HTTP/1.1\r\n" +
                "Host: " + hostName + "\r\n" +
                "User-Agent: BuildFailureDetectorESP8266\r\n" +
                "Content-Type: application/json\r\n" +
                "Content-Length: " + httpMessageBody.length() + "\r\n" +
                "Connection: close\r\n" +
                "\r\n" +
                httpMessageBody);

  if (client->find("200 OK"))
  {
    Serial.println("Server responded with 200 OK");
  }

  // readResponseBody();
  client->stop();
}

void LunsjRegistreringApiClient::readResponseBody()
{
  String answerContent = "";
  String answerLine = " ";
  while (!answerLine.equals(""))
  {
    answerLine = client->readString();
    answerContent += answerLine;
  }

  Serial.println("Reply was:");
  Serial.println("==========");
  Serial.println(answerContent);
  Serial.println("==========");
}
