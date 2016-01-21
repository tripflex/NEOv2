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

// CTRL_REG1_ Control Reg1 Hz DEFINES
#define HZ800   B01000001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 800Hz 1.25ms / (b1) No Fast Read / (b0) Full Scale
#define HZ400   B01001001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 400Hz 2.5ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ200   B01010001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 200Hz 5ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ100   B01011001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 100Hz 10ms   / (b1) No Fast Read / (b0) Full Scale
#define HZ50    B01100001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 50Hz 20ms    / (b1) No Fast Read / (b0) Full Scale
#define HZ12    B01101001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 12.5Hz 80ms  / (b1) No Fast Read / (b0) Full Scale
#define HZ6     B01110001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 6.25Hz 160ms / (b1) No Fast Read / (b0) Full Scale
#define HZ1     B01111001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 1.56Hz 640ms / (b1) No Fast Read / (b0) Full Scale

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


///////// MACROS



//------------------------------------------------------------------

//// used for MMA7660
int MMA_Nar[64] =  {-0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26,-27,-28,-29,-30,-31,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int MMA_Par[64] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};


//int MMA_XYar[64] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};
//int MMA_Zar[64] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1};



//------------------------------------------------------------------



	 //#if defined(OSMONETRUE)
	 //
	 //#else
	 //
	 //#endif


void ACCEL_INIT(void)// Init MMA865X or MMA7660
{// VOID ACCEL_INIT
	

	Wire.begin(); delay(10); // start of the i2c protocol
	
	 #if defined(OSMONETRUE)
	    DEVICEID = 0;
		OSMONE = 1;
		MMA_ADDRESS = 0x4C; //This is the I2C address for MMA7660
		Serial.println(F("MMA_ADDRESS = 0x4C;"));		
	 #else 
  	    DEVICEID = 0x4A; // 0x4A MMA8652 // 0x5A MMA8653
		OSMONE = 0;
		MMA_ADDRESS = 0x1D; //This is the I2C address for MMA865X
		Serial.println(F("MMA_ADDRESS = 0x1D;"));	 
	 #endif
	
	

	
	#if defined(OSMONETRUE) // if OSM 1
	
		I2C_SEND(0x07,0x00); // Setting up MODE to Stand by to set SR
		I2C_SEND(0x06,0x10);
		I2C_SEND(0x08,0x00);  // Setting up SR register to 120 samples active and auto sleep mode
		I2C_SEND(0x07,0x01); //Setting up MODE Active to START measures
	
	#else // IS OSM TWO
	
		Serial.println(F("> OSMTWO"));	
		
		/* REGISTERS
		// XYZ_DATA_CFG_ Data Config REGISTER DEFINES
		#define TWO_G   B00000000
		#define FOUR_G  B00000001
		#define EIGHT_G B00000010

		// CTRL_REG1_ Control Reg1 Hz DEFINES
		#define HZ800   B01000001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 800Hz 1.25ms / (b1) No Fast Read / (b0) Full Scale
		#define HZ400   B01001001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 400Hz 2.5ms  / (b1) No Fast Read / (b0) Full Scale
		#define HZ200   B01010001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 200Hz 5ms    / (b1) No Fast Read / (b0) Full Scale
		#define HZ100   B01011001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 100Hz 10ms   / (b1) No Fast Read / (b0) Full Scale
		#define HZ50    B01100001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 50Hz 20ms    / (b1) No Fast Read / (b0) Full Scale
		#define HZ12    B01101001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 12.5Hz 80ms  / (b1) No Fast Read / (b0) Full Scale
		#define HZ6     B01110001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 6.25Hz 160ms / (b1) No Fast Read / (b0) Full Scale
		#define HZ1     B01111001    // (b7-6)Sleep @ 12.5hz - 80ms / (b5-4-3) 1.56Hz 640ms / (b1) No Fast Read / (b0) Full Scale
		*/
		
		// Default
		GRANGE = EIGHT_G;
		OUTDATARANGE = HZ50;
		
		// Retrieve from EEPROM
			
		I2C_SEND(CTRL_REG1_ ,0x00); delay(1); // standby to be able to configure
		I2C_SEND(XYZ_DATA_CFG_ ,GRANGE); delay(1);	 // G full range mode
		//I2C_SEND(CTRL_REG1_ ,OUTDATARANGE); delay(1); // Output data rate at Hz, no auto wake, no auto scale adjust, no fast read mode

		// Enable interrupts - Open-drain output
		// Pulse function interrupt can wake-up system
		// Orientation interrupt can wake-up system
		// Free-fall/motion function interrupt can wake-up system
		I2C_SEND(CTRL_REG3_ ,0x39); delay(1); 
		  
		// Enable Pulse detection Interrupt
		// Enable Orientation Interrupt
		// Enable Free-fall/motion Interrupt
		I2C_SEND(CTRL_REG4_ ,0); delay(1); 
		  
		// All interrupt sources hooked to INT2 pin
		I2C_SEND(CTRL_REG5_ ,1); delay(1);  // SET INTERRUPT 1

		// Enter active mode
		I2C_MMA_Active(); delay(1); // 
		
	
		Serial.println(F("I2C_MMA_Active();"));	
		
		//I2C_MMA_Reset();
		delay(10);
		
	#endif
	
	
	
	Serial.print(F("> i2C_ADDRESS: "));	Serial.print(MMA_ADDRESS, HEX);
	Serial.print(F("  / ID: MMA8652 "));

	#if defined(OSMONETRUE)
		Serial.print(F("N/A "));
		Serial.print(F(" / OSMv1"));
		Serial.println(F(" / MMA7660 - v1"));
	#else

			//I2C_READ_REG(0x0D);
			//Serial.print(BYTE_PULLED, HEX);
			Serial.print(F(" / OSM2"));
			//byte WHOWHO = I2C_readByte(WHO_AM_I_);
			//if (WHOWHO == 0x5A)
			//{
			//Serial.println(F(" / MMA8653FC - v2"));
			//}
			//else if (WHOWHO == 0x4A)
			//{
			//Serial.println(F(" / MMA8652FC - v3"));
			//}
		
			Serial.println(F(" -- jump --"));
			
	#endif
	
	
}// DIOV ACCEL_INIT


