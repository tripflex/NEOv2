/**
 * Registers mask and some code:
 * Copyright (c) 2014 panStamp <contact@panstamp.com>
 * Author: José L. Redrejo Rodríguez
 * Creation date: 03/25/2014
 * Description: Registers definitions of MMA8652 Accelerometer.
 * 
 * Most of this header file was created using information provided by Freescale
 */
 

//#define MMA7660_ADDRESS 0x4C //This is the I2C address for our chip.
//#define MMA865X_ADDRESS 0x1D //This is the I2C address for our chip.


//----------------------------------------------------------------------
// http://cache.freescale.com/files/sensors/doc/data_sheet/MMA8653FC.pdf
// http://cache.freescale.com/files/sensors/doc/data_sheet/MMA8652FC.pdf
//----------------------------------------------------------------------

///// DEFINES FOR MMA865X ////////////////////////////



// XYZ_DATA_CFG_ Data Config REGISTER DEFINES
#define TWO_G   B00000000
#define FOUR_G  B00000001
#define EIGHT_G B00000010

// CTRL_REG1_ Control Reg1 Hz DEFINES ACTIVE
#define HZ800_ACTIVE   B01000001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 800Hz 1.25ms / (b1) No Fast Read / (b0) Full Scale
#define HZ400_ACTIVE   B01001001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 400Hz 2.5ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ200_ACTIVE   B01010001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 200Hz 5ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ100_ACTIVE   B01011001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 100Hz 10ms   / (b1) No Fast Read / (b0) Full Scale
#define HZ50_ACTIVE    B01100001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 50Hz 20ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ12_ACTIVE    B01101001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 12.5Hz 80ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ6_ACTIVE     B01110001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 6.25Hz 160ms / (b1) No Fast Read / (b0) Full Scale
#define HZ1_ACTIVE     B01111001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 1.56Hz 640ms / (b1) No Fast Read / (b0) Full Scale

// CTRL_REG1_ Control Reg1 Hz DEFINES STAND BY
#define HZ800_STANDBY   B01000000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 800Hz 1.25ms / (b1) No Fast Read / (b0) Full Scale
#define HZ400_STANDBY   B01001000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 400Hz 2.5ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ200_STANDBY   B01010000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 200Hz 5ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ100_STANDBY   B01011000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 100Hz 10ms   / (b1) No Fast Read / (b0) Full Scale
#define HZ50_STANDBY    B01100000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 50Hz 20ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ12_STANDBY    B01101000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 12.5Hz 80ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ6_STANDBY     B01110000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 6.25Hz 160ms / (b1) No Fast Read / (b0) Full Scale
#define HZ1_STANDBY     B01111000    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 1.56Hz 640ms / (b1) No Fast Read / (b0) Full Scale



// REGISTERS MMA8653FC and MMA8652FC
#define STATUS_  0x00  // Data Status
#define OUT_X_MSB_  0x01 // X Data MSB
#define OUT_X_LSB_  0x02 // X Data LSB
#define OUT_Y_MSB_  0x03 // Y Data MSB
#define OUT_Y_LSB_  0x04 // Y Data LSB
#define OUT_Z_MSB_  0x05 // Z Data MSB
#define OUT_Z_LSB_  0x06 // Z Data LSB

#define F_SETUP_   0x09 // MMA8652FC ONLY / FIFO Setup
#define TRIG_CFG_   0x0A// MMA8652FC ONLY / FIFO Triggers
#define SYSMOD_   0x0B  // MMA8652FC ONLY / System Mode

#define INT_SOURCE_   0x0C  // Interrupt Status
#define WHO_AM_I_  0x0D    // ID Register
#define XYZ_DATA_CFG_   0x0E // Data Config

