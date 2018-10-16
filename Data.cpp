
#include    <U8g2lib.h>

//------------------------------------------------------------
//      System
//------------------------------------------------------------
int     time_H = 15;                    // Working Time
int     time_M = 30;
int     time_S = 35;

//------------------------------------------------------------
//      GPIO
//------------------------------------------------------------
int     key_pg = 16;                    // Key : Page
int     key_ln = 14;                    // Key : Line
int     key_up = 12;                    // Key : Data Change Up
int     key_dw = 13;                    // Key : Data Change Down

//------------------------------------------------------------
//      Key State
//------------------------------------------------------------
int     key_pg_state;                   // Key_Pg   State
int     key_pg_last_state = 0;          // Key_Pg   Last State
long    key_pg_last_debounce;           // Key_Pg   Last State Change Time

int     key_ln_state;                   // Key_Line State
int     key_ln_last_state = 0;
long    key_ln_last_debounce;

int     key_up_state;                   // Key_Up
int     key_up_last_state = 0;
long    key_up_last_debounce;

int     key_dw_state;                   // Key_Down
int     key_dw_last_state = 0;
long    key_dw_last_debounce;

//------------------------------------------------------------
//      OLED
//------------------------------------------------------------
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0);        // page buffer, size = 128 bytes, For 0.96 Inch
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0);           // page buffer, size = 128 bytes, For 1.30 Inch

//------------------------------------------------------------
//      Data for Display
//------------------------------------------------------------
int     Data_Changed = 0;               // Data Has Been Changed -> Setup Instruction Send Times

int     Work_Mode = 0;                  // Work Mode Select :  0-> Welcome    1-> Config    2-> Querry    3-> Set

int     Page_Number_Cfg = 1;            // Start Page
int     Page_Number_Run = 1;
int     Page_Number_Set = 1;

int     Line_number = 2;                // Default Line in Work Mode Select ( Query Mode as Default )

//------------------------------------------------------------
//      Data for Configration
//------------------------------------------------------------
int     Bias_Uab = 2048;                // Uac: Bias
int     Bias_Ubc = 2049;                //
int     Bias_Uca = 2050;                //

int     Ratio_Uab = 3350;               // Uac: Ratio
int     Ratio_Ubc = 3351;
int     Ratio_Uca = 3352;

int     Bias_Iab = 2048;                // Iac: Bias
int     Bias_Ibc = 2049;
int     Bias_Ica = 2050;

int     Ratio_Iab = 3150;               // Iac: Ratio
int     Ratio_Ibc = 3151;
int     Ratio_Ica = 3152;

int     Vdc_Slope = 4940;               // Udc: Slope + Apart
float   Vdc_Apart = 207.52;

int     Idc_Slope = 2346;               // Idc: Slope + Apart
float   Idc_Apart = 307.52;

//------------------------------------------------------------
//      Data for Query
//------------------------------------------------------------
float   Uac_ab = 220.1;
float   Uac_bc = 220.2;
float   Uac_ca = 220.3;

float   Fac_ab = 50.4;
float   Fac_bc = 50.5;
float   Fac_ca = 50.6;

float   Iac_ab = 12.7;
float   Iac_bc = 12.8;
float   Iac_ca = 12.9;

float   Udc_out = 512.1;
float   Idc_out = 32.2;

int     DutyCycle = 55;                 // DutyCycle of PWM

//------------------------------------------------------------
int     F_Cap_A = 0;
int     F_Cap_B = 0;
int     F_Cap_C = 0;

//------------------------------------------------------------
//      Data for Set
//------------------------------------------------------------
float   Set_Udc_out = 520.0;
float   Set_Idc_Lmt = 50.0;

int     Set_Uac_H = 494;
int     Set_Uac_L = 200;

int     Set_Fac_H = 55;
int     Set_Fac_L = 45;

//------------------------------------------------------------
//      UART Control
//------------------------------------------------------------
int     Send_LastTime = 0;

int     Number_Query = 1;
int     Number_Setup = 1;

String  Ans_String = "";
char    Ans_char[20];
