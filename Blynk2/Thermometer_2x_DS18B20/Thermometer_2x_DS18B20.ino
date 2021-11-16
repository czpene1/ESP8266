/*
 * import BLYNK_TEMPLATE_ID and BLYNK_DEVICE_NAME from the file blynk_configs.h
 * Keep the credentials in the separate file and add it into git ignore file
 */
#include "blynk_configs.h"

#define BLYNK_FIRMWARE_VERSION        "0.1.50"
#define BLYNK_PRINT Serial
#define APP_DEBUG

/*
 * Don't forget to uncomment board type to prevent issues with not working pins.
 * (https://community.blynk.cc/t/blynkedgent-and-nodemcu-v-01-problem-d8-gpio15/54346)
 * Or configure a custom board in Settings.h
 */
#define USE_NODE_MCU_BOARD


#include "BlynkEdgent.h"

/* DS18B20 Temperature Sensor */
#include <OneWire.h>
#include <DallasTemperature.h> 

/*#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board*/
#define ONE_WIRE_BUS 4 // DS18B20 on arduino pin4 corresponds to D2 on physical board
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress T1, T2, T3, T4, T5, T6, T7, T8; // arrays to hold device addresses
#define precision 12 // OneWire precision Dallas Sensor 12-bits
//float temp_0;
//float temp_1;
float tempC;

BlynkTimer timer;

//int deviceCount = 0;

void setup()
{
  Serial.begin(115200);
  delay(100);
  BlynkEdgent.begin();
  timer.setInterval(10000L, getSendData);  // start the ON slider timer ...
  
  // Start up the Dallas library
  /*
  sensors.begin();
  // locate devices on the bus
  Serial.print("Found: ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" Devices.");
  // report parasite power requirements
  Serial.print("Parasite power is: ");
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  // Search for devices on the bus and assign based on an index.
 
  if (!sensors.getAddress(T1, 0)) Serial.println("Not Found Sensor 1");
  if (!sensors.getAddress(T2, 1)) Serial.println("Not Found Sensor 2");
  if (!sensors.getAddress(T3, 2)) Serial.println("Not Found Sensor 3");
  if (!sensors.getAddress(T4, 3)) Serial.println("Not Found Sensor 4");
  if (!sensors.getAddress(T5, 4)) Serial.println("Not Found Sensor 5");
  if (!sensors.getAddress(T6, 5)) Serial.println("Not Found Sensor 6");
  if (!sensors.getAddress(T7, 6)) Serial.println("Not Found Sensor 7");
  if (!sensors.getAddress(T8, 7)) Serial.println("Not Found Sensor 8");
 
  // show the addresses we found on the bus
  for (int k =0; k < sensors.getDeviceCount(); k++) {
    Serial.print("Sensor "); Serial.print(k+1);
    Serial.print(" Address: ");
    if (k == 0) { printAddress(T1); Serial.println();}
    else if (k == 1) { printAddress(T2); Serial.println();}
    else if (k == 2) { printAddress(T3); Serial.println();}
    else if (k == 3) { printAddress(T4); Serial.println();}
    else if (k == 4) { printAddress(T5); Serial.println();}
    else if (k == 5) { printAddress(T6); Serial.println();}
    else if (k == 6) { printAddress(T7); Serial.println();}
    else if (k == 7) { printAddress(T8); Serial.println();}
  }

  // set the resolution to 12 bit per device
  sensors.setResolution(T1, precision);
  sensors.setResolution(T2, precision);
  sensors.setResolution(T3, precision);
  sensors.setResolution(T4, precision);
  sensors.setResolution(T5, precision);
  sensors.setResolution(T6, precision);
  sensors.setResolution(T7, precision);
  sensors.setResolution(T8, precision);

  for (int k =0; k < sensors.getDeviceCount(); k++) {
    Serial.print("Sensor "); Serial.print(k+1);
    Serial.print(" Resolution: ");
    if (k == 0) { Serial.print(sensors.getResolution(T1), DEC); Serial.println();}
    else if (k == 1) { Serial.print(sensors.getResolution(T2), DEC); Serial.println();}
    else if (k == 2) { Serial.print(sensors.getResolution(T3), DEC); Serial.println();}
    else if (k == 3) { Serial.print(sensors.getResolution(T4), DEC); Serial.println();}
    else if (k == 4) { Serial.print(sensors.getResolution(T5), DEC); Serial.println();}
    else if (k == 5) { Serial.print(sensors.getResolution(T6), DEC); Serial.println();}
    else if (k == 6) { Serial.print(sensors.getResolution(T7), DEC); Serial.println();}
    else if (k == 7) { Serial.print(sensors.getResolution(T8), DEC); Serial.println();}
  }
  float temp_0 = sensors.getTempCByIndex(0); // Gets 1st probe on wire in lieu of by address
  float temp_1 = sensors.getTempCByIndex(1); // Gets 2nd probe on wire in lieu of by address
  Serial.print(" oC . Temp_0: ");
  Serial.print(temp_0);
  Serial.print(" oC . Temp_1: ");
  Serial.print(temp_1);
  Serial.println(" oC.");
  */
}


