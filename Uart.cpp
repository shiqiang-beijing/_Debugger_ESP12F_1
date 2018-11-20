
//------------------------------------------------------------
#include    "Data.h"
#include    "Uart.h"

//------------------------------------------------------------
// Send Out the Query Instructions
//------------------------------------------------------------
void Cmd_Send_Query(void) {                         // the Function Serial.println() Terminate with : '\r'+'\n'
    switch( Number_Query )    {                     // 'r' : ASCII Code -> 13   Return
        //-----------------------------------       // 'n' : ASCII Code -> 10   Change Line
        //      Query Internal Parameters
        //-----------------------------------
        case 1: Serial.println("Q01");              // Bias of Uab/Ubc/Uca
                Number_Query += 1;
                break;
        case 2: Serial.println("Q02");              // Ratio of Uab/Ubc/Uca
                Number_Query += 1;
                break;
        case 3: Serial.println("Q03");              // Bias of Iab/Ibc/Ica
                Number_Query += 1;
                break;
        case 4: Serial.println("Q04");              // Ratio of Iab/Ibc/Ica
                Number_Query += 1;
                break;
        case 5: Serial.println("Q05");              // Slope && Apart of Udc
                Number_Query += 1;
                break;
        case 6: Serial.println("Q06");              // Slope && Apart of Idc
                Number_Query += 1;
                break;
        //-----------------------------------
        //      Query External Parameters
        //-----------------------------------
        case 7: Serial.println("Q07");              // Uab Ubc Uca
                Number_Query += 1;
                break;
        case 8: Serial.println("Q08");              // Fab Fbc Fca
                Number_Query += 1;
                break;
        case 9: Serial.println("Q09");              // Iab Ibc Ica
                Number_Query += 1;
                break;
        case 10:Serial.println("Q10");              // Udc Idc
                Number_Query += 1;
                break;
        case 11:Serial.println("Q11");              // Time DutyCycle
                Number_Query += 1;
                break;
        case 12:Serial.println("Q12");              // F_Cap_A F_Cap_B F_Cap_C
                Number_Query = 1;
                break;
    }
}

//------------------------------------------------------------
// Send Out the Config Instructions
//------------------------------------------------------------
void Cmd_Send_Config(void) {
    long    tmp_data;
    switch( Number_Config )    {
        case 1: Serial.print("S1");                 // the Serial.println() Terminator is : '\r'+'\n'
                Serial.print(Bias_Uab);             // 'r' : ASCII Code -> 13   Return
                Serial.print(Bias_Ubc);             // 'n' : ASCII Code -> 10   Change Line
                Serial.println(Bias_Uca);
                Number_Config += 1;
                break;
        case 2: Serial.print("S2");
                Serial.print(Ratio_Uab);
                Serial.print(Ratio_Ubc);
                Serial.println(Ratio_Uca);
                Number_Config += 1;
                break;
        case 3: Serial.print("S3");
                Serial.print(Bias_Iab);
                Serial.print(Bias_Ibc);
                Serial.println(Bias_Ica);
                Number_Config += 1;
                break;
        case 4: Serial.print("S4");
                Serial.print(Ratio_Iab);
                Serial.print(Ratio_Ibc);
                Serial.println(Ratio_Ica);
                Number_Config += 1;
                break;
        case 5: tmp_data = Vdc_Apart * 100;
                Serial.print("S5");
                Serial.print(Vdc_Slope);
                //Serial.println(Vdc_Apart);
                Serial.println(tmp_data);
                Number_Config += 1;
                break;
        case 6: tmp_data = Idc_Apart * 100;
                Serial.print("S6");
                Serial.print(Idc_Slope);
                //Serial.println(Idc_Apart);
                Serial.println(tmp_data);
                Number_Config = 1;                   // All Setup Instruction Send !
                Cfg_Changed -= 1;                   // the Setup Instruction Send Times Changed
                break;
    }
}

//------------------------------------------------------------
// Send Out the Setting Instructions
//------------------------------------------------------------
void Cmd_Send_Setting(void) {

    switch( Number_Setting ) {
        case 1: Serial.print("S10");
                break;
        case 2: Serial.print("S11");
                break;
        case 3: Serial.print("S12");
                break;
    }
}

//------------------------------------------------------------
// Received Answer for Querry Instructions
//------------------------------------------------------------

// 'r' : ASCII Code -> 13   Return
// 'n' : ASCII Code -> 10   Change Line

// '0' : ASCII Code -> 48
// ......
// '9' : ASCII Code -> 57

// 'A' : ASCII Code -> 65   ( Uppercase Letter )
// ......
// 'Z' : ASCII Code -> 90   ( Uppercase Letter )

// 'a' : ASCII Code -> 97   ( Lowercase Letter )
// ......
// 'z' : ASCII Code -> 122  ( Lowercase Letter )

//------------------------------------------------------------
// Data Format:
// Q1 -> Q1+(4 Bit Integer)+(4 Bit Integer)+(4 Bit Integer)
// Q2 -> the same as above
// Q3 -> the same as above
// Q4 -> the same as above
//------------------------------------------------------------

