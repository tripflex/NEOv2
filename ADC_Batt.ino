
long readVcc() {
	// Read 1.1V reference against AVcc
	// set the reference to Vcc and the measurement to the internal 1.1V reference
	#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
	ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
	#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
	ADMUX = _BV(MUX5) | _BV(MUX0);
	#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
	ADMUX = _BV(MUX3) | _BV(MUX2);
	#else
	ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
	#endif

	delay(20); // Wait for Vref to settle
	ADCSRA |= _BV(ADSC); // Start conversion
	while (bit_is_set(ADCSRA,ADSC)); // measuring

	uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH
	uint8_t high = ADCH; // unlocks both

	long result = (high<<8) | low;

	//result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
	result = 1090100L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
	return result; // Vcc in volts
}




double BattMeasurament(void)
{// void BattMeasurament
	float ResultHere = readVcc();
	ResultHere = ResultHere / 1000;
	return ResultHere;
	//////////////////////////////
}// diov BattMeasurament



void BattBlink(void)
{// void BattBlink
	//analogReference(1);// added OSMv2.1
	
	ADCSRA = ADCRASAVE;// added OSMv2.1
	ADCRASAVE = ADCSRA;// added OSMv2.1
	
	while (digitalRead (BUTTON) == LOW)
	{
		delay(1000);
	}
	
	delay(1000);
	int BattInput = readVcc();
	byte BatVal[4];
	Serial.print(F("> BATT LEVELS: "));
	
	BatVal[0]= BattInput/1000; 
	Serial.print(BatVal[0]); Serial.print(F("."));
	
	BatVal[1]= ( (BattInput/100) - (BatVal[0]*10)) ; 
	Serial.print(BatVal[1]);
	
	BatVal[2]= ( (BattInput/10) - (BatVal[0]*100) - (BatVal[1]*10) )  ;
	Serial.print(BatVal[2]);
	
	BatVal[3]= ( (BattInput) - (BatVal[0]*1000) - (BatVal[1]*100) - (BatVal[2]*10) )  ;
	Serial.print(BatVal[3]); Serial.println(F(" Volts"));
	
	delay(1000);
	BLINK(255,0,0,500,(BatVal[0])); BLINK(0,0,0,500,2);
	if (BatVal[1] < 1) {BLINK(0,30,0,50,30);BLINK(0,0,0,500,2);} else {BLINK(0,255,0,500,BatVal[1]); BLINK(0,0,0,500,2);}// 
	if (BatVal[2] < 1) {BLINK(0,0,30,50,30);BLINK(0,0,0,500,2);} else {BLINK(0,0,255,500,BatVal[2]); BLINK(0,0,0,500,2);}// 
	//if (BatVal[3] == 0) {BLINK(10,10,0,10,500);delay(1000);} else {BLINK(90,90,0,500,(BatVal[3]));delay(1000);delay(1000);}
	ToBorNotToB = 1;		
	
	
}// void BattBlink


void DeathLoop(void)
{// void DeathLoop
	/////////////// BATTERY CHECK
	int ReadBattLevels = readVcc();
	Serial.print(F("> BATT LEVELS: "));
	Serial.println(ReadBattLevels,DEC);
	ToBorNotToB = 1;
	while (ReadBattLevels < 2640 && ToBorNotToB)
	{
		digitalWrite(LDO, LOW); // Power LDO OFF
		DEATHLOOP:
		BLINKPWM(255,0,0,30,5);
		BLINKPWM(15,0,0,20,5);
		goto DEATHLOOP;
	}
	ToBorNotToB = 1;
	///////////////////////////////	
}// diov DeathLoop
