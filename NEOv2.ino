  

/*
                                     ____   _____ __  __                     _
                                    / __ \ / ____|  \/  |                   | |
__      ____      ____      __     | |  | | (___ | \  / |       ___ ___   __| | ___  ___
\ \ /\ / /\ \ /\ / /\ \ /\ / /     | |  | |\___ \| |\/| |      / __/ _ \ / _` |/ _ \/ __|
 \ V  V /  \ V  V /  \ V  V /   _  | |__| |____) | |  | |  _  | (_| (_) | (_| |  __/\__ \
  \_/\_/    \_/\_/    \_/\_/   (_)  \____/|_____/|_|  |_| (_)  \___\___/ \__,_|\___||___/

57 65 20 68 61 76 65 20 61 6c 6c 20 74 68 65 20 6c 69 67 68 74 20 77 65 20 6e 65 65 64 2c 20 77 65 20 
6a 75 73 74 20 6e 65 65 64 20 74 6f 20 70 75 74 20 69 74 20 69 6e 20 70 72 61 63 74 69 63 65 2e 0d 0a
*****************************************************************************************************
* Credits: AAA_CREDITS.ino
* ♒ NEO ♒ for the Open Source Microlight
* Version: v2 Series
* Date: 09-30-2015
* Company: Quantum Hex LLC
* Author: Ramiro Montes De Oca
* Product Page: http://www.osm.codes
* Support: http://support.osm.codes
* Facebook Users Group: https://www.facebook.com/groups/osmModeSwap/
* Facebook Dev Group: https://www.facebook.com/groups/OSMdevelopers/
* Facebook Product Page: https://www.facebook.com/osmcodes
*
* This Software is licensed under Creative Commons Attribution-ShareAlike 4.0
*
* Revision  Description
* ========  ===========
* 2.1b      - Added "One Mode" toggle
			- Added Independent Prime color change
			- Fixed bugs 
			- Changed Serial speed to 115200
   			- MORE HIDDEN STUFF

* 2.1.5b    - BYE BYE LIBRARY
			- Self Contained project to avoid versions conflicts 
          

* 2.2     - Compatibility with MMA86X  

-------
Many things happened in between these versions
-------

* 2.3       - Tuned MMA86X speed clocks settings
			- Practically eliminated the stand alone MMA7660 library
			- Fixed Master reset 
			- BEFORE BIG CHANGES TO V 3

-------
 Many things happened in between these versions
-------


* 2.4      - Fixed compatibility between the MMA family

-------
Many things happened in between these versions
-------


* 2.5      - Current Version

* 2.5.1bR   - Beta Release

* 2.5.1bd  - Beta Developer 

* 2.5.2bd  - Beta Developer 
           - FIXING THE SLEEP MODE AFFECTING THE ACCELEROMETER RE-INIATILIZATON 
		   - OSM1 SUPPORT: UNCOMMENT LINE 88 FOR OSM SUPPORT (FIRST LINE OF THE PROGRAM)
		   
* 2.5.3bd  - Added missing accelerometer sensitivity (Debug)
           - FIXING THE SLEEP MODE 	
   		   - OSM1 SUPPORT: UNCOMMENT LINE 92 FOR OSM SUPPORT (FIRST LINE OF THE PROGRAM)	   

* 2.5.4bd  - Kroma variation  
           - Removed SLEEP MODE killer suspect
		   
		   
* 2.5.5bd  - Dimmed Colors
  		        
**********************************************************************************************/


///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
/// THE PROGRAM STARTS HERE ///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

//#define OSMONETRUE // UNCOMMENT THIS LINE FOR OSM1 
#define DEBUGRUN 
#define PRINTVERSION Serial.println(F("> NEO * 2.5.5bd - Kroma Edition (Take 3)")); 

//#define SLIDERPRO
//#define EEPROM_DEBUG
//#define VISUAL // COMMENT TO DISABLE VISUAL NAVIAGTION
#define NOP __asm__ __volatile__ ("nop\n\t") // AND THIS IS HOW YOU DEFINE A "NOP" ON ARDUINO AVR
//#define ACCEL_MMA7660 // ACCELEROMETER ENABLED
#define RED      9   // RED LED
#define GREEN    6   // GREEN LED
#define BLUE     5   // BLUE LED
#define BLUE_ARD 13  // BLUE_ARDUINO LED
#define LDO      A3  // LDO ENABLE
#define DEBUG    7   // DEBUG PIN

#include "mma8652_regs.h"