#define HP_FILTER_CUTOFF_   0x0F // HP Filter Setting
#define PL_STATUS_   0x10    // PL Status
#define PL_CFG_   0x11       // PL Configuration
#define PL_COUNT_   0x12     // PL DEBOUNCE
#define PL_BF_ZCOMP_   0x13  // PL Back/Front Z Comp
#define PL_L_THS_REG_   0x14 // PL THRESHOLD
#define FF_MT_CFG_   0x15    // Freefall / Motion Config
#define FF_MT_SRC_   0x16    // Freefall / Motion Source
#define FF_MT_THS_   0x17    // Freefall / Motion Threshold
#define FF_MT_COUNT_   0x18  // Freefall / Motion Debounce

//////// 1D TO 28 MMA8652FC ONLY
#define TRANSIENT_CFG_   0x1D // MMA8652FC ONLY / Transient Config
#define TRANSIENT_SRC_   0x1E // MMA8652FC ONLY / Transient Source
#define TRANSIENT_THS_   0x1F // MMA8652FC ONLY / Transient Threshold
#define TRANSIENT_COUNT_   0x20 // MMA8652FC ONLY / Transient Debounce
#define PULSE_CFG_   0x21 // MMA8652FC ONLY / Pulse Config
#define PULSE_SRC_   0x22 // MMA8652FC ONLY / Pulse Source
#define PULSE_THSX_   0x23 // MMA8652FC ONLY / Pulse X Threshold
#define PULSE_THSY_   0x24 // MMA8652FC ONLY / Pulse Y Threshold
#define PULSE_THSZ_   0x25 // MMA8652FC ONLY / Pulse Z Threshold
#define PULSE_TMLT_   0x26 // MMA8652FC ONLY / Pulse First Timer
#define PULSE_LTCY_   0x27 // MMA8652FC ONLY / Pulse Latency
#define PULSE_WIND_   0x28 // MMA8652FC ONLY / Pulse 2nd Window
//////// 1D TO 28 MMA8652FC ONLY

#define ASLP_COUNT_   0x29 // Auto-SLEEP Counter
#define CTRL_REG1_    0x2A // Control Reg1
#define CTRL_REG2_    0x2B // Control Reg2
#define CTRL_REG3_    0x2C // Control Reg3 / Wake Interrupts from SLEEP
#define CTRL_REG4_    0x2D // Control Reg4 / Interrupt Enable Map
#define CTRL_REG5_    0x2E // Control Reg5 / Interrupt Configuration


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


//// used for MMA7660

int MMA_Nar[64] =  {-0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26,-27,-28,-29,-30,-31,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int MMA_Par[64] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};

//------------------------------------------------------------------