//------------------------------------------------------------------


void I2C_SEND(unsigned char REG_ADDRESS, unsigned  char DATA)  //SEND data to MMA
{// VOID I2C_SEND
	Wire.beginTransmission(MMA_ADDRESS);
	Wire.write(REG_ADDRESS);
	Wire.write(DATA);
	Wire.endTransmission();
}// DIOV I2C_SEND


//------------------------------------------------------------------


void I2C_ACC_GET_XYZ(int *xAcc,int *yAcc,int *zAcc) //READ number data from i2c slave ctrl-reg register and return the result in a vector
{// VOID I2C_ACC_GET_XYZ
	
	   //+++++++++++++++++++++++++++++++++++++++++++++++
		#if defined(OSMONETRUE)
			Wire.beginTransmission(0x4C);//This is the I2C address for MMA7660
			Wire.write(0x00);  // register to read
			Wire.endTransmission();
			Wire.requestFrom(0x4C, 3); // read a byte
			
			if(Wire.available()){
				*yAcc=Wire.read();
				*xAcc=Wire.read();
				*zAcc=Wire.read();
				
			}
			
			*xAcc = MMA_Nar[*xAcc];
			*yAcc = MMA_Par[*yAcc];
			*zAcc = MMA_Par[*zAcc];
		
		
		//+++++++++++++++++++++++++++++++++++++++++++++++
		
		#else // OSMv2
		
		//+++++++++++++++++++++++++++++++++++++++++++++++
		
			byte REG_ADDRESS[7];
			int accel[4];
			int i=0;
			Wire.beginTransmission(MMA_ADDRESS); //=ST + (Device address+W(0)) + wait for ACK
			Wire.write(0);  // store the register to read in the buffer of the wire library
			Wire.endTransmission();
			Wire.requestFrom(MMA_ADDRESS,7); // read a number of byte and store them in wire.read (note: by nature, this is called an "auto-increment register address")
			for(i=0; i<7; i++) // 7 because on datasheet p.19 if FREAD=0, on auto-increment, the address is shifted
	
			/*
			// according to the datasheet, because it's shifted, outZlsb are in address 0x00
			// so we start reading from 0x00, forget the 0x01 which is now "status" and make the adaptation by ourselves
			//this gives:
			//0 = status
			//1= X_MSB
			//2= X_LSB
			//3= Y_MSB
			//4= Y_LSB
			//5= Z_MSB
			//6= Z_LSB
			*/
	
			{// FOR I
			REG_ADDRESS[i]=Wire.read(); //each time you read the write.read it gives you the next byte stored. The counter is reset on requestForm
			}// ROF I

			// MMA8653FC gives the answer on 10bits. 8bits are on _MSB, and 2 are on _LSB
			// this part is used to concatenate both, and then put a sign on it (the most significant bit is giving the sign)
			// the explanations are on p.14 of the 'application notes' given by freescale.
			
			for (i=1;i<7;i=i+2)
			{// FOR BYTE
			accel[0] = (REG_ADDRESS[i+1]|((int)REG_ADDRESS[i]<<8))>>6; // X
			if (accel[0]>0x01FF) {accel[1]=(((~accel[0])+1)-0xFC00);} // note: with signed int, this code is optional
			else {accel[1]=accel[0];} // note: with signed int, this code is optional
			switch(i)
				{// SWITCH
					
					case 1: *xAcc=accel[1];
					break;
					case 3: *yAcc=accel[1];
					break;
					case 5: *zAcc=accel[1];
					break;
										
				}// HCTIWS
		
			}// ROF BYTE
	
		#endif
		
		//+++++++++++++++++++++++++++++++++++++++++++++++

}// DIOV I2C_ACC_GET_XYZ

