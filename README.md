# lunsjregristrering-iot



## OTA firmware update
Firmware update can be made by issuing the following command from within the folder `/<your local path>/lunsjregistrering-iot/.pio/build/nodemcuv2/`:
```
curl -X POST http://<ip-address>/update -H 'content-type: multipart/form-data' -F update=@firmware.bin
```
This upload the current binary `firmware.bin` and restarts the microcontroller.

## Retrieve certificate fingerprint
`openssl s_client -connect host:port < /dev/null 2>/dev/null | openssl x509 -fingerprint -noout -in /dev/stdin | tr -d :`