#include "LowPower.h"    // LOW POWER SLEEP (OPTION A)
#include <Wire.h>        // I2C LIBRARY
#include <EEPROM.h>      // EEPROM READ AND WRITE
#include <avr/pgmspace.h>// MEMORY SAVING LIBRARY
#include <avr/wdt.h>

#include "_CSTM_COLOR.h"
#include "_COLOR_MODES.h"




//// SETTING VARIABLES NEO

volatile boolean SLIDERPRO_FLAG = 0;
volatile byte ACCEL_MODE = 1;
volatile boolean ONEMODE_FLAG = 0; 
volatile boolean ClearToGo;
volatile boolean ONEMODE = 0;
volatile boolean MODERESET_FLAG = 0;             // RESET FLAG
volatile boolean AllYourBaseAreBelongToUs = 0;   
volatile byte CurrentOffCounter = 0;             
volatile int long TTtime;
volatile boolean Preview[2];
volatile boolean Armed = 1;
volatile boolean GLOBALCHANGE;
volatile int long RoundResult;
volatile float FloatResult;
volatile boolean AUTOCHANGE;
volatile int long BPM_Counter;
volatile int long BPM_Factor;
volatile byte PrimeA;
volatile byte PrimeB;
volatile byte MMAselect;
volatile  byte mmAxis;
volatile byte SenseY;
volatile int Sensitivity;
volatile byte PMMAselect;
volatile byte PmmAxis;
volatile int PAccelCounter;
volatile byte PAccelSensitivity;
volatile int ColorTime[2];
volatile int BlankTime[2];
volatile byte PrimeType[2];
volatile byte MaxPrimeColors[2];
volatile boolean TipUp;
volatile boolean TiltRight;
volatile boolean UpsideUp;
byte AccTilt;
int accelCounter;
boolean accShake;
volatile byte MemCheck;
int ColorTimeA, BlankTimeA, ColorTimeB,  BlankTimeB;
volatile byte ThisLimit;
volatile boolean Zflipped = 0;
volatile boolean ColorZflipped = 0;
volatile boolean NOMORE = 0;
int ThisTime;
volatile boolean SANDBOX = 1;
volatile bool ZEROCOLOR;
volatile byte CurrentMode; 
volatile bool DeleteColor = 0;
boolean FirstPrintFlag = 1;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int xAcc, yAcc, zAcc;
uint16_t xAccT, yAccT, zAccT;
int EEplus;
byte PROGMEMbank;
byte PROGset;
int eeRead;
int Daddress;
int Dvalue;
int ClearCountStart;
int ClearCountEnds;
int ClearCount;
int EEbank;
byte ValueCount;
int ek;
int uuu; 
int kk;
int k;// 
char myChar;
byte CC;
byte CCSET;
byte CR;
byte CG;
byte CB;
volatile boolean shadeFlag = 0;
int shTime;
volatile boolean ONNS = 1;
volatile byte CSHADE = 0;
volatile int time;
volatile byte shade;
volatile byte CCR[2][9];
volatile byte CCG[2][9];
volatile byte CCB[2][9];
volatile byte CCS[2][9];
volatile int CCT[2][9]; // NOT USED?
volatile byte colorSet;
volatile byte color;
volatile const byte BUTTON = 2; // Push Button on Digital Pin 2
byte VariationOffset;
volatile byte VARIATION = 0; // Used @ magnetometer.ino, modes.ino, OSMserial.ino
volatile int offyMinus;
volatile int offyPlus;
volatile boolean MASTER = 0; // SERIAL MASTER ( 1 = TRUE ) IF MASTER INVERT TX/RX CONNECTIONS - ONLY ONE MASTER ALLOWED
volatile boolean JUSTONCE; // WILL RUN ROUTINE ONLY ONCE
volatile boolean ONLYUNO; // WILL RUN ROUTINE ONLY ONCE
volatile boolean JUSTONCECHANGE;
volatile int MixCounter;
volatile byte STATE = 1; 
volatile boolean COLORCHANGE_FLAG = 0;
volatile byte WhatDmode;
unsigned int displayInt;
volatile boolean VirtualPreview = 0;

