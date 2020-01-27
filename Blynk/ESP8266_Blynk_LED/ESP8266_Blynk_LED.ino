/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a5efad69de5a420586ba55dcdcd9718b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "mySSID";
char pass[] = "myPass";

// Select your pin with physical button
const int btnPin = 4;

WidgetLED led3(V3);

BlynkTimer timer;

// V3 LED Widget represents the physical button state
boolean btnState = false;
void buttonLedWidget()
{
  // Read button
  boolean isPressed = (digitalRead(btnPin) == LOW);

  // If state has changed...
  if (isPressed != btnState) {
    if (isPressed) {
      led3.on();
    } else {
      led3.off();
    }
    btnState = isPressed;
  }
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);  
  digitalWrite(5, HIGH); 
  digitalWrite(16, HIGH);

  Blynk.begin(auth, ssid, pass);
  //Blynk.syncVirtual(5);
  //Blynk.syncVirtual(16);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Setup physical button pin (active low)
  pinMode(btnPin, INPUT_PULLUP);
  // Setup physical button pin (active high)
  //pinMode(btnPin, INPUT_PULLDOWN);

  timer.setInterval(500L, buttonLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
