
//------------------------------------------------------------
#include    "Data.h"
#include    "Screen.h"

//------------------------------------------------------------
//  the Calling Function
//------------------------------------------------------------
void draw() {

    u8g2.clearBuffer();
    switch( Work_Mode ) {
        case 0: draw_page_welcome();                        // Welcome Mode
                break;
        case 1: switch( Page_Number_Cfg )   {               // Config Mode
                    case 1: draw_page_cfg_1();  break;
                    case 2: draw_page_cfg_2();  break;
                    case 3: draw_page_cfg_3();  break;
                    case 4: draw_page_cfg_4();  break;
                    case 5: draw_page_cfg_5();  break;
                    case 6: draw_page_cfg_6();  break;
                    case 7: draw_page_cfg_7();  break;
                }
                break;
        case 2: switch( Page_Number_Run )   {               // Query Mode
                    case 1: draw_page_run_1();  break;
                    case 2: draw_page_run_2();  break;
                    case 3: draw_page_run_3();  break;
                    case 4: draw_page_run_4();  break;
                    case 5: draw_page_run_5();  break;
                    case 6: draw_page_run_6();  break;
                }
                break;
        case 3: switch( Page_Number_Set )   {               // Setup Mode
                    case 1: draw_page_set_1();  break;
                    case 2: draw_page_set_2();  break;
                }
                break;
    }
    u8g2.sendBuffer();
}

//------------------------------------------------------------
//  the Welcome Screen
//------------------------------------------------------------
void draw_page_welcome() {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);                   // Background Color : Enable
    u8g2.print("Select Work Mode");         // the Title
    u8g2.setDrawColor(1);                   // Background Color : Disable

    u8g2.setCursor(42, 30);
    u8g2.print("Config");

    u8g2.setCursor(46, 45);
    u8g2.print("Query");

    u8g2.setCursor(52, 60);
    u8g2.print("Set");

    switch( Line_number )   {
        case 1: u8g2.drawHLine(42,32,48); break;
        case 2: u8g2.drawHLine(46,47,40); break;
        case 3: u8g2.drawHLine(52,62,24); break;
    }
}

//------------------------------------------------------------
//  the Config Screen
//------------------------------------------------------------
void draw_page_cfg_1() {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-1 AC Voltage");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(4, 30);
    u8g2.print("Bias Uab : ");
    u8g2.print(Bias_Uab);

    u8g2.setCursor(4, 45);
    u8g2.print("Bias Ubc : ");
    u8g2.print(Bias_Ubc);

    u8g2.setCursor(4, 60);
    u8g2.print("Bias Uca : ");
    u8g2.print(Bias_Uca);

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(91,32,33); break;
        case 2: u8g2.drawHLine(91,47,33); break;
        case 3: u8g2.drawHLine(91,62,33); break;
    }
}

void draw_page_cfg_2() {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-2 AC Voltage");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(0, 30);
    u8g2.print("Ratio AB :0.");
    u8g2.print(Ratio_Uab);

    u8g2.setCursor(0, 45);
    u8g2.print("Ratio BC :0.");
    u8g2.print(Ratio_Ubc);

    u8g2.setCursor(0, 60);
    u8g2.print("Ratio CA :0.");
    u8g2.print(Ratio_Uca);

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(80,32,47); break;
        case 2: u8g2.drawHLine(80,47,47); break;
        case 3: u8g2.drawHLine(80,62,47); break;
    }
}

void draw_page_cfg_3() {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-3 AC Current");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(4, 30);
    u8g2.print("Bias Iab : ");
    u8g2.print(Bias_Iab);

    u8g2.setCursor(4, 45);
    u8g2.print("Bias Ibc : ");
    u8g2.print(Bias_Ibc);

    u8g2.setCursor(4, 60);
    u8g2.print("Bias Ica : ");
    u8g2.print(Bias_Ica);

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(91,32,33); break;
        case 2: u8g2.drawHLine(91,47,33); break;
        case 3: u8g2.drawHLine(91,62,33); break;
    }
}

