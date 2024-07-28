/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
  #define _USER_CONFIG_OVERRIDE_H_

  /*****************************************************************************************************\
   * USAGE:
   *   To modify the stock configuration without changing the my_user_config.h file:
   *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
   *   (2) define your own settings below
   *
   ******************************************************************************************************
  * ATTENTION:
  *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
  *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
  *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
  *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
  \*****************************************************************************************************/
  #undef  CFG_HOLDER
    #define CFG_HOLDER        4618                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

  // -- Wi-Fi ---------------------------------------
  #undef WIFI_GATEWAY
    #define WIFI_GATEWAY           "192.168.0.254"      // [IpAddress2] If not using DHCP set Gateway IP address
  #undef WIFI_SUBNETMASK
    #define WIFI_SUBNETMASK        "255.255.255.0"      // [IpAddress3] If not using DHCP set Network mask
  #undef WIFI_DNS
    #define WIFI_DNS               "192.168.0.254"      // [IpAddress4] If not using DHCP set DNS1 IP address (might be equal to WIFI_GATEWAY)

  #undef STA_SSID1
    #define STA_SSID1              "MAISON"                // [Ssid1] Wi-Fi SSID
  #undef STA_PASS1
    #define STA_PASS1              "obdormisti-pervigile%.-ficiendus"                // [Password1] Wi-Fi password
  #undef STA_SSID2
    #define STA_SSID2              "Relai Wifi 2.4G KuWFi"                // [Ssid2] Optional alternate AP Wi-Fi SSID
  #undef STA_PASS2
    #define STA_PASS2              "obdormisti-pervigile%.-ficiendus"                // [Password2] Optional alternate AP Wi-Fi password
  #undef WIFI_AP_PASSPHRASE
    #define WIFI_AP_PASSPHRASE     ""               // AccessPoint passphrase. For WPA2 min 8 char, for open use "" (max 63 char).
  #undef WIFI_CONFIG_TOOL
    #define WIFI_CONFIG_TOOL       WIFI_MANAGER        // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                    // (WIFI_RESTART, WIFI_MANAGER, WIFI_RETRY, WIFI_WAIT, WIFI_SERIAL, WIFI_MANAGER_RESET_ONLY)
                                                    // The configuration can be changed after first setup using WifiConfig 0, 2, 4, 5, 6 and 7.

  #define DNS_TIMEOUT            1000              // [DnsTimeout] Number of ms before DNS timeout
  #define WIFI_ARP_INTERVAL      60                // [SetOption41] Send gratuitous ARP interval
  #undef WIFI_SCAN_AT_RESTART
    #define WIFI_SCAN_AT_RESTART   true             // [SetOption56] Scan Wi-Fi network at restart for configured AP's
  #define WIFI_SCAN_REGULARLY    true              // [SetOption57] Scan Wi-Fi network every 44 minutes for configured AP's
  #define WIFI_NO_SLEEP          false             // [SetOption127] Sets Wifi in no-sleep mode which improves responsiveness on some routers

  // -- Syslog --------------------------------------
  #undef SYS_LOG_HOST
    #define SYS_LOG_HOST           "192.168.0.2"                // [LogHost] (Linux) syslog host
  #undef SYS_LOG_PORT
    #define SYS_LOG_PORT           514               // [LogPort] default syslog UDP port
  #undef SYS_LOG_LEVEL
    #define SYS_LOG_LEVEL          LOG_LEVEL_DEBUG    // [SysLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
  #undef SERIAL_LOG_LEVEL
    #define SERIAL_LOG_LEVEL       LOG_LEVEL_DEBUG    // [SerialLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
  #undef WEB_LOG_LEVEL
    #define WEB_LOG_LEVEL          LOG_LEVEL_DEBUG    // [WebLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)
  #undef MQTT_LOG_LEVEL
    #define MQTT_LOG_LEVEL         LOG_LEVEL_NONE    // [MqttLog] (LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE)

  // -- HTTP ----------------------------------------
  #define WEB_SERVER             2                  // [WebServer] Web server (0 = Off, 1 = Start as User, 2 = Start as Admin)
  #define WEB_PASSWORD           ""                 // [WebPassword] Web server Admin mode Password for WEB_USERNAME (empty string = Disable)
  #define USE_ENHANCED_GUI_WIFI_SCAN                // Enable Wi-Fi scan output with BSSID (+0k5 code)
  #define USE_WEBSEND_RESPONSE                      // Enable command WebSend response message (+1k code)
  #define USE_WEBGETCONFIG                          // Enable restoring config from external webserver (+0k6)
  #define USE_GPIO_VIEWER                           // Enable GPIO Viewer to see realtime GPIO states (+6k code)
    #define GV_SAMPLING_INTERVAL  100               // [GvSampling] milliseconds - Use Tasmota Scheduler (100) or Ticker (20..99,101..1000)
  #define EMULATION              EMUL_NONE          // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)
  #define EMULATION_HUE_1ST_GEN  false              // [Emulation] Force SetOption109 1 - if you only have Echo Dot 2nd gen devices
  #define USE_CORS                                  // [Cors] Enable CORS - Be aware that this feature is unsecure ATM (https://github.com/arendst/Tasmota/issues/6767)
    #define CORS_DOMAIN            ""               // [Cors] CORS Domain for preflight requests

  // -- Setup your own MQTT settings  ---------------
  #undef  MQTT_HOST
    #define MQTT_HOST         "192.168.0.5"          // [MqttHost]
  #undef  MQTT_PORT
    #define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)
  #undef  MQTT_USER
    #define MQTT_USER         "fdaubercy"       	 // [MqttUser] MQTT user
  #undef  MQTT_PASS
    #define MQTT_PASS         "Lune5676"       		 // [MqttPassword] MQTT password

  // -- FTP Server ---------------------------------------
  #define USE_FTP
    #define USER_FTP "fdaubercy"
    #define PW_FTP "Lune5676"

  // -- Telegram Protocol ---------------------------
  #define USE_TELEGRAM                             // Support for Telegram protocol (+49k code, +7.0k mem and +4.8k additional during connection handshake)
    #undef USE_TELEGRAM_FINGERPRINT
      #define USE_TELEGRAM_FINGERPRINT "\xB2\x72\x47\xA6\x69\x8C\x3C\x69\xF9\x58\x6C\xF3\x60\x02\xFB\x83\xFA\x8B\x1F\x23" // Telegram api.telegram.org TLS public key fingerpring

  // -- mDNS ----------------------------------------
  #undef MDNS_ENABLED
    #define MDNS_ENABLED      true                   // [SetOption55] Use mDNS (false = Disable, true = Enable)

  // -- Time - Up to three NTP servers in your region
  #undef NTP_SERVER1
    #define NTP_SERVER1      "pool.ntp.org"        // [NtpServer1] Select first NTP server by name or IP address (135.125.104.101, 2001:418:3ff::53)
  #undef NTP_SERVER2
    #define NTP_SERVER2      "europe.pool.ntp.org" // [NtpServer2] Select second NTP server by name or IP address (192.36.143.134, 2a00:2381:19c6::100)
  #undef NTP_SERVER3
    #define NTP_SERVER3      "nl.pool.ntp.org"     // [NtpServer3] Select third NTP server by name or IP address (46.249.42.13, 2603:c022:c003:c900::4)

  // -- Location ------------------------------------
  #undef LATITUDE
    #define LATITUDE               50.4109163         // [Latitude] Your location to be used with sunrise and sunset
  #undef LONGITUDE 
    #define LONGITUDE              3.0858052          // [Longitude] Your location to be used with sunrise and sunset

  // -- Application ---------------------------------
  #undef APP_TIMEZONE
    #define APP_TIMEZONE           99                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

  /*********************************************************************************************\
   * END OF SECTION 1
   *
   * SECTION 2
   * - Enable a feature by removing both // in front of it
   * - Disable a feature by preceding it with //
  \*********************************************************************************************/

  // -- Localization --------------------------------
    // If non selected the default en-GB will be used
  #define MY_LANGUAGE            fr_FR           // French in France

  // -- Ping ----------------------------------------
  #define USE_PING                                 // Enable Ping command (+2k code)

  // -- HTTP ----------------------------------------
  #undef USE_WEBSERVER
    #define USE_WEBSERVER                            // Enable web server and Wi-Fi Manager (+66k code, +8k mem)
  #ifdef USE_WEBSERVER
    #define USE_ENHANCED_GUI_WIFI_SCAN             // Enable Wi-Fi scan output with BSSID (+0k5 code)
    #define USE_WEBSEND_RESPONSE                   // Enable command WebSend response message (+1k code)
    #define USE_GPIO_VIEWER                        // Enable GPIO Viewer to see realtime GPIO states (+6k code)
    #define GV_SAMPLING_INTERVAL  100            // [GvSampling] milliseconds - Use Tasmota Scheduler (100) or Ticker (20..99,101..1000)
  #endif
    
  // -- Rules or Script  ----------------------------
  // Select none or only one of the below defines USE_RULES or USE_SCRIPT
  //#define USE_SCRIPT                               // Add support for script (+17k code)
    //#define USE_SCRIPT_FATFS 4                     // Script: Add FAT FileSystem Support
    #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)

  // -- Optional modules ----------------------------
  #undef ROTARY_V1                                // Add support for Rotary Encoder as used in MI Desk Lamp (+0k8 code)
    #undef ROTARY_MAX_STEPS     //10                // Rotary step boundary
  #undef USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge (+3k2 code)
    #undef USE_RF_FLASH                           // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+2k7 code)
  #undef USE_SONOFF_SC                            // Add support for Sonoff Sc (+1k1 code)
  #undef USE_TUYA_MCU                             // Add support for Tuya Serial MCU
    #undef TUYA_DIMMER_ID       //0                 // Default dimmer Id
    #undef USE_TUYA_TIME                          // Add support for Set Time in Tuya MCU
  #undef USE_TUYAMCUBR                            // Add support for TuyaMCU Bridge

  // -- One wire sensors ----------------------------
  #undef USE_DS18x20                              // Add support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)

  // -- IR Remote features - subset of IR protocols --------------------------
  #undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 (+4k3 code, 0k3 mem, 48 iram)

    // Enable IR devoder via GPIO `IR Recv` - always enabled if `USE_IR_REMOTE_FULL`
    #undef USE_IR_RECEIVE                         // Support for IR receiver (+7k2 code, 264 iram)

  // -- Other sensors/drivers -----------------------

  /*********************************************************************************************\
   * ESP32 only features
  \*********************************************************************************************/
  #ifdef ESP32
    #define USE_ESP32_SENSORS                        // Add support for ESP32 temperature and optional hall effect sensor
    #define USE_AUTOCONF                             // Enable Esp32 autoconf feature, requires USE_BERRY and USE_WEBCLIENT_HTTPS (12KB Flash)

    // -- Paramètres BERRY ----------------------------
    #define USE_BERRY                                // Enable Berry scripting language
      #define USE_BERRY_PYTHON_COMPAT                // Enable by default `import python_compat`
      #define USE_BERRY_TIMEOUT             4000     // Timeout in ms, will raise an exception if running time exceeds this timeout
      #define USE_BERRY_PSRAM                        // Allocate Berry memory in PSRAM if PSRAM is connected - this might be slightly slower but leaves main memory intact
      #define USE_BERRY_IRAM                         // Allocate some data structures in IRAM (which is ususally unused) when possible and if no PSRAM is available
      #define USE_BERRY_FAST_LOOP_SLEEP_MS  5        // Minimum time in milliseconds to before calling again `tasmota.fast_loop()`, a smaller value will consume more CPU (min 1ms)
      //#define USE_BERRY_DEBUG                        // Compile Berry bytecode with line number information, makes exceptions easier to debug. Adds +8% of memory consumption for compiled code
        //#define UBE_BERRY_DEBUG_GC                   // Print low-level GC metrics
      #define USE_BERRY_INT64                        // Add 64 bits integer support (+1.7KB Flash)

      #undef USE_BERRY_PARTITION_WIZARD
        #define USE_BERRY_PARTITION_WIZARD           // Add a button to dynamically load the Partion Wizard from a bec file online (+1.3KB Flash)
        #define USE_BERRY_PARTITION_WIZARD_URL      "http://ota.tasmota.com/tapp/partition_wizard.bec"
      #define USE_BERRY_GPIOVIEWER                 // Add a button to dynamocally load the GPIO Viewer from a bec file online
        #define USE_BERRY_GPIOVIEWER_URL            "http://ota.tasmota.com/tapp/gpioviewer.bec"    // Connect to http: <your_tasmota_ip:5555/
      #define USE_BERRY_TCPSERVER                    // Enable TCP socket server (+0.6k)
      #define USE_BERRY_ULP                          // Enable ULP (Ultra Low Power) support (+4.9k)

    // -- LVGL Graphics Library ---------------------------------

  #endif  // ESP32

  /*********************************************************************************************\
   * Debug features
  \*********************************************************************************************/

  //#define DEBUG_TASMOTA_CORE                       // Enable core debug messages
  #define DEBUG_TASMOTA_DRIVER                     // Enable driver debug messages
  //#define DEBUG_TASMOTA_SENSOR                     // Enable sensor debug messages
  //#define USE_DEBUG_DRIVER                         // Use xdrv_99_debug.ino providing commands CpuChk, CfgXor, CfgDump, CfgPeek and CfgPoke

  #define USE_SONOFF_SPM                           // Add support for ESP32 based Sonoff Smart Stackable Power Meter (+11k code)

  /*********************************************************************************************\
   * END OF SECTION 2
   *
   * SECTION 3
   * - Firmwares personnalisés
  \*********************************************************************************************/
  #ifndef ESP32
    #error *** Ces parametres son destines à Tasmota32 ***
  #endif  

  // -- Options for firmware tasmota32-serveur-rly-cave ------
  #ifdef FIRMWARE_SERVEUR_RLY_CAVE
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "serveur-rly-cave"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "SERVEUR-RLY-CAVE"         	 // PROJECT is used as the default topic delimiter
    //#define USER_TEMPLATE "{\"NAME\":\"ESP32 Relay x8\",\"GPIO\":[33,1,160,1,32,1,1,1,1,1,1,161,1,1,34,1,1,1,1216,288,1,226,227,228,1,1,1,1,224,225,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"
    //#define USER_TEMPLATE "{\"NAME\":\"ESP32 Relay x8\",\"GPIO\":[33, 1, 160, 1, 32, 6720, 0, 0, 1, 1, 1, 161, 0, 0, 736, 672, 1, 34, 1216, 704, 1, 226, 227, 228, 0, 0, 0, 0, 224, 225, 1, 1, 1, 1, 1, 1],\"FLAG\":0,\"BASE\":1}"
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
    #define WIFI_IP_ADDRESS "192.168.0.48" // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

    // -- Setup your own Wifi settings  ---------------
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
    #define MQTT_CLIENT_ID "SERVEUR-RLY-CAVE" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
    #define MQTT_TOPIC "cave/serveur-rly-cave" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
    #define MQTT_GRPTOPIC "tasmotas/cave" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Serveur Relais Cave" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
    #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)

    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
    #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices

    // -- LCD I2C -----------------------
    //#define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
    //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
    //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    //#define USE_GRAPH           // Enable line charts with displays
    //#define NUM_GRAPHS 4        // Max 16

    // -- I2C sensors ---------------------------------

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Rules or Script  ----------------------------
    #undef USER_BACKLOG
      #define USER_BACKLOG      "Backlog Module 0; Hostname SERVEUR-RLY-CAVE;"

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
    #ifdef USE_SPI
      #define USE_UFILESYS
      #define GUI_EDIT_FILE
      #define GUI_TRASH_FILE

    // -- SD Card support -----------------------------
      #define USE_SDCARD                      // mount SD Card, requires configured SPI pins and setting of `SDCard CS` gpio
      #define SDC_HIDE_INVISIBLES             // hide hidden directories from the SD Card, which prevents crashes when dealing SD created on MacOS
      #define SDCARD_CS_PIN 5                 // Not strictly necessary since the same #define happens in xdrv_50_filesystem.ino
    #endif
  #endif

  // -- Options for firmware tasmota32-teleinfo-conso ------
  #ifdef FIRMWARE_TELEINFO_CONSO
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "teleinfo-conso"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "ESP32-TELEINFO"         	 // PROJECT is used as the default topic delimiter
    #define USER_TEMPLATE 		"{\"NAME\":\"Wemos Teleinfo\",\"GPIO\":[1,1,1,1,5664,1,1,1,1,1,1,1,1,1,1376,1,1,640,608,5632,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"

    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS        "0.0.0.0"            // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

    // -- Setup your own Wifi settings  ---------------
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID    "TELEINFO-CONSO"       // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef  MQTT_TOPIC
      #define MQTT_TOPIC        "teleinfo/consommation"   		 // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC     "tasmotas"        // [GroupTopic] MQTT Group topic  
    #undef  FRIENDLY_NAME
      #define FRIENDLY_NAME     "TéléInfo Consommation"           // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION         EMUL_NONE               // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)

    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE   true  // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER                              // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

    // -- LCD I2C -----------------------
    #define USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
      #define USE_DISPLAY                            // Add I2C/TM1637/MAX7219 Display Support (+2k code)
        #define USE_DISPLAY_SSD1306                  // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
        #define USE_DISPLAY_SH1106                   // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
        #define USE_GRAPH                            // Enable line charts with displays
        #define NUM_GRAPHS     4                     // Max 16

    // -- I2C sensors ---------------------------------

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Power monitoring sensors --------------------
    #define USE_TELEINFO                             // Add support for Teleinfo via serial RX interface (+5k2 code, +168 RAM + SmartMeter LinkedList Values RAM)

    // -- Rules or Script  ----------------------------
    #undef USER_BACKLOG
      #define USER_BACKLOG      "Backlog Module 0; Hostname ESP32-TELEINFO;"
  #endif

  // -- Options for firmware tasmota32-teleinfo-prod ------
  #ifdef FIRMWARE_TELEINFO_PROD
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "teleinfo-prod"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "ESP32-TELEINFO"         	 // PROJECT is used as the default topic delimiter
    #define USER_TEMPLATE 		"{\"NAME\":\"Wemos Teleinfo\",\"GPIO\":[1,1,1,1,5664,1,1,1,1,1,1,1,1,1,1376,1,1,640,608,5632,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"

    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS        "0.0.0.0"            // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

    // -- Setup your own Wifi settings  ---------------
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID    "TELEINFO-PROD"       // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef  MQTT_TOPIC
      #define MQTT_TOPIC        "teleinfo/production"   		 // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC     "tasmotas"        // [GroupTopic] MQTT Group topic  
    #undef  FRIENDLY_NAME
      #define FRIENDLY_NAME     "TéléInfo Production"           // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION         EMUL_NONE               // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)

    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE   true  // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER                              // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

    // -- LCD I2C -----------------------
    #define USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
      #define USE_DISPLAY                            // Add I2C/TM1637/MAX7219 Display Support (+2k code)
        #define USE_DISPLAY_SSD1306                  // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
        #define USE_DISPLAY_SH1106                   // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
        #define USE_GRAPH                            // Enable line charts with displays
        #define NUM_GRAPHS     4                     // Max 16

    // -- I2C sensors ---------------------------------

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Power monitoring sensors --------------------
    #define USE_TELEINFO                             // Add support for Teleinfo via serial RX interface (+5k2 code, +168 RAM + SmartMeter LinkedList Values RAM)

    // -- Rules or Script  ----------------------------
    #undef USER_BACKLOG
      #define USER_BACKLOG      "Backlog Module 0; Hostname ESP32-TELEINFO;"
  #endif

  // -- Options for firmware tasmota32-vr-porte ------
  #ifdef FIRMWARE_VR_PORTE
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "vr-porte"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "VR-PORTE"         	 // PROJECT is used as the default topic delimiter
    #define USER_TEMPLATE "{\"NAME\":\"Sonoff Dual R3\",\"GPIO\":[1,1,1,1,1,1,1,1,1,576,224,1,1,1,1,1,0,1,1,1,0,1,1,225,0,0,0,0,160,161,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"

    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
    #define WIFI_IP_ADDRESS "192.168.0.46" // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

    // -- Setup your own Wifi settings  ---------------
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
    #define MQTT_CLIENT_ID "VR-PORTE" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
    #define MQTT_TOPIC "volet/entree" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
    #define MQTT_GRPTOPIC "tasmotas/volets" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
    #define FRIENDLY_NAME "Volet de porte d'entrée" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
    #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)

    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
    #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #define USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices

    // -- Rules or Script  ----------------------------
    #undef USER_BACKLOG
      #define USER_BACKLOG      "Backlog Module 0; Hostname VR-PORTE;"
  #endif

  // -- Options for firmware tasmota32-serveur-rly-rdc ------
  #ifdef FIRMWARE_SERVEUR_RLY_RDC
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "serveur-rly-rdc"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "SERVEUR-RLY-RDC"         	 // PROJECT is used as the default topic delimiter
    #define USER_TEMPLATE 		"{\"NAME\":\"ESP32 Relay x8\",\"GPIO\":[33,1,160,1,32,6720,0,0,1,1,1,160,1,1,736,672,1,1216,1,704,1,226,227,228,0,0,0,0,224,225,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
    #define WIFI_IP_ADDRESS "192.168.0.47" // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

    // -- Setup your own Wifi settings  ---------------
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "SERVEUR-RLY-RDC" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "rdc/serveur-rly-rdc" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/rdc" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Serveur Relais RdC" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)
    
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #define USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	
    
    // -- LCD I2C -----------------------
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
    //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
    //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    //#define USE_GRAPH           // Enable line charts with displays
    //#define NUM_GRAPHS 4        // Max 16

    // -- I2C sensors ---------------------------------
    //#define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
    //#define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
    //#define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
    #ifdef USE_SPI
      // -- SD Card support -----------------------------
      #define USE_SDCARD                      // mount SD Card, requires configured SPI pins and setting of `SDCard CS` gpio
      #define SDC_HIDE_INVISIBLES             // hide hidden directories from the SD Card, which prevents crashes when dealing SD created on MacOS
      #define SDCARD_CS_PIN 5                 // Not strictly necessary since the same #define happens in xdrv_50_filesystem.ino
    #endif

    // -- ESP-NOW -------------------------------------
    // Plus d'info dans le dossier : "Tasmota\info\xdrv_57_tasmesh.md"
    //#define USE_TASMESH                              // Enable Tasmota Mesh using ESP-NOW (+11k code)
    //#define USE_TASMESH_HEARTBEAT                    // If enabled, the broker will detect when nodes come online and offline and send Birth and LWT messages over MQTT correspondingly
    //#define TASMESH_OFFLINE_DELAY  3                 // Maximum number of seconds since the last heartbeat before the broker considers a node to be offline

    // -- Serial sensors ------------------------------
    //#define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)

    // -- Other sensors/drivers -----------------------
    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    #define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif

    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    //#define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
      //#define USER_RULE1 "Rule1 on system#boot do meshbroker endon"          // Add rule1 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      #define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-RLY-RDC;"
  #endif

  // -- Options for firmware tasmota32-serveur-debitmetres-pac ------
  #ifdef FIRMWARE_SERVEUR_DEBITMETRES_PAC
    #if TASMOTA_VERSION > 0x0D040000
      #error *** Ce firmware ne fonctionne pas au dela de la version 13.4.0 du firmware Tasmota ***
    #endif
    
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
      #define CODE_IMAGE_STR "serveur debitmetres pac"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "SERVEUR-DEBITMETRES-PAC"         	 // PROJECT is used as the default topic delimiter
      #define USER_TEMPLATE 		"{\"NAME\":\"ESP32 Debitmetres PAC\",\"GPIO\":[1,1,1,1,1,6720,1,1,1,1,1,1,1,1,736,672,1,1,1,704,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"
      
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS "192.168.0.43" // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
      
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    #undef WIFI_CONFIG_TOOL
      #define WIFI_CONFIG_TOOL       WIFI_RETRY         // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                        // (0=WIFI_RESTART, 2=WIFI_MANAGER, 4=WIFI_RETRY, 5=WIFI_WAIT, 6=WIFI_SERIAL, 7=WIFI_MANAGER_RESET_ONLY)

    // -- Setup your own RANGE EXTENDER settings  -----
    // Les autres paramètres du RangeExtender sont gérés par la partie 'Post-process compile options' en fin de fichier
    // Backlog RgxSSID rangeextender ; RgxPassword securepassword ; RgxAddress 192.168.123.1 ; RgxSubnet 255.255.255.0; RgxState 1 ; RgxNAPT 1
    #define USE_WIFI_RANGE_EXTENDER
      #define WIFI_RGX_SSID           "SERVEUR-DEBITMETRES-PAC-AP"
      #define WIFI_RGX_PASSWORD       "Lune5676"
  
    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "DEBITMETRES-PAC" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "pac/debitmetres" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/pac" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Débitmètres PAC" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL__NONE, EMUL_WEMO or EMUL_HUE)
  
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	

    // -- Optional light modules ----------------------
    #undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
      #undef USE_WS2812_HARDWARE  //NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)
      #undef  USE_WS2812_CTYPE     //NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
    
    // -- LCD I2C -----------------------
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
    //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
    //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    //#define USE_GRAPH           // Enable line charts with displays
    //#define NUM_GRAPHS 4        // Max 16

      // -- I2C sensors ---------------------------------
    #define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
    #define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
    #define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
      #define USE_ILI9488                            // Utilisation de l'ecran ILI9488. Les autres paramètres pour ILI9488 sont gérés par la partie 'Post-process compile options' en fin de fichier  

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Serial sensors ------------------------------
    //#define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)

    // -- Other sensors/drivers -----------------------
    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    //#define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif

    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    #define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
      //#define USER_RULE1 "ON System#Boot DO RgxPort tcp, 8080, 10.99.0.2, 80 ENDON"          // Add rule1 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      //#define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-DEBITMETRES-PAC; Sensor96 1 3500; Sensor96 2 3500;"
      #define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-DEBITMETRES-PAC;"
  #endif

  // -- Options for firmware tasmota32-serveur-debitmetres-pac ------
  #ifdef FIRMWARE_ESP32S3_SERVEUR_DEBITMETRES_PAC
    #if TASMOTA_VERSION > 0x0D040000
      #error *** Ce firmware ne fonctionne pas au dela de la version 13.4.0 du firmware Tasmota ***
    #endif
    
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
      #define CODE_IMAGE_STR "serveur debitmetres pac"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "SERVEUR-DEBITMETRES-PAC"         	 // PROJECT is used as the default topic delimiter
      #define USER_TEMPLATE 		"{\"NAME\":\"ESP32S3 Debitmetres PAC\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,288,544,1,1,1,1,1,1,1,1,1376],\"FLAG\":0,\"BASE\":1}"
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS "192.168.0.43" // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
      
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    #undef WIFI_CONFIG_TOOL
      #define WIFI_CONFIG_TOOL       WIFI_RETRY         // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                        // (0=WIFI_RESTART, 2=WIFI_MANAGER, 4=WIFI_RETRY, 5=WIFI_WAIT, 6=WIFI_SERIAL, 7=WIFI_MANAGER_RESET_ONLY)

    // -- Setup your own RANGE EXTENDER settings  -----
    // Les autres paramètres du RangeExtender sont gérés par la partie 'Post-process compile options' en fin de fichier
    // Backlog RgxSSID rangeextender ; RgxPassword securepassword ; RgxAddress 192.168.123.1 ; RgxSubnet 255.255.255.0; RgxState 1 ; RgxNAPT 1
    #define USE_WIFI_RANGE_EXTENDER
      #define WIFI_RGX_SSID           "SERVEUR-DEBITMETRES-PAC-AP"
      #define WIFI_RGX_PASSWORD       "Lune5676"
  
    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "SERVEUR-DEBITMETRES-PAC" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "pac/debitmetres" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/pac" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Débitmètres PAC" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL__NONE, EMUL_WEMO or EMUL_HUE)
  
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	

    // -- Optional light modules ----------------------
    #define USE_LIGHT                                // Add support for light control
    #define USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
    //  #define USE_WS2812_DMA                         // ESP8266 only, DMA supports only GPIO03 (= Serial RXD) (+1k mem). When USE_WS2812_DMA is enabled expect Exceptions on Pow
      #define USE_WS2812_RMT  0                      // ESP32 only, hardware RMT support (default). Specify the RMT channel 0..7. This should be preferred to software bit bang.
    //  #define USE_WS2812_I2S  0                      // ESP32 only, hardware I2S support. Specify the I2S channel 0..2. This is exclusive from RMT. By default, prefer RMT support
    //  #define USE_WS2812_INVERTED                    // Use inverted data signal
      #define USE_WS2812_HARDWARE  NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)
      #undef USE_WS2812_CTYPE
      #define USE_WS2812_CTYPE     NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
    
    // -- I2C -----------------------
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    #ifdef USE_I2C
      // -- LCD I2C -----------------------
      //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
      //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
      //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
      //#define USE_GRAPH           // Enable line charts with displays
      //#define NUM_GRAPHS 4        // Max 16

      // -- I2C sensors ---------------------------------
      #define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
      #define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
      #define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

      // Cf. url: https://tasmota.github.io/docs/MCP230xx/
      // Vérifier activation du driver : I2cDriver22 1
      // Tester l'adresse du module MCP23XXX (adresse comprise entre 0x20 & 0x26) : I2CScan
      // Les paramètres des I/O est realisé dans le fichier mcp23xx.dat
      // Paramètres Mode 2 MCP23017
      // #define USE_MCP23XXX_DRV

      // Paramètres Mode 1 MCP23017 (mode lancé si echec activation mode 2)
      #ifdef USE_MCP23XXX_DRV
        #define USE_MCP230xx                            // [I2cDriver22] Enable MCP23008/MCP23017 - Must define I2C Address in #define USE_MCP230xx_ADDR below - range 0x20 - 0x27 (+5k1 code)
        #define USE_MCP230xx_ADDR 0x20                  // Enable MCP23008/MCP23017 I2C Address to use (Must be within range 0x20 through 0x26 - set according to your wired setup)
        #define USE_MCP230xx_OUTPUT                     // Enable MCP23008/MCP23017 OUTPUT support through sensor29 commands (+2k2 code)
        #define USE_MCP230xx_DISPLAYOUTPUT              // Enable MCP23008/MCP23017 to display state of OUTPUT pins on Web UI (+0k2 code)
      #endif
    #endif

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
      //#define USE_ILI9488                            // Utilisation de l'ecran ILI9488. Les autres paramètres pour ILI9488 sont gérés par la partie 'Post-process compile options' en fin de fichier

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Serial sensors ------------------------------
    //#define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)

    // -- Other sensors/drivers -----------------------
    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    //#define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif
    
    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    #define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
      //#define USER_RULE1 "<Any rule1 data>"          // Add rule1 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      #define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-DEBITMETRES-PAC;"
  #endif

  // -- Options for firmware tasmota32-serveur-debitmetres-pac ------
  #ifdef FIRMWARE_ESP32S3_LCD_SERVEUR_DEBITMETRES_PAC
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
      #define CODE_IMAGE_STR "ili9488 pac"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "ILI9488-PAC"         	 // PROJECT is used as the default topic delimiter
      #define USER_TEMPLATE 		"{\"NAME\":\"ESP32S3 ILI8499\",\"GPIO\":[6210,1,1,11008,992,1,1024,800,1,7264,768,704,736,672,1,1,1,1,1,1,1,1,1,1,1,1,1,288,544,1,1,1,1,1,1,1,1,1376],\"FLAG\":0,\"BASE\":1}"
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS       "10.99.0.3"         // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
    #undef WIFI_GATEWAY
      #define WIFI_GATEWAY           "10.99.0.1"      // [IpAddress2] If not using DHCP set Gateway IP address
      
    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    #undef WIFI_CONFIG_TOOL
      #define WIFI_CONFIG_TOOL       WIFI_MANAGER         // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                        // (0=WIFI_RESTART, 2=WIFI_MANAGER, 4=WIFI_RETRY, 5=WIFI_WAIT, 6=WIFI_SERIAL, 7=WIFI_MANAGER_RESET_ONLY)
  
    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "ILI9488-PAC" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "pac/ili8499" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/pac" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Ecran ILI9488 PAC" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL__NONE, EMUL_WEMO or EMUL_HUE)
  
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	

    // -- Optional light modules ----------------------
    #define USE_LIGHT                                // Add support for light control
    #define USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
    //  #define USE_WS2812_DMA                         // ESP8266 only, DMA supports only GPIO03 (= Serial RXD) (+1k mem). When USE_WS2812_DMA is enabled expect Exceptions on Pow
      #define USE_WS2812_RMT  0                      // ESP32 only, hardware RMT support (default). Specify the RMT channel 0..7. This should be preferred to software bit bang.
    //  #define USE_WS2812_I2S  0                      // ESP32 only, hardware I2S support. Specify the I2S channel 0..2. This is exclusive from RMT. By default, prefer RMT support
    //  #define USE_WS2812_INVERTED                    // Use inverted data signal
      #define USE_WS2812_HARDWARE  NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)
      #undef USE_WS2812_CTYPE
      #define USE_WS2812_CTYPE     NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
    
    // -- I2C -----------------------
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    #ifdef USE_I2C
      // -- LCD I2C -----------------------
      //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
      //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
      //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
      //#define USE_GRAPH           // Enable line charts with displays
      //#define NUM_GRAPHS 4        // Max 16

      // -- I2C sensors ---------------------------------
      #define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
      #define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
      #define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

      // Cf. url: https://tasmota.github.io/docs/MCP230xx/
      // Vérifier activation du driver : I2cDriver22 1
      // Tester l'adresse du module MCP23XXX (adresse comprise entre 0x20 & 0x26) : I2CScan
      // Les paramètres des I/O est realisé dans le fichier mcp23xx.dat
      // Paramètres Mode 2 MCP23017
      // #define USE_MCP23XXX_DRV

      // Paramètres Mode 1 MCP23017 (mode lancé si echec activation mode 2)
      #ifdef USE_MCP23XXX_DRV
        #define USE_MCP230xx                            // [I2cDriver22] Enable MCP23008/MCP23017 - Must define I2C Address in #define USE_MCP230xx_ADDR below - range 0x20 - 0x27 (+5k1 code)
        #define USE_MCP230xx_ADDR 0x20                  // Enable MCP23008/MCP23017 I2C Address to use (Must be within range 0x20 through 0x26 - set according to your wired setup)
        #define USE_MCP230xx_OUTPUT                     // Enable MCP23008/MCP23017 OUTPUT support through sensor29 commands (+2k2 code)
        #define USE_MCP230xx_DISPLAYOUTPUT              // Enable MCP23008/MCP23017 to display state of OUTPUT pins on Web UI (+0k2 code)
      #endif
    #endif

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
      #define USE_ILI9488                            // Utilisation de l'ecran ILI9488. Les autres paramètres pour ILI9488 sont gérés par la partie 'Post-process compile options' en fin de fichier

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Serial sensors ------------------------------
    //#define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)

    // -- Other sensors/drivers -----------------------
    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    //#define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif
    
    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    #define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
      //#define USER_RULE1 "<Any rule1 data>"          // Add rule1 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      #define USER_BACKLOG "Backlog Module 0; Hostname ILI9488-PAC;"
  #endif

  // -- Options for firmware tasmota32-debitmetres-pac1 ------
  #ifdef FIRMWARE_DEBITMETRES_PAC1
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
      #define CODE_IMAGE_STR "debitmetres pac"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "DEBITMETRES-PAC"         	 // PROJECT is used as the default topic delimiter
      #define USER_TEMPLATE 		"{\"NAME\":\"ESP32 Debitmetres PAC\",\"GPIO\":[1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,8992,8993,1,0,0,0,0,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":1}"
      
    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS       "10.99.0.2"         // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
    #undef WIFI_GATEWAY
      #define WIFI_GATEWAY           "10.99.0.1"      // [IpAddress2] If not using DHCP set Gateway IP address

    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    #undef STA_SSID1
      #define STA_SSID1              "SERVEUR-DEBITMETRES-PAC-AP"                // [Ssid1] Wi-Fi SSID
    #undef STA_PASS1
      #define STA_PASS1              "Lune5676"                // [Password1] Wi-Fi password
    #undef STA_SSID2
      #define STA_SSID2              ""                // [Ssid2] Optional alternate AP Wi-Fi SSID
    #undef STA_PASS2
      #define STA_PASS2              ""                // [Password2] Optional alternate AP Wi-Fi password
    #undef WIFI_AP_PASSPHRASE
      #define WIFI_AP_PASSPHRASE     ""               // AccessPoint passphrase. For WPA2 min 8 char, for open use "" (max 63 char).
    #undef WIFI_CONFIG_TOOL
      #define WIFI_CONFIG_TOOL       WIFI_WAIT         // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                        // (0=WIFI_RESTART, 2=WIFI_MANAGER, 4=WIFI_RETRY, 5=WIFI_WAIT, 6=WIFI_SERIAL, 7=WIFI_MANAGER_RESET_ONLY)

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "DEBITMETRES-PAC-1" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "pac/module1" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/pac" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Débitmètres PAC 1" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)
    
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	

      // -- Optional light modules ----------------------
    #undef USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
      #undef USE_WS2812_HARDWARE  //NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)
      #undef  USE_WS2812_CTYPE     //NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
    
    // -- LCD I2C -----------------------
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
    //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
    //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    //#define USE_GRAPH           // Enable line charts with displays
    //#define NUM_GRAPHS 4        // Max 16

    // -- I2C sensors ---------------------------------
    #define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
    #define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
    #define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
      //#define USE_ILI9488                            // Utilisation de l'ecran ILI9488. Les autres paramètres pour ILI9488 sont gérés par la partie 'Post-process compile options' en fin de fichier

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Other sensors/drivers -----------------------
    #define USE_FLOWRATEMETER                        // Add support for water flow meter YF-DN50 and similary (+1k7 code)
    #ifdef USE_FLOWRATEMETER
      //#define D_JSON_FLOWRATEMETER                 "debitmetre" 
    #endif

    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    //#define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif

    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    #define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
      //#define USER_RULE1 "Rule1 on system#boot do meshbroker endon"          // Add rule1 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
      //#define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      //#define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-DEBITMETRES-PAC; Sensor96 1 3500; Sensor96 2 3500;"
      #define USER_BACKLOG "Backlog Module 0; Hostname DEBITMETRES-PAC-1;"
  #endif

    // -- Options for firmware tasmota32s3-debitmetres-pac1 ------
  #ifdef FIRMWARE_ESP32S3_DEBITMETRES_PAC1
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
      #define CODE_IMAGE_STR "debitmetres pac"

    // -- Project -------------------------------------
    #undef PROJECT
      #define PROJECT           "DEBITMETRES-PAC"         	 // PROJECT is used as the default topic delimiter
      #define USER_TEMPLATE 		"{\"NAME\":\"ESP32S3 Debitmetres PAC\",\"GPIO\":[1,1,1,1,640,608,1,1,1,1,1,1,1,8993,8992,1,1,1,1,1,1,1,1,1,1,1,1,288,544,1,1,1,1,1,1,1,1,1376],\"FLAG\":0,\"BASE\":1}"

    // -- Wi-Fi ---------------------------------------
    #undef WIFI_IP_ADDRESS
      #define WIFI_IP_ADDRESS       "10.99.0.2"         // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
    #undef WIFI_GATEWAY
      #define WIFI_GATEWAY           "10.99.0.1"      // [IpAddress2] If not using DHCP set Gateway IP address

    // You might even pass some parameters from the command line ----------------------------
    // Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

    #undef STA_SSID1
      #define STA_SSID1              "SERVEUR-DEBITMETRES-PAC-AP"                // [Ssid1] Wi-Fi SSID
    #undef STA_PASS1
      #define STA_PASS1              "Lune5676"                // [Password1] Wi-Fi password
    #undef STA_SSID2
      #define STA_SSID2              ""                // [Ssid2] Optional alternate AP Wi-Fi SSID
    #undef STA_PASS2
      #define STA_PASS2              ""                // [Password2] Optional alternate AP Wi-Fi password
    #undef WIFI_AP_PASSPHRASE
      #define WIFI_AP_PASSPHRASE     ""               // AccessPoint passphrase. For WPA2 min 8 char, for open use "" (max 63 char).
    #undef WIFI_CONFIG_TOOL
      #define WIFI_CONFIG_TOOL       WIFI_WAIT         // [WifiConfig] Default tool if Wi-Fi fails to connect (default option: 4 - WIFI_RETRY)
                                                        // (0=WIFI_RESTART, 2=WIFI_MANAGER, 4=WIFI_RETRY, 5=WIFI_WAIT, 6=WIFI_SERIAL, 7=WIFI_MANAGER_RESET_ONLY)

    // -- Setup your own MQTT settings  ---------------
    #undef MQTT_CLIENT_ID
      #define MQTT_CLIENT_ID "DEBITMETRES-PAC-1" // [MqttClient] Also fall back topic using last 6 characters of MAC address or use "DVES_%12X" for complete MAC address
    #undef MQTT_TOPIC
      #define MQTT_TOPIC "pac/module1" // [Topic] unique MQTT device topic including (part of) device MAC address
    #undef MQTT_GRPTOPIC
      #define MQTT_GRPTOPIC "tasmotas/pac" // [GroupTopic] MQTT Group topic
    #undef FRIENDLY_NAME
      #define FRIENDLY_NAME "Débitmètres PAC 1" // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
    #undef EMULATION
      #define EMULATION EMUL_NONE // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)
    
    // -- MQTT - Home Assistant Discovery -------------
    #undef HOME_ASSISTANT_DISCOVERY_ENABLE
      #define HOME_ASSISTANT_DISCOVERY_ENABLE true // [SetOption19] Home Assistant Discovery (false = Disable, true = Enable)

    // -- Optional modules ----------------------------
    #undef USE_SHUTTER // Add Shutter support for up to 4 shutter with different motortypes (+11k code)

    // -- Internal Analog input -----------------------
    #undef USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices	

    // -- Optional light modules ----------------------
    #define USE_LIGHT                                // Add support for light control
    #define USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
    //  #define USE_WS2812_DMA                         // ESP8266 only, DMA supports only GPIO03 (= Serial RXD) (+1k mem). When USE_WS2812_DMA is enabled expect Exceptions on Pow
      #define USE_WS2812_RMT  0                      // ESP32 only, hardware RMT support (default). Specify the RMT channel 0..7. This should be preferred to software bit bang.
    //  #define USE_WS2812_I2S  0                      // ESP32 only, hardware I2S support. Specify the I2S channel 0..2. This is exclusive from RMT. By default, prefer RMT support
    //  #define USE_WS2812_INVERTED                    // Use inverted data signal
      #define USE_WS2812_HARDWARE  NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106, NEO_HW_P9813)
      #undef USE_WS2812_CTYPE
      #define USE_WS2812_CTYPE     NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
    
    #define USE_I2C             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    #ifdef USE_I2C
      // -- LCD I2C -----------------------
      //#define USE_DISPLAY         // Add I2C/TM1637/MAX7219 Display Support (+2k code)
      //#define USE_DISPLAY_SSD1306 // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
      //#define USE_DISPLAY_SH1106  // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
      //#define USE_GRAPH           // Enable line charts with displays
      //#define NUM_GRAPHS 4        // Max 16

      // -- I2C sensors ---------------------------------
      #define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
      #define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
      #define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

      // Cf. url: https://tasmota.github.io/docs/MCP230xx/
      // Vérifier activation du driver : I2cDriver22 1
      // Tester l'adresse du module MCP23XXX (adresse comprise entre 0x20 & 0x26) : I2CScan
      // Les paramètres des I/O est realisé dans le fichier mcp23xx.dat
      // Paramètres Mode 2 MCP23017
      #define USE_MCP23XXX_DRV

      // Paramètres Mode 1 MCP23017 (mode lancé si echec activation mode 2)
      #ifdef USE_MCP23XXX_DRV
        #define USE_MCP230xx                            // [I2cDriver22] Enable MCP23008/MCP23017 - Must define I2C Address in #define USE_MCP230xx_ADDR below - range 0x20 - 0x27 (+5k1 code)
        #define USE_MCP230xx_ADDR 0x20                  // Enable MCP23008/MCP23017 I2C Address to use (Must be within range 0x20 through 0x26 - set according to your wired setup)
        #define USE_MCP230xx_OUTPUT                     // Enable MCP23008/MCP23017 OUTPUT support through sensor29 commands (+2k2 code)
        #define USE_MCP230xx_DISPLAYOUTPUT              // Enable MCP23008/MCP23017 to display state of OUTPUT pins on Web UI (+0k2 code)
      #endif
    #endif

    // -- SPI sensors ---------------------------------
    #define USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
      //#define USE_ILI9488                            // Utilisation de l'ecran ILI9488. Les autres paramètres pour ILI9488 sont gérés par la partie 'Post-process compile options' en fin de fichier

    // -- One wire sensors ----------------------------
    #undef USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

    // -- Other sensors/drivers -----------------------
    #define USE_FLOWRATEMETER                        // Add support for water flow meter YF-DN50 and similary (+1k7 code)
    #ifdef USE_FLOWRATEMETER
      //#define D_JSON_FLOWRATEMETER                 "debitmetre" 
    #endif

    //#define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)

    // -- Other sensors/drivers -----------------------
    // GPIO12: 74x595 RClk / GPIO13: 74x595 SRClk / GPIO14: 74x595 Ser
    // Pour utiliser plusieurs 74x595, connecter :
    // - all SRCLK together to GPIO srclk
    // - all RCLK together to GPIO rclk
    // - GPIO ser to SER input of first 74x595
    // - QH' output of first 74x595 to SER input of 2nd 74x595 and so on
    //#define USE_SHIFT595                                // Add support for 74xx595 8-bit shift registers (+0k7 code)
    #ifdef USE_SHIFT595
      #define SHIFT595_INVERT_OUTPUTS false             // [SetOption133] Don't invert outputs of 74x595 shift register
      #define SHIFT595_DEVICE_COUNT  1                  // [Shift595DeviceCount] Set the number of connected 74x595 shift registers
    #endif

    // Cf. url: https://templates.blakadder.com/dingtian_DT-R008.html
    //#define USE_DINGTIAN
    #ifdef USE_DINGTIAN
      #define USE_DINGTIAN_RELAY                       // Add support for the Dingian board using 74'595 et 74'165 shift registers
      #define DINGTIAN_INPUTS_INVERTED               // Invert input states (Hi => OFF, Low => ON)
      #define DINGTIAN_USE_AS_BUTTON                 // Inputs as Tasmota's virtual Buttons
      #define DINGTIAN_USE_AS_SWITCH                 // Inputs as Tasmota's virtual Switches
    #endif

    // -- Rules or Script  ----------------------------
    // Select none or only one of the below defines USE_RULES or USE_SCRIPT
    #define USE_RULES                                // Add support for rules (+8k code)
    #ifdef USE_RULES
      #define SUPPORT_MQTT_EVENT                      // Support trigger event with MQTT subscriptions (+1k8 code)
      #define USE_EXPRESSION                          // Add support for expression evaluation in rules (+1k7 code)
        #define SUPPORT_IF_STATEMENT                  // Add support for IF statement in rules (+2k7)
        #define USER_RULE1 ""                         // Add rule1 data saved at initial firmware load or when command reset is executed
        #define USER_RULE2 ""                         // Add rule2 data saved at initial firmware load or when command reset is executed
        #define USER_RULE3 ""                         // Add rule3 data saved at initial firmware load or when command reset is executed
    #endif
    #undef USER_BACKLOG
      //#define USER_BACKLOG "Backlog Module 0; Hostname SERVEUR-DEBITMETRES-PAC; Sensor96 1 3500; Sensor96 2 3500;"
      #define USER_BACKLOG "Backlog Module 0; Hostname DEBITMETRES-PAC-1;"
  #endif

  /*********************************************************************************************\
   * Mutual exclude options
  \*********************************************************************************************/

  #if defined(ESP8266) && defined(USE_DISCOVERY) && (defined(USE_MQTT_AWS_IOT) || defined(USE_MQTT_AWS_IOT_LIGHT))
    #error "Select either USE_DISCOVERY or USE_MQTT_AWS_IOT, mDNS takes too much code space and is not needed for AWS IoT"
  #endif

  #if defined(USE_RULES) && defined(USE_SCRIPT)
    #error "Select either USE_RULES or USE_SCRIPT. They can't both be used at the same time"
  #endif

  /*********************************************************************************************\
   * Post-process compile options for Autoconf and others
  \*********************************************************************************************/
  //Paramètres RangeExtender
  #ifdef USE_WIFI_RANGE_EXTENDER
    #define USE_WIFI_RANGE_EXTENDER_NAPT
    #define USE_WIFI_RANGE_EXTENDER_CLIENTS
    #ifndef WIFI_RGX_SSID
      #define WIFI_RGX_SSID           "RANGE-EXTENDER-AP"
    #endif
    #ifndef WIFI_RGX_PASSWORD
      #define WIFI_RGX_PASSWORD       "Lune5676"
    #endif
    #define WIFI_RGX_IP_ADDRESS     "10.99.0.1"
    #define WIFI_RGX_SUBNETMASK     "255.255.255.0"
    #define WIFI_RGX_STATE          1
    #define WIFI_RGX_NAPT           1
  #endif

  // Si utilisation de l'ecran ILI9488
  #ifdef USE_ILI9488
    // Active SPI si ce n'est pas fait
    #ifndef USE_SPI
      #define USE_SPI
    #endif
    #define USE_LVGL
    #define USE_DISPLAY                            // Add SPI Display support for 320x240 and 480x320 TFT
    #define USE_DISPLAY_LVGL_ONLY
    #define USE_UNIVERSAL_DISPLAY
    #define USE_DISPLAY_ILI9488
    #define MAX_TOUCH_BUTTONS 16                 // Virtual touch buttons
    #define SHOW_SPLASH
        
    #define USE_XPT2046

    #undef USE_DISPLAY_MODES1TO5
    #undef USE_DISPLAY_LCD
    #undef USE_DISPLAY_SSD1306
    #undef USE_DISPLAY_MATRIX
    #undef USE_DISPLAY_SEVENSEG
  #endif

  // Paramètres de la gestion de fichiers
  #ifdef USE_SPI
    #define USE_UFILESYS
    #define GUI_EDIT_FILE
    #define GUI_TRASH_FILE
  #endif

  #if defined(USE_AUTOCONF)
    #ifndef USE_BERRY
      #define USE_BERRY
    #endif
    #ifndef USE_WEBCLIENT_HTTPS
      #define USE_WEBCLIENT_HTTPS
    #endif
    #ifndef USE_MQTT_TLS
      #define USE_MQTT_TLS
    #endif
  #endif // USE_AUTOCONF

  #ifdef USE_SONOFF_SPM
    #define USE_ETHERNET
  #endif
#endif  // _USER_CONFIG_OVERRIDE_H_