//------------------------------------------------------------------





//------------------------------------------------------------------


void I2C_READ_REG(int ctrlreg_address) //READ number data from i2c slave ctrl-reg register and return the result in a vector
{
	Wire.beginTransmission(MMA_ADDRESS); //=ST + (Device address+W(0)) + wait for ACK
	Wire.write(ctrlreg_address);  // register to read
	
	#if defined(OSMONETRUE)
	Wire.endTransmission();
	#else
	Wire.endTransmission(0);
	#endif
	
	Wire.requestFrom(MMA_ADDRESS,1); // read a number of byte and store them in write received
	if(Wire.available())
	{
		BYTE_PULLED=Wire.read();
	}	
}

////------------------------------------------------------------------
//
    //uint8_t I2C_readByte(uint8_t ctrlreg_address)
    //{
	    //uint8_t BYTE_PULLED; // `data` will store the register data
	    //Wire.beginTransmission(MMA_ADDRESS);         // Initialize the Tx buffer
	    //Wire.write(ctrlreg_address);	                 // Put slave register address in Tx buffer
	    //Wire.endTransmission(false);             // Send the Tx buffer, but send a restart to keep connection alive
		//Wire.requestFrom(MMA_ADDRESS,1);  // Read one uint8_t from slave register address
	    //while(!Wire.available());
		//BYTE_PULLED = Wire.read();                      // Fill Rx buffer with result
	    //return BYTE_PULLED;                             // Return data read from slave register
    //}
		//
////------------------------------------------------------------------
//


//------------------------------------------------------------------