void draw_page_cfg_4() {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-4 AC Current");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(0, 30);
    u8g2.print("Ratio AB :0.");
    u8g2.print(Ratio_Iab);

    u8g2.setCursor(0, 45);
    u8g2.print("Ratio BC :0.");
    u8g2.print(Ratio_Ibc);

    u8g2.setCursor(0, 60);
    u8g2.print("Ratio CA :0.");
    u8g2.print(Ratio_Ica);

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(80,32,47); break;
        case 2: u8g2.drawHLine(80,47,47); break;
        case 3: u8g2.drawHLine(80,62,47); break;
    }
}

void draw_page_cfg_5() {

    long    tmp_i1;
    long    tmp_i2;

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-5 DC Voltage");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(8, 36);
    u8g2.print("Slope : 0.");
    u8g2.print(Vdc_Slope);

    tmp_i1 = long( Vdc_Apart );
    tmp_i2 = long( Vdc_Apart*100 - tmp_i1*100 );

    u8g2.setCursor(8, 52);
    u8g2.print("Apart : ");
    u8g2.print( tmp_i1 );
    u8g2.print(".");
    u8g2.print( tmp_i2 );

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(73,38,47); break;
        case 2: u8g2.drawHLine(73,54,47); break;
    }
}

void draw_page_cfg_6() {

    long    tmp_i1;
    long    tmp_i2;

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Cfg-6 DC Current");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(8, 36);
    u8g2.print("Slope : 0.");
    u8g2.print(Idc_Slope);

    tmp_i1 = long( Idc_Apart );
    tmp_i2 = long( Idc_Apart*100 - tmp_i1*100 );

    u8g2.setCursor(8, 52);
    u8g2.print("Apart : ");
    u8g2.print( tmp_i1 );
    u8g2.print(".");
    u8g2.print( tmp_i2 );

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(73,38,47); break;
        case 2: u8g2.drawHLine(73,54,47); break;
    }
}

void draw_page_cfg_7()  {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Save All Configs");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(8, 36);
    u8g2.print("Save : Push ");

    u8g2.setFont(FONT_SYMBOL);              // Change Font for Symbols
    u8g2.drawGlyph(108, 36, 0x21e7);        // the Output Code for the Symbol

    u8g2.setFont(FONT_CHARACTER);           // Change Font Back for Character
    u8g2.setCursor(8, 52);
    u8g2.print("Quit : Push No");

    switch( Line_number )   {
        case 1: u8g2.drawHLine(109,38,7); break;
        case 2: u8g2.drawHLine(103,54,17); break;
    }
}