// TIMER2 INTERRUPT @ 61HZ / 16.40ms
volatile int long Int0count = 0; // Used on INT0
volatile int long Int0countNEG = 0; // Used on INT0
volatile bool Pushed = 0;  // Used on INT0
volatile bool Click = 0;  // Used on INT0
volatile bool OFF_MODE = 0;  // Used on INT0
volatile bool ToBorNotToB = 0;  // Used on INT0
volatile byte BlinkyCount = 0;
volatile boolean DoubleClick; // Used on Timer2 Interrupt
volatile boolean ONCE_RESET_COLOR_MODES = 1;
volatile boolean ONCE_SETUP_COLOR = 1;
volatile boolean ONCE_SAVE_COLOR = 0;
volatile byte CurrentColor = 1;
byte MaxSaved;
volatile int ShadeSet;
volatile byte ShaderFactor;
volatile int ColorSelection;// void TheLoop
volatile int ValueToRead;
// modeChange.ino
volatile byte ColorMaxCount[2];
volatile byte RRmode;
volatile byte cOLORcount;
volatile byte ColorToSet;
volatile byte mathEE_1;
volatile byte mathEE_2;
volatile byte ModeToChange;
volatile int sred;
volatile int sgreen;
volatile int sblue;
volatile boolean SaveDaColor = 0; // interrupts
volatile byte ColorToSave = 0;
volatile boolean COLOR_NAV = 1;
volatile boolean SaveDmode = 0;
volatile byte PrintMaster=0;
volatile byte AsteriscMaster=0;
int ModeMult;
volatile int Val1A;
volatile int Val2A;
volatile int Val1B;
volatile int Val2B;
volatile int Val1[2];
volatile int Val2[2];
volatile byte AccelCounter;
volatile byte Accel865xSensitivity;
volatile byte Axis;
volatile byte ModeSetSRAM [13][36]; // SRAM Space
volatile byte ModeSwap [5] [24];


uint8_t intSource;





#if defined(VISUAL)
const PROGMEM char osmCC_flahs_names[] ={"BLANK___/RED_____/SUNSET__/ORANGE__/YELLOW__/LEMON___/CHARTRE_/LAWNGR__/GCAMOL__/GREEN___/IXTAPA__/AQUA____/EBLUE___/CYAN____/JADE____/SKYBLUE_/AZURE___/BLUE____/GRAPE___/BUBBLGUM/MAGENTA_/PINK____/HOT_PINK/DEEP_PNK/FUSCIA__/ALLWIHTE/FIXWHITE/GRNWHITE/BLUWHITE/SFTPINK_/GHSTBLUE/GHSTGRN_/GHSTRED_/"};
#endif

volatile byte MaxUserModes;
volatile byte Mode;

long randNumber;
volatile boolean RandomYes;
volatile int RandomValue;

volatile boolean OgooD;
volatile byte CurrentUserBundle;
volatile byte CurrentUserMode;
volatile byte BPM_Selector;



//////////////// EXTRA ADDED FOR 865X
int AXIS_X_STATUS ;
int AXIS_Y_STATUS ;
int AXIS_Z_STATUS ;
int ID_STATUS;
volatile bool OSMONE = 0;
unsigned char GRANGE;
unsigned char OUTDATARANGE;
volatile int ReadReg;
uint8_t BYTE_PULLED; // was int
byte REG_TO_READ;

byte RawByte;
byte SUPER_REG_ADDRESS[49];
int DEVICEID;
int MMA_ADDRESS;


#define readIntSource()  I2C_readByte(MMA8652_INT_SOURCE)


int Debouncer;

//----------------------------------------------------------------------