uint8_t I2C_readByte(uint8_t ctrlreg_address)
{
	uint8_t BYTE_PULLED; // `data` will store the register data
	Wire.beginTransmission(MMA_ADDRESS);         // Initialize the Tx buffer
	Wire.write(ctrlreg_address);	                 // Put slave register address in Tx buffer
	Wire.endTransmission(false);             // Send the Tx buffer, but send a restart to keep connection alive
	Wire.requestFrom(MMA_ADDRESS,1);  // Read one uint8_t from slave register address
		if(Wire.available())
		{
			BYTE_PULLED = Wire.read();  delay(1);
		}
	return BYTE_PULLED;                             // Return data read from slave register
}

//------------------------------------------------------------------





uint8_t I2C_read_buffer(uint8_t address, uint8_t *buffer, uint8_t length)
{
	uint8_t i;
	
	Wire.beginTransmission(MMA8652_CTRL_ID_DEFAULT);
	Wire.write(address);
	Wire.endTransmission(false);
	
	Wire.requestFrom((int)MMA8652_CTRL_ID_DEFAULT, (int)length);

	for(i=0 ; i<length ; i++)
	{
		while(!Wire.available());
		buffer[i] = Wire.read();
	}
	
	return i;
}



//------------------------------------------------------------------

//int I2C_READ_865_CHECK(void) //READ MMA865X to be used at the top
//{
	//
	//Wire.beginTransmission(0x1D); //=ST + (Device address+W(0)) + wait for ACK
//Serial.println(F("> beginTransmission(0x1D)"));
	//Wire.write(0x0D);  // register to read Device ID
//Serial.println(F("write(0x0D)"));
		//
		//#if defined(OSMONETRUE)
		//{
			//Wire.endTransmission();
			//Serial.println(F("endTransmission()"));
		//}
		//#else
		//{
			//Wire.endTransmission(0);
			//Serial.println(F("endTransmission(0)"));
			//Wire.requestFrom(0x1D,1); // read a number of byte and store them in write received
			//Serial.println(F("requestFrom(0x1D,1)"));
			//while (!Wire.available());
			//Serial.println(F("out of !Wire.available()"));
			//delay(10);
			//if(Wire.available())
			//{
				//BYTE_PULLED=Wire.read();
				//Serial.println(F("BYTE_PULLED=Wire.read();"));
			//}
		//}
		//#endif
//
//
	//return BYTE_PULLED;
//}

//------------------------------------------------------------------






void I2C_MMA_DUMP(unsigned char TheseRegisters ) //READ number data from i2c slave ctrl-reg register and return the result in a vector
{
	////unsigned char REG_ADDRESS;
	//Wire.beginTransmission(MMA_ADDRESS); //=ST + (Device address+W(0)) + wait for ACK
	//Wire.write(0);  // register to read
	//if (!OSMONE){ Wire.endTransmission(0);} // Send the Tx buffer, but send a restart to keep connection alive
	//else{ Wire.endTransmission();}
	//
	//Wire.requestFrom(MMA_ADDRESS, TheseRegisters ); // read a number of byte and store them in write received
//
	//byte CounterA = 0;
	//while (CounterA < TheseRegisters)
	//{
		//if(Wire.available())
		//{
			//SUPER_REG_ADDRESS[CounterA]=Wire.read();
		//}
		//CounterA++;
	//}
	
}


//------------------------------------------------------------------



void I2C_MMA_standby()
{// void I2C_MMA_standby
	//+++++++++++++++++++++++++++++++++++++++++++++++
	#if defined(OSMONETRUE)
		Wire.begin();       //Initiate the Wire library and join the I2C bus as a master
		I2C_SEND(0x07,0x10); // Setting up StandBy
	#else // else if OSM2
		byte c = I2C_readByte(0x2A);
		I2C_SEND(CTRL_REG1_, c & ~(0x01));
	#endif
}// diov I2C_MMA_standby

//--------------------------------------------------------------------------------------------------


