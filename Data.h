
//------------------------------------------------------------
#include    <U8g2lib.h>

//------------------------------------------------------------
//      MACROs
//------------------------------------------------------------
#define     MAX_Page_Number_CFG 7                           // Max Page Number for Configration
#define     MAX_PAGE_NUMBER_RUN 6                           // Max Page Number for Running
#define     MAX_PAGE_NUMBER_SET 2                           // Max Page Number for Setting

#define     KEY_DEBOUNCE_STD    25                          // Key Push Debounce Time : Standard    in " ms "
#define     KEY_DEBOUNCE_LONG   350                         // Key Push Debounce Time : Long Time   in " ms "

#define     QUE_INS_INTERVAL    500                         // SCI Instruction 'Qx' Send Interval in " ms "

#define     CFG_INS_TIMES       5                           // SCI Instruction 'Sx' Send Times
#define     SET_INS_TIMES       5                           // SCI Instruction 'Sx' Send Times

#define     FONT_CHARACTER      u8g2_font_t0_15b_mf         // Font : 10 Pixel Height, English, Bold
//#define     FONT_CHARACTER      u8g2_font_t0_15_tf        // Font : 10 Pixel Height, English, Fine
#define     FONT_SYMBOL         u8g2_font_unifont_t_symbols // Font : All Symbols

//------------------------------------------------------------
//      System
//------------------------------------------------------------
extern  int     time_H;
extern  int     time_M;
extern  int     time_S;

//------------------------------------------------------------
//      WiFi
//------------------------------------------------------------
extern  const char* ssid;
extern  const char* password;

//------------------------------------------------------------
//      GPIO
//------------------------------------------------------------
extern  int     key_pg;
extern  int     key_ln;
extern  int     key_up;
extern  int     key_dw;

//------------------------------------------------------------
//      Key State
//------------------------------------------------------------
extern  int     key_pg_state;                   // Key_Pg   State
extern  int     key_pg_last_state;              // Key_Pg   Last State
extern  long    key_pg_last_debounce;           // Key_Pg   Last State Change Time

extern  int     key_ln_state;
extern  int     key_ln_last_state;
extern  long    key_ln_last_debounce;

extern  int     key_up_state;
extern  int     key_up_last_state;
extern  long    key_up_last_debounce;

extern  int     key_dw_state;
extern  int     key_dw_last_state;
extern  long    key_dw_last_debounce;

//------------------------------------------------------------
//      OLED
//------------------------------------------------------------
//extern  U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2;     // page buffer, size = 128 bytes, For 0.96 Inch
extern  U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2;        // page buffer, size = 128 bytes, For 1.30 Inch

//------------------------------------------------------------
//      Data for Display
//------------------------------------------------------------
extern  int     Cfg_Changed;
extern  int     Set_Changed;

extern  int     Work_Mode;

extern  int     Page_Number_Cfg;
extern  int     Page_Number_Run;
extern  int     Page_Number_Set;

extern  int     Line_number;

//------------------------------------------------------------
//      Data for Configration
//------------------------------------------------------------
extern  int     Bias_Uab;
extern  int     Bias_Ubc;
extern  int     Bias_Uca;

extern  int     Ratio_Uab;
extern  int     Ratio_Ubc;
extern  int     Ratio_Uca;

extern  int     Bias_Iab;
extern  int     Bias_Ibc;
extern  int     Bias_Ica;

extern  int     Ratio_Iab;
extern  int     Ratio_Ibc;
extern  int     Ratio_Ica;

extern  int     Vdc_Slope;
extern  float   Vdc_Apart;

extern  int     Idc_Slope;
extern  float   Idc_Apart;

//------------------------------------------------------------
//      Data for Query
//------------------------------------------------------------
extern  float   Uac_ab;
extern  float   Uac_bc;
extern  float   Uac_ca;

extern  float   Fac_ab;
extern  float   Fac_bc;
extern  float   Fac_ca;

extern  float   Iac_ab;
extern  float   Iac_bc;
extern  float   Iac_ca;

extern  float   Udc_out;
extern  float   Idc_out;

extern  int     DutyCycle;

//------------------------------------------------------------
extern  int     F_Cap_A;
extern  int     F_Cap_B;
extern  int     F_Cap_C;

//------------------------------------------------------------
//      Data for Set
//------------------------------------------------------------
extern  float   Set_Udc_out;
extern  float   Set_Idc_Lmt;

extern  int     Set_Uac_H;
extern  int     Set_Uac_L;

extern  int     Set_Fac_H;
extern  int     Set_Fac_L;

//------------------------------------------------------------
//      UART Control
//------------------------------------------------------------
extern  int     Send_LastTime;

extern  int     Number_Query;
extern  int     Number_Config;
extern  int     Number_Setting;

extern  String  Ans_String;
extern  char    Ans_char[];