void ACCEL_INIT(void)// Init MMA865X or MMA7660
{// VOID ACCEL_INIT
	
digitalWrite(LDO, HIGH); // Power LDO ON
delay(5);


	#if defined(OSMONETRUE)
	    Wire.begin(); delay(1); // start of the i2c protocol
		DEVICEID = 0;
		OSMONE = 1;
		MMA_ADDRESS = 0x4C; //This is the I2C address for MMA7660
    	//Serial.println(F("MMA_ADDRESS = 0x4C;"));		
	#else 
   	    TWADC_begin(); delay(1); // start of the i2c protocol
		DEVICEID = 0x4A; // 0x4A MMA8652 // 0x5A MMA8653
		OSMONE = 0;
		MMA_ADDRESS = 0x1D; //This is the I2C address for MMA865X
		//Serial.println(F("MMA_ADDRESS = 0x1D;"));	 
	#endif
	
	

	
	#if defined(OSMONETRUE) // if OSM 1
	
		I2C_SEND(0x07,0x00); // Setting up MODE to Stand by to set SR
		I2C_SEND(0x06,0x10);
		I2C_SEND(0x08,0x00);  // Setting up SR register to 120 samples active and auto sleep mode
		I2C_SEND(0x07,0x01); //Setting up MODE Active to START measures
			
	#else // IS OSM TWO
	
		//Serial.println(F("> OSMTWO"));	
		
		/* REGISTERS
		// XYZ_DATA_CFG_ Data Config REGISTER DEFINES
		#define TWO_G   B00000000
		#define FOUR_G  B00000001
		#define EIGHT_G B00000010
		*/
		
		// Default
		GRANGE = B00000010 ;// XYZ_DATA_CFG 
		/*
		//////////////////////////////////////////////////////////////////////
		/// XYZ_DATA_CFG (0x0E)
		----------------------------------------------------------------------
		b7  | 0 |  ------------
		----------------------------------------------------------------------
		b6  | 0 |  ------------
		----------------------------------------------------------------------
		b5  | 0 |  ------------
		----------------------------------------------------------------------
		b4  | 0 |  OUTPUT DATA HIGH-PASS FILTER | 0* NORMAL / 1 HPF
		----------------------------------------------------------------------
		b3  | 0 |  ------------
		----------------------------------------------------------------------
		b2  | 0 |  ------------
		----------------------------------------------------------------------
		b1  | 0 |  FULL SCALE RANGE 1
		----------------------------------------------------------------------
		b0  | 0 |  FULL SCALE RANGE 0
		----------------------------------------------------------------------
		//////////////////////////////////////////////////////////////////////
		+==================================+
		|  FS1  |  FS0  | FULL SCALE RANGE |
		+=======|=======|==================+  
		|   0   |   0   |      +/-2G       |
		|   0   |   1   |      +/-4G       |
		|   1   |   0   |      +/-8G       |*
		|   1   |   1   |     RESERVED     |
		+==================================+   
		*/		
		
		
		OUTDATARANGE_STANDBY = B00100000; // STANDBY
		OUTDATARANGE_ACTIVE  = B00100001; // ACTIVE
		/* B00100000 (stand by)  / B00100001 (ACTIVE)
		//////////////////////////////////////////////////////
		/// CTRL_REG1 (0x2A)
		======================================================
		b7  | 0 |  ASLP-RATE-1    0* = 50HZ
		------------------------------------------------------
		b6  | 0 |  ASLP-RATE-0    0* = 50HZ
		======================================================
		b5  | 1 |  DATA RATE 2       = 50HZ / 20MS
		------------------------------------------------------
		b4  | 0 |  DATA RATE 1       = 50HZ / 20MS
		------------------------------------------------------
		b3  | 0 |  DATA RATE 0       = 50HZ / 20MS
		======================================================
		b2  | 0 |  ------------
		======================================================
		b1  | 0 |  F_READ (FAST READ)  0* NORMAL / 1 FAST READ
		======================================================
		b0  | 0 |  ACTIVE              0 STAND BY / 1 ACTIVE
		======================================================
		//////////////////////////////////////////////////////
		+==================================+
		| ASLP1 | ASLP0 |    FREQUENCY HZ  |
		+=======|=======|==================+
		|   0   |   0   |       50Hz       |
		|   0   |   1   |      12.5Hz      |
		|   1   |   0   |       6.5Hz      |
		|   1   |   1   |       1.56Hz     |
		+==================================+
		//////////////////////////////////////////////////////
		+==================================+============+
		|  DR2  |  DR1  |  DR0  | ODR(HZ)  | PERIOD(MS) |
		+=======|=======|=======|==========|============+
		|   0   |   0   |   0   |   800    |    1.25    |
		|   0   |   0   |   1   |   400    |    2.50    |
		|   0   |   1   |   0   |   200    |    5       |
		|   0   |   1   |   1   |   100    |    10      |
		|   1   |   0   |   0   |   50     |    20      | *
		|   1   |   0   |   1   |   12.5   |    80      |
		|   1   |   1   |   0   |   6.25   |    160     |
		|   1   |   1   |   1   |   1.56   |    640     |
		+===============================================+
		//////////////////////////////////////////////////////		
		*/
				

		// Retrieve from EEPROM
		


		I2C_MMA_standby();
		
					#ifdef DEBUGI2C
					Serial.println(F(">I2C_MMA_standby();"));
					#endif
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		I2C_SEND(CTRL_REG1_ , OUTDATARANGE_STANDBY ); // Output data rate at Hz, no auto wake, no auto scale adjust, no fast read mode, Active
		/* B00100000 (stand by)  / B00100001 (ACTIVE)
		//////////////////////////////////////////////////////
		/// CTRL_REG1 (0x2A)
		======================================================
		b7  | 0 |  ASLP-RATE-1    0* = 50HZ
		------------------------------------------------------
		b6  | 0 |  ASLP-RATE-0    0* = 50HZ
		======================================================
		b5  | 1 |  DATA RATE 2       = 50HZ / 20MS
		------------------------------------------------------
		b4  | 0 |  DATA RATE 1       = 50HZ / 20MS
		------------------------------------------------------
		b3  | 0 |  DATA RATE 0       = 50HZ / 20MS
		======================================================
		b2  | 0 |  ------------
		======================================================
		b1  | 0 |  F_READ (FAST READ)  0* NORMAL / 1 FAST READ
		======================================================
		b0  | 0 |  ACTIVE              0 STAND BY / 1 ACTIVE
		======================================================
		//////////////////////////////////////////////////////
		+==================================+
		| ASLP1 | ASLP0 |    FREQUENCY HZ  |
		+=======|=======|==================+
		|   0   |   0   |       50Hz       |
		|   0   |   1   |      12.5Hz      |
		|   1   |   0   |       6.5Hz      |
		|   1   |   1   |       1.56Hz     |
		+==================================+
		//////////////////////////////////////////////////////
		+==================================+============+
		|  DR2  |  DR1  |  DR0  | ODR(HZ)  | PERIOD(MS) |
		+=======|=======|=======|==========|============+
		|   0   |   0   |   0   |   800    |    1.25    |
		|   0   |   0   |   1   |   400    |    2.50    |
		|   0   |   1   |   0   |   200    |    5       |
		|   0   |   1   |   1   |   100    |    10      |
		|   1   |   0   |   0   |   50     |    20      | *
		|   1   |   0   |   1   |   12.5   |    80      |
		|   1   |   1   |   0   |   6.25   |    160     |
		|   1   |   1   |   1   |   1.56   |    640     |
		+===============================================+
		//////////////////////////////////////////////////////		
		*/
		
		
		
		
		
		I2C_SEND(XYZ_DATA_CFG_ ,GRANGE); // G full range mode
		/*
		//////////////////////////////////////////////////////////////////////
		/// XYZ_DATA_CFG (0x0E)
		----------------------------------------------------------------------
		b7  | 0 |  ------------
		----------------------------------------------------------------------
		b6  | 0 |  ------------
		----------------------------------------------------------------------
		b5  | 0 |  ------------
		----------------------------------------------------------------------
		b4  | 0 |  OUTPUT DATA HIGH-PASS FILTER | 0* NORMAL / 1 HPF
		----------------------------------------------------------------------
		b3  | 0 |  ------------
		----------------------------------------------------------------------
		b2  | 0 |  ------------
		----------------------------------------------------------------------
		b1  | 0 |  FULL SCALE RANGE 1
		----------------------------------------------------------------------
		b0  | 0 |  FULL SCALE RANGE 0
		----------------------------------------------------------------------
		//////////////////////////////////////////////////////////////////////
		+==================================+
		|  FS1  |  FS0  | FULL SCALE RANGE |
		+=======|=======|==================+  
		|   0   |   0   |      +/-2G       |
		|   0   |   1   |      +/-4G       |
		|   1   |   0   |      +/-8G       |*
		|   1   |   1   |     RESERVED     |
		+==================================+   
		*/
		
		#ifdef DEBUGI2C
		Serial.println(F(">I2C_SEND(XYZ_DATA_CFG_ ,GRANGE);"));
		#endif
		



		I2C_SEND(CTRL_REG2_, B00011011); //
		/* 
		//////////////////////////////////////////////////////
		/// CTRL_REG2 (0x2B)
		======================================================
		b7  | 0 |  Self-Test 
		======================================================
		b6  | 0 |  Software Reset
		======================================================
		b5  | 0 |  ------------
		======================================================
		b4  | 1 |  SMODS1 SLEEP mode power scheme selection
		------------------------------------------------------
		b3  | 1 |  SMODS0 SLEEP mode power scheme selection
		======================================================
		b2  | 0 |  SLPE / Auto-SLEEP
		======================================================
		b1  | 1 |  MODS1 ACTIVE mode power scheme selection
		------------------------------------------------------
		b0  | 1 |  MODS0 ACTIVE mode power scheme selection
		======================================================
		//////////////////////////////////////////////////////
		+===========================================+
		| (S)MODS1 | (S)MODS1 |      POWER MODE     |
		+==========|==========|=====================+
		|     0    |     0    | Normal              |
		|     0    |     1    | Low Noise Low Power |
		|     1    |     0    | High Resolution     |
		|     1    |     1    | Low Power           |
		+===========================================+
		//////////////////////////////////////////////////////	
		*/




		I2C_SEND(CTRL_REG3_ ,B00111000);
		/* 
		//////////////////////////////////////////////////////
		/// CTRL_REG3 (0x2C)
		=======================================================================
		b7  | 0 |  FIFO GATE / 0 = BYPASSED / 1 = ENABLED
		=======================================================================
		b6  | 0 |  WAKE_TRANS / Transient Wakeup / 0 = Bypassed / 1 = Enabled 
		=======================================================================
		b5  | 1 |  WAKE_LNDPRT / LNDPRT Wakeup  / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b4  | 1 |  WAKE_PULSE / TAP Wakeup / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b3  | 1 |  WAKE_FF / Free Fall Wakeup / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b2  | 0 |  ------------
		=======================================================================
		b1  | 0 |  IPOL / Interrupt Polarity / 0 = Active low / 1 = Active High
		=======================================================================
		b0  | 0 |  PP_OD / Push-Pull/Open-Drain on Interrupt / 0* = Push-Pull / 1 = Open Drain
		=======================================================================
		//////////////////////////////////////////////////////		
		*/
		
				
		 
		I2C_SEND(CTRL_REG4_ ,0x00);  
		/* 
		//////////////////////////////////////////////////////
		/// CTRL_REG3 (0x2C)
		=======================================================================
		b7  | 0 |  FIFO GATE / 0 = BYPASSED / 1 = ENABLED
		=======================================================================
		b6  | 0 |  WAKE_TRANS / Transient Wakeup / 0 = Bypassed / 1 = Enabled 
		=======================================================================
		b5  | 1 |  WAKE_LNDPRT / LNDPRT Wakeup  / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b4  | 1 |  WAKE_PULSE / TAP Wakeup / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b3  | 1 |  WAKE_FF / Free Fall Wakeup / 0 = Bypassed / 1 = Enabled
		=======================================================================
		b2  | 0 |  ------------
		=======================================================================
		b1  | 0 |  IPOL / Interrupt Polarity / 0 = Active low / 1 = Active High
		=======================================================================
		b0  | 0 |  PP_OD / Push-Pull/Open-Drain on Interrupt / 0* = Push-Pull / 1 = Open Drain
		=======================================================================
		//////////////////////////////////////////////////////		
		*/
		


        // Enter active mode
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		I2C_SEND(CTRL_REG1_ , OUTDATARANGE_ACTIVE ); // Output data rate at Hz, no auto wake, no auto scale adjust, no fast read mode, Active
		/* B00100000 (stand by)  / B00100001 (ACTIVE)
		//////////////////////////////////////////////////////
		/// CTRL_REG1 (0x2A)
		======================================================
		b7  | 0 |  ASLP-RATE-1    0* = 50HZ
		------------------------------------------------------
		b6  | 0 |  ASLP-RATE-0    0* = 50HZ
		======================================================
		b5  | 1 |  DATA RATE 2       = 50HZ / 20MS
		------------------------------------------------------
		b4  | 0 |  DATA RATE 1       = 50HZ / 20MS
		------------------------------------------------------
		b3  | 0 |  DATA RATE 0       = 50HZ / 20MS
		======================================================
		b2  | 0 |  ------------
		======================================================
		b1  | 0 |  F_READ (FAST READ)  0* NORMAL / 1 FAST READ
		======================================================
		b0  | 0 |  ACTIVE              0 STAND BY / 1 ACTIVE
		======================================================
		//////////////////////////////////////////////////////
		+==================================+
		| ASLP1 | ASLP0 |    FREQUENCY HZ  |
		+=======|=======|==================+
		|   0   |   0   |       50Hz       |
		|   0   |   1   |      12.5Hz      |
		|   1   |   0   |       6.5Hz      |
		|   1   |   1   |       1.56Hz     |
		+==================================+
		//////////////////////////////////////////////////////
		+==================================+============+
		|  DR2  |  DR1  |  DR0  | ODR(HZ)  | PERIOD(MS) |
		+=======|=======|=======|==========|============+
		|   0   |   0   |   0   |   800    |    1.25    |
		|   0   |   0   |   1   |   400    |    2.50    |
		|   0   |   1   |   0   |   200    |    5       |
		|   0   |   1   |   1   |   100    |    10      |
		|   1   |   0   |   0   |   50     |    20      | *
		|   1   |   0   |   1   |   12.5   |    80      |
		|   1   |   1   |   0   |   6.25   |    160     |
		|   1   |   1   |   1   |   1.56   |    640     |
		+===============================================+
		//////////////////////////////////////////////////////		
		*/
		TWADC_endTransmission();
		
		#ifdef DEBUGI2C
		Serial.println(F("> TWADC_endTransmission();"));
		#endif
	#endif
	
	Serial.print(F("> i2C_ADDRESS: 0x"));	Serial.print(MMA_ADDRESS, HEX);
	

	#if defined(OSMONETRUE)
		Serial.print(F(" / OSMv1"));
		Serial.println(F(" / MMA7660 - OSMv1"));
	#else
    	TWADC_requestFrom(DEVICEIDADDRESS, 0x0D);
	    byte ByteReturned = TWADC_read();
		Serial.print(F("  / ID: 0x"));
		Serial.print(ByteReturned, HEX);
		Serial.print(F(" / OSM"));
		
		I2CADC_SCL_H_OUTPUT();
		int ADCresult = analogRead(SCL_PIN);
		
		if (ADCresult > 568)
		{
		  Serial.println(F("v2.0"));	
		}
		else
		{
  		  Serial.println(F("v2.1"));
		}

	#endif
	
	
}// DIOV ACCEL_INIT



