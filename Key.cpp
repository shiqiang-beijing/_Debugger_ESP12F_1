
#include    "Data.h"
#include    "Key.h"

//------------------------------------------------------------
void key_read() {                                               // Read 4 Keys in Order

    // ---------- Key : Page ----------
    //
    int key_pg_read = digitalRead(key_pg);                      // Key State Reading
    if( key_pg_read != key_pg_last_state ) {                    // Key State Changed ?
        key_pg_last_debounce = millis();                        // Record the Current Time
    }
    if( (millis() - key_pg_last_debounce) > KEY_DEBOUNCE_STD ) {// Beyond the Debounce Time ?
        if( key_pg_read != key_pg_state) {                      // Beyond the Debounce Time && New State Appear
            key_pg_state = key_pg_read;                         // Record New State
            if( key_pg_state == 1 ) {                           // Key Pressed Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: switch( Line_number )   {
                                case 1: Work_Mode = 1;  break;                  // Change to Mode : Config
                                case 2: Work_Mode = 2;  break;                  // Change to Mode : Query
                                case 3: Work_Mode = 3;  break;                  // Change to Mode : Query
                            }
                            break;
                    case 1: if( ++Page_Number_Cfg > MAX_Page_Number_CFG )   {   // Switch Pages in Mode : Config
                                Page_Number_Cfg = 1;
                            }
                            break;
                    case 2: if( ++Page_Number_Run > MAX_PAGE_NUMBER_RUN )   {   // Switch Pages in Mode : Query
                                Page_Number_Run = 1;
                            }
                            break;
                    case 3: if( ++Page_Number_Set > MAX_PAGE_NUMBER_SET )   {   // Switch Pages in Mode : Set
                                Page_Number_Set = 1;
                            }
                            break;
                }
                Line_number = 1;                                // Page Changed Line Return to the First Line
            }
        }
    }
    key_pg_last_state = key_pg_read;                            // Save the State

    // ---------- Key : Line ----------
    //
    int key_ln_read = digitalRead(key_ln);
    if( key_ln_read != key_ln_last_state ) {
        key_ln_last_debounce = millis();
    }
    if( (millis() - key_ln_last_debounce) > KEY_DEBOUNCE_STD ) {
        if( key_ln_read != key_ln_state) {                      // Beyond the Debounce Time && New State Appear
            key_ln_state = key_ln_read;
            if( key_ln_state == 1 ) {                           // Key Pressed Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: if( ++Line_number>3 )   Line_number = 1;    // Change Line in Welcom Screen
                            break;
                    case 1: switch( Page_Number_Cfg )   {               // Change Line in Mode : Config
                                case 1: if( ++Line_number>3 )   Line_number = 1;
                                        break;
                                case 2: if( ++Line_number>3 )   Line_number = 1;
                                        break;
                                case 3: if( ++Line_number>3 )   Line_number = 1;
                                        break;
                                case 4: if( ++Line_number>3 )   Line_number = 1;
                                        break;
                                case 5: if( ++Line_number>2 )   Line_number = 1;
                                        break;
                                case 6: if( ++Line_number>2 )   Line_number = 1;
                                        break;
                                case 7: if( ++Line_number>2 )   Line_number = 1;
                                        break;
                            }
                            break;
                    case 2: switch( Page_Number_Run )   {               // Change Line in Mode : Query

                            }
                            break;
                    case 3: switch( Page_Number_Set )   {               // Change Line in Mode : Set
                                case 1: if( ++Line_number>2 )   Line_number = 1;
                                        break;
                                case 2: if( ++Line_number>4 )   Line_number = 1;
                                        break;
                            }
                            break;
                }
            }
        }
    }
    key_ln_last_state = key_ln_read;                            // Save the State

    // ---------- Key : Up ----------
    //
    int key_up_read = digitalRead(key_up);                      // Key State Reading
    if( key_up_read != key_up_last_state ) {                    // Key State Changed ?
        key_up_last_debounce = millis();                        // Record the Current Time
    }
    if( (millis() - key_up_last_debounce) > KEY_DEBOUNCE_STD ) {
        if( key_up_read != key_up_state) {                      // Beyond the Debounce Time && New State Appear
            key_up_state = key_up_read;
            if( key_up_state == 1 ) {                           // Key Pressed Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: break;                                          // Mode : Welcom Screen
                    case 1: Cfg_Changed = CFG_INS_TIMES;
                            switch( Page_Number_Cfg )   {                   // Mode : Config
                                case 1: switch( Line_number )   {
                                            case 1: Bias_Uab += 1;  break;
                                            case 2: Bias_Ubc += 1;  break;
                                            case 3: Bias_Uca += 1;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Ratio_Uab += 1;  break;
                                            case 2: Ratio_Ubc += 1;  break;
                                            case 3: Ratio_Uca += 1;  break;
                                        }
                                        break;
                                case 3: switch( Line_number )   {
                                            case 1: Bias_Iab += 1;  break;
                                            case 2: Bias_Ibc += 1;  break;
                                            case 3: Bias_Ica += 1;  break;
                                        }
                                        break;
                                case 4: switch( Line_number )   {
                                            case 1: Ratio_Iab += 1;  break;
                                            case 2: Ratio_Ibc += 1;  break;
                                            case 3: Ratio_Ica += 1;  break;
                                        }
                                        break;
                                case 5: switch( Line_number )   {
                                            case 1: Vdc_Slope += 1;     break;
                                            case 2: Vdc_Apart += 0.01;  break;
                                        }
                                        break;
                                case 6: switch( Line_number )   {
                                            case 1: Idc_Slope += 1;     break;
                                            case 2: Idc_Apart += 0.01;  break;
                                        }
                                        break;
                            }
                            break;
                    case 2: switch( Page_Number_Run )   {                   // Mode : Query
                            }
                            break;
                    case 3: Set_Changed = SET_INS_TIMES;
                            switch( Page_Number_Set )   {                   // Mode : Set
                                case 1: switch( Line_number )   {
                                            case 1: Set_Udc_out += 0.1;  break;
                                            case 2: Set_Idc_Lmt += 0.1;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Set_Uac_L += 1; break;
                                            case 2: Set_Uac_H += 1; break;
                                            case 3: Set_Fac_L += 1; break;
                                            case 4: Set_Fac_H += 1; break;
                                        }
                                        break;
                            }
                            break;
                }
            }
        }
        if( (millis() - key_up_last_debounce) > KEY_DEBOUNCE_LONG )    {
            if( key_up_state == 1 ) {                           // Long-Time Key Press Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: break;                                          // Mode : Welcom Screen
                    case 1: Cfg_Changed = CFG_INS_TIMES;
                            switch( Page_Number_Cfg )   {                   // Mode : Configration
                                case 1: switch( Line_number )   {
                                            case 1: Bias_Uab += 10;  break;
                                            case 2: Bias_Ubc += 10;  break;
                                            case 3: Bias_Uca += 10;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Ratio_Uab += 10;  break;
                                            case 2: Ratio_Ubc += 10;  break;
                                            case 3: Ratio_Uca += 10;  break;
                                        }
                                        break;
                                case 3: switch( Line_number )   {
                                            case 1: Bias_Iab += 10;  break;
                                            case 2: Bias_Ibc += 10;  break;
                                            case 3: Bias_Ica += 10;  break;
                                        }
                                        break;
                                case 4: switch( Line_number )   {
                                            case 1: Ratio_Iab += 10;  break;
                                            case 2: Ratio_Ibc += 10;  break;
                                            case 3: Ratio_Ica += 10;  break;
                                        }
                                        break;
                                case 5: switch( Line_number )   {
                                            case 1: Vdc_Slope += 10;    break;
                                            case 2: Vdc_Apart += 0.1;   break;
                                        }
                                        break;
                                case 6: switch( Line_number )   {
                                            case 1: Idc_Slope += 10;    break;
                                            case 2: Idc_Apart += 0.1;   break;
                                        }
                                        break;
                            }
                            break;
                    case 2: switch( Page_Number_Run )   {                   // Mode : Query
                            }
                            break;
                    case 3: Set_Changed = SET_INS_TIMES;
                            switch( Page_Number_Set )   {                   // Mode : Set
                                case 1: switch( Line_number )   {
                                            case 1: Set_Udc_out += 1;   break;
                                            case 2: Set_Idc_Lmt += 1;   break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Set_Uac_L += 10;    break;
                                            case 2: Set_Uac_H += 10;    break;
                                            case 3: Set_Fac_L += 10;    break;
                                            case 4: Set_Fac_H += 10;    break;
                                        }
                                        break;
                            }
                            break;
                }
            }
        }
    }
    key_up_last_state = key_up_read;                            // Save the State

    // ---------- Key : Down ----------
    //
    int key_dw_read = digitalRead(key_dw);                      // Key State Reading
    if( key_dw_read != key_dw_last_state ) {                    // Key State Changed ?
        key_dw_last_debounce = millis();                        // Record the Current Time
    }
    if( (millis() - key_dw_last_debounce) > KEY_DEBOUNCE_STD ) {
        if( key_dw_read != key_dw_state) {                      // Beyond the Debounce Time && New State Appear
            key_dw_state = key_dw_read;
            if( key_dw_state == 1 ) {                           // Key Pressed Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: break;                                          // Mode : Welcom Screen
                    case 1: Cfg_Changed = CFG_INS_TIMES;
                            switch( Page_Number_Cfg )   {                   // Mode : Configration
                                case 1: switch( Line_number )   {
                                            case 1: Bias_Uab -= 1;  break;
                                            case 2: Bias_Ubc -= 1;  break;
                                            case 3: Bias_Uca -= 1;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Ratio_Uab -= 1;  break;
                                            case 2: Ratio_Ubc -= 1;  break;
                                            case 3: Ratio_Uca -= 1;  break;
                                        }
                                        break;
                                case 3: switch( Line_number )   {
                                            case 1: Bias_Iab -= 1;  break;
                                            case 2: Bias_Ibc -= 1;  break;
                                            case 3: Bias_Ica -= 1;  break;
                                        }
                                        break;
                                case 4: switch( Line_number )   {
                                            case 1: Ratio_Iab -= 1;  break;
                                            case 2: Ratio_Ibc -= 1;  break;
                                            case 3: Ratio_Ica -= 1;  break;
                                        }
                                        break;
                                case 5: switch( Line_number )   {
                                            case 1: Vdc_Slope -= 1;     break;
                                            case 2: Vdc_Apart -= 0.01;  break;
                                        }
                                        break;
                                case 6: switch( Line_number )   {
                                            case 1: Idc_Slope -= 1;     break;
                                            case 2: Idc_Apart -= 0.01;  break;
                                        }
                                        break;
                            }
                            break;
                    case 2: switch( Page_Number_Run )   {                   // Mode : Query
                            }
                            break;
                    case 3: Set_Changed = SET_INS_TIMES;
                            switch( Page_Number_Set )   {                   // Mode : Set
                                case 1: switch( Line_number )   {
                                            case 1: Set_Udc_out -= 0.1;  break;
                                            case 2: Set_Idc_Lmt -= 0.1;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Set_Uac_L -= 1; break;
                                            case 2: Set_Uac_H -= 1; break;
                                            case 3: Set_Fac_L -= 1; break;
                                            case 4: Set_Fac_H -= 1; break;
                                        }
                                        break;
                            }
                            break;
                }
            }
        }
        if( (millis() - key_dw_last_debounce) > KEY_DEBOUNCE_LONG )    {
            if( key_dw_state == 1 ) {                           // Long-Time Key Press Confirm ( the Useful Key State )
                switch( Work_Mode ) {
                    case 0: break;                                          // Mode : Welcom Screen
                    case 1: Cfg_Changed = CFG_INS_TIMES;
                            switch( Page_Number_Cfg )    {                  // Mode : Configration
                                case 1: switch( Line_number )   {
                                            case 1: Bias_Uab -= 10;  break;
                                            case 2: Bias_Ubc -= 10;  break;
                                            case 3: Bias_Uca -= 10;  break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Ratio_Uab -= 10;  break;
                                            case 2: Ratio_Ubc -= 10;  break;
                                            case 3: Ratio_Uca -= 10;  break;
                                        }
                                        break;
                                case 3: switch( Line_number )   {
                                            case 1: Bias_Iab -= 10;  break;
                                            case 2: Bias_Ibc -= 10;  break;
                                            case 3: Bias_Ica -= 10;  break;
                                        }
                                        break;
                                case 4: switch( Line_number )   {
                                            case 1: Ratio_Iab -= 10;  break;
                                            case 2: Ratio_Ibc -= 10;  break;
                                            case 3: Ratio_Ica -= 10;  break;
                                        }
                                        break;
                                case 5: switch( Line_number )   {
                                            case 1: Vdc_Slope -= 10;    break;
                                            case 2: Vdc_Apart -= 0.1;   break;
                                        }
                                        break;
                                case 6: switch( Line_number )   {
                                            case 1: Idc_Slope -= 10;    break;
                                            case 2: Idc_Apart -= 0.1;   break;
                                        }
                                        break;
                            }
                            break;
                    case 2: switch( Page_Number_Run )   {                   // Mode : Query
                            }
                            break;
                    case 3: Set_Changed = SET_INS_TIMES;
                            switch( Page_Number_Set )   {                   // Mode : Set
                                case 1: switch( Line_number )   {
                                            case 1: Set_Udc_out -= 1;   break;
                                            case 2: Set_Idc_Lmt -= 1;   break;
                                        }
                                        break;
                                case 2: switch( Line_number )   {
                                            case 1: Set_Uac_L -= 10;    break;
                                            case 2: Set_Uac_H -= 10;    break;
                                            case 3: Set_Fac_L -= 10;    break;
                                            case 4: Set_Fac_H -= 10;    break;
                                        }
                                        break;
                            }
                            break;
                }
            }
        }
    }
    key_dw_last_state = key_dw_read;                            // Save the State
}
