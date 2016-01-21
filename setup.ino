// setup.ino


void OSMsetup(void)
{
	
	////#define RED      9   // RED LED
	////#define GREEN    6   // GREEN LED
	////#define BLUE     5   // BLUE LED
	////#define BLUE_ARD 13  // BLUE_ARDUINO LED
	////#define LDO      A3  // LDO ENABLE
	////#define DEBUG    7   // DEBUG PIN
	
	
    /// POWER LDO
    pinMode(LDO, OUTPUT);// Prep Output power to LDO
    //digitalWrite(LDO, HIGH); // Power LDO ON
	
	//randomSeed(analogRead(0));
	

	// MMA PIN INTERRUPT pins, they're set as active high, push-pull
	pinMode(3, INPUT);   // interrupt pin
	digitalWrite(3, LOW);
	
    // LED SETUP
    pinMode(BLUE, OUTPUT); // BLUE
    pinMode(GREEN, OUTPUT); // GREEN
    pinMode(RED, OUTPUT); // RED
    pinMode(BLUE_ARD, INPUT_PULLUP); // ARDUINO 13 BLUE
	pinMode(DEBUG, OUTPUT); // Debug Pin on Pin 14
	digitalWrite(RED, LOW);
	digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW); // BLUE ON (just to know that we are here)
	digitalWrite(BLUE_ARD, LOW);
}


void SerialSetup(void)
{
	
	//power_usart0_disable();// check
	//power_spi_disable(); // check
	//ADCSRA = 0; // Disable ADC // check
	
Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
Serial.println(F("> Serial ON")); Serial.println();

#if defined(VISUAL)
Serial.println(F("VISUAL ENVIRONMENT VERSION")); Serial.println();
#else
Serial.println(F("BLIND VERSION")); Serial.println();
#endif

inputString.reserve(200);
delay(20);
}


void TimerMax(void)
{// void TimerMax
	// SET TIMER0 AND TIMER1
	TCCR0B = (TCCR0B & 0b11111000) | 0x01; // Timer 0 for pin 5 & 6
	TCCR1B = (TCCR1B & 0b11111000) | 0x01; // Timer 1 for pin 9 & 10

	//SET TIMER2 INTERRUPT 16.40ms
	TCCR2A = 0;// TCCR2A REG
	TCCR2B = 0;// TCCR2B REG
	TCNT2  = 0;// INITIALIZE TO ZERO
	// 1024 pre-scaler
	TCCR2B |= (1 << CS22);
	TCCR2B |= (1 << CS21);
	TCCR2B |= (1 << CS20);

	TIMSK2 |= (1 << OCIE2A); // TIMER2 INTERRUPT ENABLE


////////////////// not activated
//CLKPR = 0x80;
//CLKPR = 0x02;
/////////////////////////////////

}// diov TimerMax



void debug(volatile boolean DebugBool)
{
	//if (DebugBool)
	//{
	//digitalWrite(DEBUG, HIGH);
	//}
	//else
	//{
	//digitalWrite(DEBUG, LOW);
	//}
}                          







void handleSerial() 
{// VOID 
	//uint8_t in0, in1, in2, in3;
	//if (Serial.available() >= 4) 
	//{// IF SERIAL
		//in0 = Serial.read();
		//in1 = Serial.read();
		//in2 = Serial.read();
		//in3 = Serial.read();
	//
		//
		//Serial.print(F("YOU JUST SENT: "));
		//Serial.println(in0);
		//
		//Serial.print(F("YOU JUST SENT: "));
		//Serial.println(in1);
		//
		//Serial.print(F("YOU JUST SENT: "));
		//Serial.println(in2);
		//
		//Serial.print(F("YOU JUST SENT: "));
		//Serial.println(in3);
		//Serial.flush();
     //}
		//
}