//------------------------------------------------------------------

void I2C_MMA_standby()
{// void I2C_MMA_standby
	//+++++++++++++++++++++++++++++++++++++++++++++++
	#if defined(OSMONETRUE)
	// SHOULD READ THE REGISTER AND CHANGE THE LAST BIT
	TWADC_begin(); delay(1);      //Initiate the Wire library and join the I2C bus as a master
	I2C_SEND(0x07,0x10);// Setting up StandBy
	#else // else if OSM2
	// SHOULD READ THE REGISTER AND CHANGE THE LAST BIT
	TWADC_begin(); delay(1);
	I2C_SEND(CTRL_REG1_ ,0x00);// stand by
	#endif
}// diov I2C_MMA_standby


//------------------------------------------------------------------


void I2C_MMA_Active()
{// void I2C_MMA_Active
	//+++++++++++++++++++++++++++++++++++++++++++++++
	#if defined(OSMONETRUE)
	// SHOULD READ THE REGISTER AND CHANGE THE LAST BIT
	I2C_SEND(0x07,0x01); //Setting up MODE Active to START measures
	#else // else if OSM2
	// SHOULD READ THE REGISTER AND CHANGE THE LAST BIT
	I2C_SEND(CTRL_REG1_ ,OUTDATARANGE_ACTIVE);// Output data rate at Hz, no auto wake, no auto scale adjust, no fast read mode, Active
	#endif
}// diov I2C_MMA_Active