//------------------------------------------------------------
//  the Running Screen
//------------------------------------------------------------
void draw_page_run_1()  {

    int     tmp_i1;
    int     tmp_i2;

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("   AC Voltage   ");     // the Title
    u8g2.setDrawColor(1);

    tmp_i1 = int( Uac_ab );
    tmp_i2 = int( Uac_ab*10 - tmp_i1*10 );

    u8g2.setCursor(24, 30);
    u8g2.print("Uab: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Uac_bc );
    tmp_i2 = int( Uac_bc*10 - tmp_i1*10 );

    u8g2.setCursor(24, 45);
    u8g2.print("Ubc: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Uac_ca );
    tmp_i2 = int( Uac_ca*10 - tmp_i1*10 );

    u8g2.setCursor(24, 60);
    u8g2.print("Uca: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);
}

void draw_page_run_2()  {

    int     tmp_i1;
    int     tmp_i2;

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("  AC Frequency  ");     // the Title
    u8g2.setDrawColor(1);

    tmp_i1 = int( Fac_ab );
    tmp_i2 = int( Fac_ab*10 - tmp_i1*10 );

    u8g2.setCursor(26, 30);
    u8g2.print("Fab: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Fac_bc );
    tmp_i2 = int( Fac_bc*10 - tmp_i1*10 );

    u8g2.setCursor(26, 45);
    u8g2.print("Fbc: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Fac_ca );
    tmp_i2 = int( Fac_ca*10 - tmp_i1*10 );

    u8g2.setCursor(26, 60);
    u8g2.print("Fca: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);
}

void draw_page_run_3()  {

    int     tmp_i1;
    int     tmp_i2;

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("   AC Current   ");     // the Title
    u8g2.setDrawColor(1);

    tmp_i1 = int( Iac_ab );
    tmp_i2 = int( Iac_ab*10 - tmp_i1*10 );

    u8g2.setCursor(26, 30);
    u8g2.print("Iab: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Iac_bc );
    tmp_i2 = int( Iac_bc*10 - tmp_i1*10 );

    u8g2.setCursor(26, 45);
    u8g2.print("Ibc: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Iac_ca );
    tmp_i2 = int( Iac_ca*10 - tmp_i1*10 );

    u8g2.setCursor(26, 60);
    u8g2.print("Ica: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);
}

void draw_page_run_4()  {

    int     tmp_i1;
    int     tmp_i2;

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("  DC Parameter  ");     // the Title
    u8g2.setDrawColor(1);

    tmp_i1 = int( Udc_out );
    tmp_i2 = int( Udc_out*10 - tmp_i1*10 );

    u8g2.setCursor(26, 36);
    u8g2.print("Udc: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Idc_out );
    tmp_i2 = int( Idc_out*10 - tmp_i1*10 );

    u8g2.setCursor(26, 52);
    u8g2.print("Idc: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);
}

void draw_page_run_5()  {

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print(" Working Status ");     // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(20, 36);
    u8g2.print("Time: ");
    u8g2.print(time_H);
    u8g2.print(":");
    u8g2.print(time_M);

    u8g2.setCursor(20, 52);
    u8g2.print("Duty: ");
    u8g2.print(DutyCycle);
    u8g2.print(" %");
}

void draw_page_run_6()  {

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("   Error Code   ");     // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(20, 30);
    u8g2.print("F_Cap_A: ");
    u8g2.print(F_Cap_A);

    u8g2.setCursor(20, 45);
    u8g2.print("F_Cap_B: ");
    u8g2.print(F_Cap_B);

    u8g2.setCursor(20, 60);
    u8g2.print("F_Cap_C: ");
    u8g2.print(F_Cap_C);
}

//------------------------------------------------------------
//  the Setup Screen
//------------------------------------------------------------
void draw_page_set_1()  {

    int     tmp_i1;
    int     tmp_i2;

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Set DC Parameter");         // the Title
    u8g2.setDrawColor(1);

    tmp_i1 = int( Set_Udc_out );
    tmp_i2 = int( Set_Udc_out*10 - tmp_i1*10 );

    u8g2.setCursor(5, 36);
    u8g2.print("Vout Set: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    tmp_i1 = int( Set_Idc_Lmt );
    tmp_i2 = int( Set_Idc_Lmt*10 - tmp_i1*10 );

    u8g2.setCursor(5, 52);
    u8g2.print("Iout Lmt: ");
    u8g2.print(tmp_i1);
    u8g2.print(".");
    u8g2.print(tmp_i2);

    switch( Line_number )    {              // Current Line
        case 1: u8g2.drawHLine(85,38,40); break;
        case 2: u8g2.drawHLine(85,54,32); break;
    }
}

void draw_page_set_2()  {

    u8g2.setFont(FONT_CHARACTER);

    u8g2.setCursor(0, 15);
    u8g2.setDrawColor(0);
    u8g2.print("Set AC Parameter");         // the Title
    u8g2.setDrawColor(1);

    u8g2.setCursor(5, 36);
    u8g2.print("Vac: ");

    u8g2.setCursor(45, 36);
    u8g2.print(Set_Uac_L);
    u8g2.setCursor(75, 36);
    u8g2.print("->");
    u8g2.setCursor(97, 36);
    u8g2.print(Set_Uac_H);

    u8g2.setCursor(5, 52);
    u8g2.print("Fac: ");

    u8g2.setCursor(53, 52);
    u8g2.print(Set_Fac_L);
    u8g2.setCursor(75, 52);
    u8g2.print("->");
    u8g2.setCursor(97, 52);
    u8g2.print(Set_Fac_H);

    switch( Line_number )   {
        case 1: u8g2.drawHLine(45,38,24); break;
        case 2: u8g2.drawHLine(97,38,24); break;
        case 3: u8g2.drawHLine(53,54,16); break;
        case 4: u8g2.drawHLine(97,54,16); break;
    }
}