void Ans_Receive(void)  {

    int     decide;
    int     tmp_data1, tmp_data2, tmp_data3, tmp_data4;
    long    tmp_data0;
    float   tmp_ans;

    Ans_String.toCharArray(Ans_char,20);                    // Copy the Received Answers to Char Array

    if( Ans_char[0] == 'Q' )    {                           // the Answer for Querry Instruction Received

        if( Ans_char[1] != 48 ) {
            decide = ( Ans_char[1] - 48 ) * 10;
            decide = decide + ( Ans_char[2] - 48 );
        }
        else    {
            decide = Ans_char[2] - 48;
        }

        switch( decide )   {
            //-----------------------------------
            //      Query Internal Parameters
            //-----------------------------------
            case 1 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q01 : Q01_2047_2048_2049
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Uab = int(tmp_ans);
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Ubc = int(tmp_ans);
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Uca = int(tmp_ans);
                    break;
            case 2 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q02 : Q02_3349_3350_3351
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Uab = int(tmp_ans);
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Ubc = int(tmp_ans);
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Uca = int(tmp_ans);
                    break;
            case 3 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q03 : Q03_2047_2048_2049
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Iab = int(tmp_ans);
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Ibc = int(tmp_ans);
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Bias_Ica = int(tmp_ans);
                    break;
            case 4 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q04 : Q04_3150_3151_3152
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Iab = int(tmp_ans);
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Ibc = int(tmp_ans);
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Ratio_Ica = int(tmp_ans);
                    break;
            case 5 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q05 : Q05_4940_30751
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Vdc_Slope = int(tmp_ans);
                    tmp_data0 = (Ans_char[7]-48);
                    tmp_data1 = (Ans_char[8]-48);
                    tmp_data2 = (Ans_char[9]-48);
                    tmp_data3 = (Ans_char[10]-48);
                    tmp_data4 = (Ans_char[11]-48);
                    tmp_ans = tmp_data0*10000 + tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Vdc_Apart = tmp_ans / 100;
                    break;
            case 6 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q06 : Q06_2346_10754
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Idc_Slope = int(tmp_ans);
                    tmp_data0 = (Ans_char[7]-48);
                    tmp_data1 = (Ans_char[8]-48);
                    tmp_data2 = (Ans_char[9]-48);
                    tmp_data3 = (Ans_char[10]-48);
                    tmp_data4 = (Ans_char[11]-48);
                    tmp_ans = tmp_data0*10000 + tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Idc_Apart = tmp_ans / 100;
                    break;
            //-----------------------------------
            //      Query External Parameters
            //-----------------------------------
            case 7 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q07 : Q07_2201_2202_2203
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Uac_ab = tmp_ans / 10;
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Uac_bc = tmp_ans / 10;
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Uac_ca = tmp_ans / 10;
                    break;
            case 8 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q08 : Q08_0504_0505_0506
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Fac_ab = tmp_ans / 10;
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Fac_bc = tmp_ans / 10;
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Fac_ca = tmp_ans / 10;
                    break;
            case 9 :tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q09 : Q09_0127_0128_0129
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Iac_ab = tmp_ans / 10;
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Iac_bc = tmp_ans / 10;
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Iac_ca = tmp_ans / 10;
                    break;
            case 10:tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q10 : Q10_5121_0321
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Udc_out = tmp_ans / 10;
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    tmp_ans = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    Idc_out = tmp_ans / 10;
                    break;
            case 11:tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q11 : Q11_0121_0021_0030
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    time_H = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;     // Time: Hour
//                    tmp_data1 = (Ans_char[7]-48);
//                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    time_M = tmp_data3*10 + tmp_data4;                                      // Time: Minute
//                    tmp_data1 = (Ans_char[11]-48);
//                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    DutyCycle = tmp_data3*10 + tmp_data4;                                   // DutyCycle
                    break;
            case 12:tmp_data1 = (Ans_char[3]-48);           // Querry Instruction Q12 : Q12_0001_0001_0000
                    tmp_data2 = (Ans_char[4]-48);
                    tmp_data3 = (Ans_char[5]-48);
                    tmp_data4 = (Ans_char[6]-48);
                    F_Cap_A = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;    // F_Cap_A F_Cap_B F_Cap_C
                    tmp_data1 = (Ans_char[7]-48);
                    tmp_data2 = (Ans_char[8]-48);
                    tmp_data3 = (Ans_char[9]-48);
                    tmp_data4 = (Ans_char[10]-48);
                    F_Cap_B = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    tmp_data1 = (Ans_char[11]-48);
                    tmp_data2 = (Ans_char[12]-48);
                    tmp_data3 = (Ans_char[13]-48);
                    tmp_data4 = (Ans_char[14]-48);
                    F_Cap_C = tmp_data1*1000 + tmp_data2*100 + tmp_data3*10 + tmp_data4;
                    break;
        }
    }
//    Serial.println(Ans_String);
    Ans_String = "";
}