////////////////////////////////////////////////////////////////////////////////////////////////
//// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES /////
////////////////////////////////////////////////////////////////////////////////////////////////
volatile byte UserCmodes[5][14] = // USE: UserCmodes[CurrentUserBundle][CurrentUserMode];
{// byte UserCmodes
	
	
	8,   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, // Bundle 1
	
	8,   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, // Bundle 2

	8,   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, // Bundle 3

	8,   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, // Bundle 4
	
	8,   1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, // Bundle 5
	
}; // etyb UserCmodes
////////////////////////////////////////////////////////////////////////////////////////////////
//// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES //// BUNLDES /////
////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////
//// BPM AUTO CHANGE ///// BPM AUTO CHANGE ///// BPM AUTO CHANGE ///// BPM AUTO CHANGE /////////
////////////////////////////////////////////////////////////////////////////////////////////////
volatile byte UserBPM[10] =
{
	0,0,        // AUTOCHANGE BPM BUNDLE 1 (0=No, 1=Yes) / BPM 1-255
	1,40,        // AUTOCHANGE BPM BUNDLE 2 (0=No, 1=Yes) / BPM 1-255
	1,80,        // AUTOCHANGE BPM BUNDLE 3 (0=No, 1=Yes) / BPM 1-255
	1,240,        // AUTOCHANGE BPM BUNDLE 4 (0=No, 1=Yes) / BPM 1-255
	1,120,      // AUTOCHANGE BPM BUNDLE 5 (0=No, 1=Yes) / BPM 1-255
} ;
////////////////////////////////////////////////////////////////////////////////////////////////
//// BPM AUTO CHANGE ///// BPM AUTO CHANGE ///// BPM AUTO CHANGE ///// BPM AUTO CHANGE /////////
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION ///
volatile  byte CurrentVersion = 231;         // CHANGE THIS NUMBER IF YOU WANT TO SAVE A NEW FACTORY DEFAULT  BETWEEN 1 AND 254  <----
//// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION  //// CURRENT VERSION ///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// the setup function runs once when you press reset or power the board
void setup()
{ // void setup
	
	
	delay(50);
	boolean WentToSleep = 0;
	OSMsetup();       // Sets I/O @ setup.ino
	TimerMax();       // Sets Timers @ setup.ino
	eeCheck();
	WentToSleep = EEPROM.read(5); // WentToSleep
	eeCheck();
	ONEMODE = EEPROM.read(1);// ONEMODE
	eeCheck();	
	attachInterrupt(0, pushInterrupt, FALLING); // Interrupt on Push Button (Digital 2)


	if (WentToSleep)
	{
		LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);//////// DEEP SLEEP
	}
	
	delay(50);
	digitalWrite(LDO, HIGH); // Power LDO ON
	delay(50);
	
	noInterrupts();
	while (digitalRead (BUTTON) == LOW)
	{
	WentToSleep = 1;
	}
	interrupts();
	
	
	SerialSetup();    // Sets Serial i/o @ setup.ino
	
	PRINTVERSION ;
	delay(200);// added for timing
	
	ACCEL_INIT();
	

	//PrintWelcome1(); // This is the welcome intro for the Serial Communication
	eepromWriteFactory();// Factory Reset (if)
	eepromLoad();// Load EEPROM to SRAM
	//PrintWelcome2();
	AnalogBlank(); // turn off LED
	STATE = 1;
	VARIATION = 0;

        /// this will take care of after sleep or battery hiccups
		eeCheck();
		CurrentUserBundle   = EEPROM.read(2);eeCheck(); // CurrentUserBundle
		CurrentUserMode     = EEPROM.read(3);eeCheck(); // CurrentUserMode
					
		if ((WentToSleep) || (!ONEMODE)) 
		{
			CurrentUserMode = 1 ;
			MaxUserModes = UserCmodes[CurrentUserBundle][0];
	    }
				
		Mode = UserCmodes[CurrentUserBundle][CurrentUserMode];
		
		
	WentToSleep = 0;	
	eeCheck();EEPROM.write(5,0);eeCheck();// did not went to sleep
	
	#if defined(EEPROM_DEBUG)
	DumpEEprom(); // FOR DEBUG
	DumpSRAM();   // FOR DEBUG
	#endif
	
    interrupts();
	


	
}// diov setup





  boolean SwitchAB = 1;
  boolean OnlyONce = 1;
  
  boolean GoOn = 1;

