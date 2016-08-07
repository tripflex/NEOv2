/*
TWO WIRE ADC REPLACE THE WIRE LIBRARY FOR DEVICES OPERATING UNDER EXTREME SIGNAL LEVELS CIRCUMSTANCES.
THIS LIBRARY IS DESIGNED TO SOLVE "LOGIC 1" DETECTION OUT OF THE NORMAL RANGE.

*/



#define CLK_H 0
#define CLK_L 1
#define TICK_DELAY 1
#define DEVICE_WRITE 0x3A
#define DEIVE_READ   0x3B
int I2CADC_H = 315; // ANALOG TRUE HIGH BIT
int I2CADC_L = 150; // ANALOG TRUE LOW BIT


//------------------------------------------------------------------


void I2C_SEND(unsigned char REG_ADDRESS, unsigned  char DATA)  
{// VOID I2C_SEND
	
	#if defined(OSMONETRUE)
	
	Wire.beginTransmission(MMA_ADDRESS);
	Wire.write(REG_ADDRESS);
	Wire.write(DATA);
	Wire.endTransmission();
	delay(1);
	
	#else 
	
	TWADC_beginTransmission(MMA_ADDRESS);
	TWADC_write(REG_ADDRESS);
	TWADC_write(DATA);
	TWADC_endTransmission();
	delay(1);
	
	#endif
	
}// DIOV I2C_SEND



//------------------------------------------------------------------


void TWADC_begin(void) // START BIT SEQUENCE
{// TWADC_begin

	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SDA_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SDA_L_INPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	
}// TWADC_begin


//------------------------------------------------------------------


void TWADC_endTransmission(void)// STOP BIT SEQUENCE
{// TWADC_begin
		I2CADC_SDA_L_INPUT(); delayMicroseconds(TICK_DELAY);
		I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
		I2CADC_SDA_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
}// TWADC_begin


//------------------------------------------------------------------


void TWADC_requestFrom(unsigned char REG_ADDRESS, unsigned  char DATA)// this is different that Wire.requestFrom
{// void TWADC_requestFrom
	TWADC_begin();
	TWADC_write_w(REG_ADDRESS); // DEVICEIDADDRESS + W(0)
	TWADC_write(DATA);
	TWADC_begin();
	TWADC_write_r(REG_ADDRESS); // DEVICEIDADDRESS + R(1)
}// diov TWADC_requestFrom


//------------------------------------------------------------------


void TWADC_beginTransmission(byte DeviceAddress)
{// void TWADC_beginTransmission
	TWADC_begin();
	TWADC_write_w(DeviceAddress);
}// diov TWADC_beginTransmission

//------------------------------------------------------------------

void TWADC_write(byte ByteSend) // full 8bit send + pull line check
{// TWADC_write
	int ReversedByte = ~ByteSend;
	uint8_t i=8;
	while(i>0)
	{
		i--;
		pinMode(SDA_PIN, bitRead(ReversedByte, i));delayMicroseconds(TICK_DELAY);
		I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
		I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	}
	

	///////// CHECK FOR PULLED LINE /////////////////////////////
	AckThis:
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	int ADCresult = analogRead(SCL_PIN);
	if (ADCresult < I2CADC_L)
	{
		// digitalWrite(BLUE, HIGH);// DEBUG
		goto AckThis;
	}
	// digitalWrite(BLUE, LOW);// DEBUG
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	///////// CHECK FOR PULLED LINE /////////////////////////////
		
}// TWADC_write


//------------------------------------------------------------------