//------------------------------------------------------------------


void TWADC_MMA_Reset(void)
{
	I2C_MMA_standby();
	I2C_SEND(CTRL_REG2_, 0x40); // Reset Mask 0x40
	I2C_MMA_Active();
}


//------------------------------------------------------------------


//void TWADC_MMA865x_Sleep(void)
//{
	//// Enter stand-by mode
	//I2C_MMA_standby();
	//I2C_SEND(ASLP_COUNT_, 1);
	//I2C_SEND(CTRL_REG2_, 0x1C);
	//// Back to active mode
	//TWADC_MMA_Active();
//}


//------------------------------------------------------------------




int TWADC_ACC_GET_VAL(byte AccelToPull) //READ number data from i2c slave ctrl-reg register and return the result in a vector
{// VOID I2C_ACC_GET_XYZ


	////+++++++++++++++++++++++++++++++++++++++++++++++
	#if defined(OSMONETRUE)
	
	int xyzAcc[3];
	
	Wire.beginTransmission(0x4C);//This is the I2C address for MMA7660
	Wire.write(0x00);  // register to read
	Wire.endTransmission();
	Wire.requestFrom(0x4C, 3); // read a byte
	
	if(Wire.available())
	{
		xyzAcc[0]=Wire.read();
		xyzAcc[1]=Wire.read();
		xyzAcc[2]=Wire.read();
		
	}
	
	
	if (AccelToPull == 0) // x axis
	{
		xyzAcc[0] = MMA_Nar[xyzAcc[0]];
	}
	
	if (AccelToPull == 1) // y axis (yaw)
	{
		xyzAcc[1] = MMA_Par[xyzAcc[1]];
	}
	
	if (AccelToPull == 2) // z axis
	{
		xyzAcc[2] = MMA_Par[xyzAcc[2]];
	}
	
	return xyzAcc[AccelToPull];

	////+++++++++++++++++++++++++++++++++++++++++++++++
	
	#else // OSMv2
	
	//+++++++++++++++++++++++++++++++++++++++++++++++

    int Acc;
	byte FIRSTADDRESS;
	//byte SECONDADDRESS;
	//byte MyResutl_high;
	//byte MyResutl_low;
	
	if (AccelToPull == 0) // x axis
	{
		FIRSTADDRESS   = 0x01;
		//SECONDADDRESS = 0x02;
	}
	
	if (AccelToPull == 1) // y axis (yaw)
	{
		FIRSTADDRESS   = 0x03;
		//SECONDADDRESS = 0x04;
	}
	
	if (AccelToPull == 2) // z axis
	{
		FIRSTADDRESS   = 0x05;
		//SECONDADDRESS = 0x06;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	ADCSRA = ADCRASAVE;// recover ADCSRA VALUE
	TWADC_requestFrom(MMA_ADDRESS,FIRSTADDRESS);
	Acc = TWADC_read();
	TWADC_endTransmission();
	ADCRASAVE = ADCSRA;// save ADCSRA VALUE
	ADCSRA = 0; // SET TO ZERO

	/////////////////////////////////////////////////////////////////////

	int accel[4];
	accel[0] = (Acc|((int)Acc<<8))>>6; // X
	if (accel[0]>0x01FF) {accel[1]=(((~accel[0])+1)-0xFC00);} // note: with signed int, this code is optional
	else {accel[1]=accel[0];} // note: with signed int, this code is optional
	
	return accel[1];

	#endif
	
	//+++++++++++++++++++++++++++++++++++++++++++++++

}// DIOV I2C_ACC_GET_XYZ


//------------------------------------------------------------------