void loop()
{ // void Loop



//while (1)
//{
//I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);
//Serial.print("Acc: ");
//Serial.print(xAcc);Serial.print("  /  ");
//Serial.print(yAcc);Serial.print("  /  ");
//Serial.print(zAcc);Serial.println("  /  ");
//delay(50);
//
//}



//////    MODE  0      //////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 0 )
{ // while 0
	Alpha_Omega(); // modes.ino
}// elihw 0
//////    MODE  0      /////////////////////////////////////////////////////////////////////

    
//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 1 && GLOBALCHANGE )// Mode
{ //while mode 

	#if defined(OSMONETRUE) // if OSM ONE
	//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
	osm_MASTER_BUILDER (      2,       2,         30,           80,              1,      5.4,       8.2,       0,    0,    0,        1,       5.4,        8.2,       0,    0,    0     ) ;
	//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else 
	//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
	osm_MASTER_BUILDER (      2,       2,         30,           80,            1,      5.4,       8.2,       0,    0,    0,        1,       5.4,        8.2,       0,    0,    0     ) ; // was 40
	//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif

//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode
////
//// Axis: (Available only for Tilt option) 
//// 0 = X 
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode 
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 2 && GLOBALCHANGE )// Mode
{ //while mode
	

	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,               1,      17.3,       17.3,       0,    0,    0,        1,       17.3,      17.3,     0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,               1,      17.3,       17.3,       0,    0,    0,        1,       17.3,      17.3,     0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif
	

//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 3 && GLOBALCHANGE )// Mode 
{ //while mode


	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             1,      2.5,       4.7,       0,    0,    0,        1,       2.5,       4.7,       0,     0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,              1,      2.5,       4.7,       0,    0,    0,        1,       2.5,       4.7,       0,     0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif

//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 4 && GLOBALCHANGE )// Mode
{ //while mode
	
	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,               1,      3.2,       23.2,       0,    0,    0,        1,       3.2,      23.2,     0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,               1,      3.2,       23.2,       0,    0,    0,        1,       3.2,      23.2,     0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif
	
//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 5 && GLOBALCHANGE )// Mode
{ //while mode
	
	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             2,      4.2,       18.3,       0,    0,    0,        2,       4.2,       18.3,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             2,      4.2,       18.3,       0,    0,    0,        2,       4.2,       18.3,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif


//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 6 && GLOBALCHANGE )// Mode
{ //while mode
	
	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,              1,      4.6,       4.7,       0,    0,    0,        1,       4.6,        4.7,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             1,      4.6,       4.7,       0,    0,    0,        1,       4.6,        4.7,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif

	
//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 7 && GLOBALCHANGE )// Mode
{ //while mode
	
	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,              1,      4.6,       8.3,       0,    0,    0,        1,       4.6,        8.3,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             1,      4.6,       8.3,       0,    0,    0,        1,       4.6,        8.3,       0,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif
	
	
//// Acc_Select:
//// 0 = No_Accelerometer
//// 1 = Tilt
//// 2 = Shake / Freefall Normal Switch
//// 3 = Switch mode  
////
//// Axis: (Available only for Tilt option)
//// 0 = X
//// 1 = Y
//// 2 = Z
////
//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
////
//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
////
//// PRIME A/B:
//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
////
//// VP (Virtual Color Preview)
//// 0 = NO
//// 1 = YES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








//////    MODE     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
JUSTONCE = 1; GLOBALCHANGE = 1;
while (Mode == 8 && GLOBALCHANGE )// Mode
{ //while mode


	#if defined(OSMONETRUE) // if OSM ONE
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,             1,       2.6,        1.2,     120,    0,    0,      1,      2.6,       1.2,       120,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#else
		//                 (//-----------------------ACCEL SETTINGS------------//-----------------PRIME A  SETTINGS------------------//-----------------PRIME B  SETTINGS------------------//)
		osm_MASTER_BUILDER (       2,       2,         30,           80,            1,       2.6,        1.2,     120,    0,    0,      1,      2.6,       1.2,       120,    0,    0     ) ;
		//                 (  Acc_Select  Axis  AccelCounter  MMASensitivity  //  PrimeA  ColorTimeA  BlankTimeA   E1A   E2A   VPA  //  PrimeB  ColorTimeB  BlankTimeB   E1B   E2B   VPB   //) ;
	#endif
	
	
	//// Acc_Select:
	//// 0 = No_Accelerometer
	//// 1 = Tilt
	//// 2 = Shake / Freefall Normal Switch
	//// 3 = Switch mode  
	////
	//// Axis: (Available only for Tilt option)
	//// 0 = X
	//// 1 = Y
	//// 2 = Z
	////
	//// AccelCounter: 100 Default (1 to 32000) / Less = more sensitive (Debounce Sensitivity Counter)
	////
	//// MMASensitivity: Less = more sensitive. (OSM2 Only) 1 - 511 / Recommended (160 - 511)
	////
	//// PRIME A/B:
	//// 1 = Strobe        :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
	//// 2 = Trace         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = N/A                    //  Extra2(A/B) = N/A
	//// 3 = Morph         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Long Blank Time        //  Extra2(A/B) = N/A
	//// 4 = PULSE         :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = Random?(1=Yes,0=No)    //  Extra2(A/B) = Random Max Value (1-32000)
	//// 5 = Triple Rainbow:  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = # of Rainbows (1 to 3) //  Extra2(A/B) = Number of Colors (1-32000)
	//// 6 = HeartBeat     :  ColorTime(A/B): Time in Milliseconds // BlankTime(A/B): Time in Milliseconds // Extra1(A/B) = BPM                    //  Extra2(A/B) = N/A
	//// 7-12 = Sandbox(1-6 Extra Settings) :  Custom
	////
	//// VP (Virtual Color Preview)
	//// 0 = NO
	//// 1 = YES
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}// elihw mode
//////    MODE     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







}// diov Loop