void TWADC_write_w(byte ByteSend)// write Address + w(0) + pull line check
{// TWADC_write_w
	
	int ReversedByte = ~ByteSend;
	uint8_t i=7;
	while(i>0)
	{
		i--;
		pinMode(SDA_PIN, bitRead(ReversedByte, i));delayMicroseconds(TICK_DELAY); 
		I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY); 
		I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY); 
	}
	//////////// WRITE BIT //////////////////////////////////////
	I2CADC_SDA_L_INPUT(); delayMicroseconds(TICK_DELAY); 
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY); 
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY); 
	//////////// WRITE BIT //////////////////////////////////////
	
	///////// CHECK FOR PULLED LINE /////////////////////////////
	AckThis:
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	int ADCresult = analogRead(SCL_PIN);
	if (ADCresult < I2CADC_L)
	{
		// digitalWrite(BLUE, HIGH);// DEBUG
		goto AckThis;
	}
	// digitalWrite(BLUE, LOW);// DEBUG
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
    ///////// CHECK FOR PULLED LINE /////////////////////////////
	
}// TWADC_write_w


//------------------------------------------------------------------


void TWADC_write_r(byte ByteSend)// write Address + r(1) + pull line check
{// TWADC_write_r

	int ReversedByte = ~ByteSend;
	uint8_t i=7;
	while(i>0)
	{
		i--;
		pinMode(SDA_PIN, bitRead(ReversedByte, i));delayMicroseconds(TICK_DELAY); 
		I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY); 
		I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY); 
	}
	//////////// READ BIT //////////////////////////////////////
	I2CADC_SDA_H_OUTPUT(); delayMicroseconds(TICK_DELAY); 
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY); 
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY); 
	//////////// READ BIT //////////////////////////////////////
	
	///////// CHECK FOR PULLED LINE /////////////////////////////
	AckThis:
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	int ADCresult = analogRead(SCL_PIN);
	if (ADCresult < I2CADC_L)
	{
		// digitalWrite(BLUE, HIGH);// DEBUG
		goto AckThis;
	}
	// digitalWrite(BLUE, LOW);// DEBUG
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	///////// CHECK FOR PULLED LINE /////////////////////////////

}// TWADC_write_r


//------------------------------------------------------------------


byte TWADC_read(void)
{// TWADC_read
	byte Received_Data = 0;
	uint8_t i=8;
	while(i>0)
	{
		i--;
		I2CADC_SDA_H_OUTPUT();
		I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
		int ADCresult = analogRead(SDA_PIN);
			if (ADCresult < I2CADC_L)
			{
			  Received_Data &= ~(1<<i); // Zero
			}
			else
			{
  			  Received_Data |= (1<<i); // One
			}
		
		I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	}

	///////// CHECK FOR PULLED LINE /////////////////////////////
	AckThis:
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	I2CADC_SCL_H_OUTPUT(); delayMicroseconds(TICK_DELAY);
	int ADCresult = analogRead(SCL_PIN);
	if (ADCresult < I2CADC_L)
	{
		// digitalWrite(BLUE, HIGH);// DEBUG
		goto AckThis;
	}
	// digitalWrite(BLUE, LOW);// DEBUG
	I2CADC_SCL_L_INPUT(); delayMicroseconds(TICK_DELAY);
	///////// CHECK FOR PULLED LINE /////////////////////////////
	
	return Received_Data;

}// TWADC_read



//------------------------------------------------------------------

////////////////////////////////////////////////////////


void I2CADC_SDA_H_OUTPUT(void)
{
	DDRC &= ~(1<<4); // set SDA pin Output / Pull High
}

//-------------------------------------------------------

void I2CADC_SCL_H_OUTPUT(void)
{
	DDRC &= ~(1<<5); // set SCL pin Output / Pull High
}

//-------------------------------------------------------

void I2CADC_SDA_L_INPUT(void)
{
	DDRC |= (1<<4); // set SDA pin Input / Pull Low
}

//-------------------------------------------------------

void I2CADC_SCL_L_INPUT(void)
{
	DDRC |= (1<<5); // set SCL pin Input / Pull Low
}


////////////////////////////////////////////////////////


//------------------------------------------------------------------


int BitReadCombine( unsigned int x_high, unsigned int x_low)
{
	int combined;
	combined = x_high;              //send x_high to rightmost 8 bits
	combined = combined<<8;         //shift x_high over to leftmost 8 bits
	combined |= x_low;                 //logical OR keeps x_high intact in combined and fills in                                                             //rightmost 8 bits
	return combined;	  
}

//------------------------------------------------------------------



