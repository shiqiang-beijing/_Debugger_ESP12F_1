
//------------------------------------------------------------
//  Libraries
//------------------------------------------------------------
#include    <ESP8266WiFi.h>         // ESP8266 Community Library : https://www.esp8266.com/
#include    <U8g2lib.h>

//------------------------------------------------------------
//  Modules
//------------------------------------------------------------
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
//  Setup
//------------------------------------------------------------
void setup() {

    // ---------- Key ----------
    pinMode(key_pg, INPUT);
    pinMode(key_ln, INPUT);
    pinMode(key_up, INPUT);
    pinMode(key_dw, INPUT);

    // ---------- OLED ----------
    u8g2.begin();

    // ---------- Uart ----------
    Serial.begin(115200);                   // UART-0 : TX->GPIO-1,  RX->GPIO-3
//    Serial.swap();                        // UART-0 : TX->GPIO-15, RX->GPIO-13

//    Serial1.begin(115200);                // UART-1 : TX->GPIO-2
//    Serial1.setDebugOutput(true);         // UART_1 : Used as Debug Output, Don't use Serial1.begin() at this time.
}

//------------------------------------------------------------
//  Loop
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
    if( (millis()-Send_LastTime) > QUE_INS_INTERVAL )  {    // Send Instructions in Fixed Time Slots
        Send_LastTime = millis();
        if( Cfg_Changed != 0 ) {
            Cmd_Send_Config();                              // Send Instructions : Config ( S1 -> S6 )
        }
        else if( Set_Changed != 0 ) {

            Set_Changed = 0;

            Cmd_Send_Setting();                             // Send Instructions : Setting ( S10 -> S12 )
        }
        else    {
            Cmd_Send_Query();                               // Send Instructions : Querry ( Q01 -> Q12 )
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