void printAddress(DeviceAddress deviceAddress)
{ 
  for (uint8_t i = 0; i < 8; i++)
  {
    Serial.print("0x");
    if (deviceAddress[i] < 0x10) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    if (i < 7) Serial.print(", ");
  }
  Serial.println("");
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}


void getSendData()
{
  sensors.begin();
  // locate devices on the bus
  Serial.print("Found: ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" Devices.");
  Serial.print("Reading DATA...");
  sensors.requestTemperatures();
  Serial.println("DONE");
  // print the device information
  //for (int k =0; k < sensors.getDeviceCount(); k++) {
  //  Serial.print("Sensor "); Serial.print(k+1); Serial.print(" ");
   // if (k == 0) { printData(T1); Blynk.virtualWrite(10, tempBabyRoom);} 
   // else if (k == 1) { printData(T2); }
   // else if (k == 2) { printData(T3); }
   // else if (k == 3) { printData(T4); }
   // else if (k == 4) { printData(T5); }
   // else if (k == 5) { printData(T6); }
   // else if (k == 6) { printData(T7); }
   // else if (k == 7) { printData(T8); }
  //}
  float temp_0 = sensors.getTempCByIndex(0); // Gets 1st probe on wire in lieu of by address
  float temp_1 = sensors.getTempCByIndex(1); // Gets 2nd probe on wire in lieu of by address
  Serial.print(" Temp_0: ");
  Serial.print(temp_0);
  Serial.print(" oC , Temp_1: ");
  Serial.print(temp_1);
  Serial.println(" oC.");
  Blynk.virtualWrite(V10, temp_0);
  Blynk.virtualWrite(V11, temp_1);
}


// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
float tempC = sensors.getTempC(deviceAddress);
Serial.print("Temp : ");
Serial.print(tempC);
Serial.print(" Celsius degres ");
// Serial.print(" Temp F: ");
// Serial.print(DallasTemperature::toFahrenheit(tempC));
}


 
void printData(DeviceAddress deviceAddress)
{
Serial.print("Device Address: ");
printAddress(deviceAddress);
Serial.print(" ");
printTemperature(deviceAddress);
Serial.println();
}


  //temp_0 = DS18B20.getTempCByIndex(0);
  //tempC = DS18B20.getTempC(Thermometer);
  //Serial.print("Temp : ");
  //Serial.print(tempC);
  //temp_1 = DS18B20.getTempCByIndex(1);
  //Blynk.virtualWrite(10, temp_0); //virtual pin V10
  //Blynk.virtualWrite(11, temp_1); //virtual pin V11
  //Serial.print(" oC . Temp_0: ");
  //Serial.print(temp_0);
  //Serial.print(" oC . Temp_1: ");
  //Serial.print(temp_1);
  //Serial.println(" oC");
//}
