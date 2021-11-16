/*
 * import BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME from the file blynk_configs.h
 * Keep the credentials in the separate file and add it into git ignore file
 */
#include "blynk_configs.h"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
  digitalWrite(2,pinValue);     // send value to pin 2

  /*
  Most of the ESP8266 development boards have a built-in LED. This LED is usually connected to GPIO2.
  The LED works with inverted logic. Send a HIGH signal to turn it off, and a LOW signal to turn it on.
  */
  
}

void setup()
{
  pinMode(2,OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
