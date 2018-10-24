
#include    <ESP8266WiFi.h>
#include    <U8g2lib.h>

#include    "Data.h"

#include    "Screen.h"
#include    "Key.h"
#include    "Uart.h"

//------------------------------------------------------------
//  Compile parameters
//------------------------------------------------------------
//  Tools :         Arduino 1.8.5

//  Board :         ESPDuino(ESP-13 Module)
//  Flash Size :    4M(1M SPIFFS)
//  Debug port :    Disabled
//  Debug Level:    No
//  lwIP Variant:   v2 Lower Memory
//  Reset Method:   ESPduino-V2
//  VTables :       Flash
//  CPU Frequency:  80 Mhz
//  Upload Speed:   921600
//  Erase Flash:    Only Sketch

//------------------------------------------------------------
void setup() {
    pinMode(key_pg, INPUT);
    pinMode(key_ln, INPUT);
    pinMode(key_up, INPUT);
    pinMode(key_dw, INPUT);

    u8g2.begin();

    Serial.begin(115200);
}

//------------------------------------------------------------
void loop() {

    // ---------- OLED ----------

    u8g2.firstPage();
    do {
        draw();
    } while ( u8g2.nextPage() );

    // ---------- Key ----------

    key_read();

    // ---------- Uart ----------

    if( (millis()-Send_LastTime) > QUE_INS_INTERVAL )  {    // Send out Instructions at fixed time
        Send_LastTime = millis();
        if( Cfg_Changed != 0 ) {
            Cmd_Send_Config();                              // Instructions : Config
        }
        else if( Set_Changed != 0 ) {

            Set_Changed = 0;

            Cmd_Send_Setting();                             // Instructions : Setting
        }
        else    {
            Cmd_Send_Query();                               // Instructions : Querry
        }
    }

    while( Serial.available() )  {                          // Qureery Instructions : Received Answers
        char inChar = Serial.read();
        Ans_String += inChar;
//      delay(1);
    }
    if( Ans_String != "" )    {
        Ans_Receive();
    }
}