// Sets to active mode.
// Needs to be in this mode to output data
void I2C_MMA_Active()
{// void I2C_MMA_Active
	//+++++++++++++++++++++++++++++++++++++++++++++++
	#if defined(OSMONETRUE)
	
		I2C_SEND(0x07,0x01); //Setting up MODE Active to START measures
	
	#else // else if OSM2
	
	byte c = I2C_readByte(0x2A);delay(1);
	I2C_SEND(CTRL_REG1_,  c | 0x01);
	
	#endif
	
}// diov I2C_MMA_Active


//--------------------------------------------------------------------------------------------------

// RESET THE DEVICE
void I2C_MMA_Reset(void)
{
	  I2C_MMA_standby();
	  delay(1);
	  I2C_SEND(CTRL_REG2_, 0x40); // Reset Mask 0x40
	  delay(1);
	  I2C_MMA_Active();
}

//--------------------------------------------------------------------------------------------------


void I2C_MMA_EnableInterrupt(uint8_t Source)
{
	  // Enable interrupt
	  byte RegisterToChange;
	  RegisterToChange |= Source;
	  I2C_SEND(CTRL_REG4_, RegisterToChange);
}


//--------------------------------------------------------------------------------------------------


void I2C_MMA_DisableInterrupt(uint8_t Source)
{
	//  Disable interrupt
	  byte RegisterToChange;
	  RegisterToChange &= Source;
	  I2C_SEND(CTRL_REG4_, RegisterToChange);	
}


//--------------------------------------------------------------------------------------------------


void I2C_MMA_enableFreeFallInterrupt(uint8_t sensibility)
{
  //// Enter stand-by mode
  I2C_MMA_standby();
  delay(1);
  I2C_MMA_EnableInterrupt(0x04); // SRC_FF_MT_MASK 
  delay(1);
  //// Enable single pulse detection on each axis
  
  I2C_SEND(FF_MT_CFG_, 0xF8); // Motion detection - XYZ events enabled
  delay(1);
  I2C_SEND(FF_MT_THS_, sensibility);
  delay(1);
  //// Back to active mode
  I2C_MMA_Active();
}


//--------------------------------------------------------------------------------------------------

void I2C_MMA_disableFreeFallInterrupt(void)
{

  // Enter stand-by mode
  I2C_MMA_standby();
  delay(1);
  I2C_MMA_DisableInterrupt(0x04); // SRC_FF_MT_MASK 
  delay(1);
  // Disable Portrait/Ladscape orientation detection
  I2C_SEND(FF_MT_CFG_, 0);
  delay(1);
  // Back to active mode
  I2C_MMA_Active();
}

//--------------------------------------------------------------------------------------------------


void I2C_MMA_Sleep(void)
{
	  // Enter stand-by mode
	  I2C_MMA_standby();
	  delay(2);
	  I2C_SEND(ASLP_COUNT_, 1);
	  delay(2);
	  I2C_SEND(CTRL_REG2_, 0x1C);
	  delay(1);
	  // Back to active mode
	  I2C_MMA_Active();
}


//--------------------------------------------------------------------------------------------------

void I2C_MMA_readXYZ(void)
{
	uint8_t buf[7];
	uint16_t twoCompl;
	
	I2C_read_buffer(MMA8652_STATUS_00, buf, 7);

	twoCompl = ((buf[1] << 8) | buf[2]) >> 4;
	if (buf[1] > 0x7F)
	xAccT = (~twoCompl + 1) * (-1);
	else
	xAccT = twoCompl;

	twoCompl = ((buf[3] << 8) | buf[4]) >> 4;
	if (buf[3] > 0x7F)
	yAccT = (~twoCompl + 1) * (-1);
	else
	yAccT = twoCompl;

	twoCompl = ((buf[5] << 8) | buf[6]) >> 4;
	if (buf[5] > 0x7F)
	zAccT = (~twoCompl + 1) * (-1);
	else
	zAccT = twoCompl;
}

//--------------------------------------------------------------------------------------------------	