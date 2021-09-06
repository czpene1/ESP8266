// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

// Wifi
#define IOT_CONFIG_WIFI_SSID "MySSID"
#define IOT_CONFIG_WIFI_PASSWORD "MyPassword"


// Azure IoT
#define IOT_CONFIG_IOTHUB_FQDN "NodeMCU-demo-IoTHub.azure-devices.net"  // Update hub FQDN
#define IOT_CONFIG_DEVICE_ID "NodeMCU-01"                               // Update device ID
#define IOT_CONFIG_DEVICE_KEY "OL1Y.............................hAWI="  // Update device key

// Publish 1 message every 2 seconds
#define TELEMETRY_FREQUENCY_MILLISECS 30000   // Azure IoT free limit 8000 messages/day
