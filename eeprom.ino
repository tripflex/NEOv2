///////////////////
///////////////////
// eeprom.ino
///////////////////
///////////////////


void eeCheck(void)
{// void eeCheck
 while ( !eeprom_is_ready () ) { ; } ;
}// diov eeCheck







/////// FACTORY DEFAULT ROUTINE
void eepromWriteFactory(void) 
{// void eepromWriteFactory
	noInterrupts();	
	eeCheck();
	
	#if defined(VISUAL)
		Serial.print(F(">EEPROM VERSION "));
		eeCheck();
		Serial.println(EEPROM.read(0),DEC);
		eeCheck();
	#endif
	
    //	if (1) /// force change
	
	MemCheck = EEPROM.read(0);
	eeCheck();
	

	
	
	//MemCheck = 1; /// super force change comment this after test
	
	if (MemCheck == CurrentVersion) /// IF EEPROM BANK 0 == 0x42
	{
		#if defined(VISUAL)	
			Serial.println(F(">VERSION MATCH!"));	
	    #endif
	}
	else
	{
		
		#if defined(VISUAL)
			Serial.print(F(">...UPLOADING NEW VERSION "));
		#endif
		
		byte DeleteCounter = 19;
		while (DeleteCounter > 0)
		{
			eeCheck();EEPROM.write(DeleteCounter,0);eeCheck();
			DeleteCounter--;
		} 
		
		eeCheck();
		EEPROM.write(0,0);// Reset Version value
		eeCheck();
		EEPROM.write(1,0);eeCheck();// Reset ONEMODE
		EEPROM.write(2,0);eeCheck();// Reset CurrentUserBundle
		EEPROM.write(3,1);eeCheck();// Reset CurrentUserMode
		
		ONEMODE = 0;
		CurrentUserBundle = 0;
		CurrentUserMode = 0;
			
		PROGset = 0;
		PROGMEMbank = 0;
		EEbank = 0;
		while (EEbank != 468)// was 864
		{// while ClearCount
			eeCheck();
			EEPROM.write((EEbank+20), (pgm_read_word_near(&(ModeSetFLASH[PROGset][(PROGMEMbank)]))));
			eeCheck();
			EEbank++;
			PROGMEMbank++;
			if (PROGMEMbank == 36) {PROGset++; PROGMEMbank=0;}
		}// elihw ClearCount
		
		//eeCheck();
		//DumpEEprom();
		//eeCheck();
		
		#if defined(VISUAL)
			Serial.print(F(">...NEW EEPROM VERSION "));
			eeCheck();
			Serial.println(EEPROM.read(0),DEC);
			eeCheck();
		#endif
		
		
		eeCheck();
		EEPROM.write(0,CurrentVersion);
		eeCheck();
    	
		#if defined(VISUAL)
			Serial.println(EEPROM.read(0));
		eeCheck();
	    #endif
	}
    interrupts();
}// diov eepromWriteFactory






/////// LOAD EEPROM
void eepromLoad(void)
{// void eepromLoad
	noInterrupts();
	#if defined(VISUAL)	
		Serial.print(F(">LOADING....EEPROM VERSION "));
		eeCheck();
		Serial.print(EEPROM.read(0),DEC);
		eeCheck();
		Serial.println(F(" TO SRAM"));
	#endif
	
	eeCheck();
	EEbank = 20;
	PROGset = 0;
	PROGMEMbank = 0;
	
	while (EEbank != 488)
	{
		eeCheck();
		ModeSetSRAM[PROGset][PROGMEMbank] = EEPROM.read(EEbank);
		eeCheck();
		EEbank++;
		PROGMEMbank++; 
		if (PROGMEMbank == 36) {PROGset++; PROGMEMbank=0;}
		eeCheck();
	}
    
	//eeCheck();
	//DumpSRAM();	
	//eeCheck();
	
	#if defined(VISUAL)
		Serial.print(F(">LOADED.... EEPROM VERSION "));
		eeCheck();
		Serial.print(EEPROM.read(0),DEC);
		eeCheck();
		Serial.println(F(" TO SRAM!"));
	#endif
	interrupts();
	
}// diov eepromLoad




//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////// DO NOT DELETE ////////////////////////////////////////
/////////////////////////////////////////////////////////////////
   ////////////////////////////////
        ////////////////////
		     ///////////
			    /////
				 //


#if defined(EEPROM_DEBUG)

///// LOAD EEPROM
void DumpSRAMss(void)
{// void eepromLoad
	noInterrupts();
	eeCheck();
	EEbank = 20;
	PROGset = 0;
	PROGMEMbank = 0;
	
	while (EEbank != 488)// was 884
	{
		eeCheck();
		ModeSetSRAM[PROGset][PROGMEMbank] = EEPROM.read(EEbank);
		eeCheck();
		EEbank++;
		PROGMEMbank++;
		if (PROGMEMbank == 36) {PROGset++; PROGMEMbank=0;}
		eeCheck();
	}
	eeCheck();
	Serial.print(F(">LOADED.... EEPROM VERSION "));
	eeCheck();
	Serial.print(EEPROM.read(0),DEC);
	eeCheck();
	Serial.println(F(" TO SRAM!"));
	interrupts();
	
}// diov eepromLoad






void DumpEEprom (void)
{
ek = 20;
uuu = 1;
kk = 1;
Serial.println();
Serial.println();
Serial.println();
Serial.println(F("> EEPROM start at 0x20"));
	while (uuu < 14)
	{// uuu
			while  (kk < 3)
			{// kk
					while (k < 18)
					{// k
						eeCheck();
						Serial.print(EEPROM.read(ek),DEC); Serial.print(F(", "));
						eeCheck();
						ek++;
						k++;
					}// k
				Serial.print(F(" // Mode "));  Serial.print(uuu);  
				Serial.print(F(" (Prime ")); 
    				                         if (kk==1){Serial.print(F("A"));}
											 if (kk==2){Serial.print(F("B"));}
				
				Serial.println(F(")  EEPROM"));
				k=0;
				kk++;
			}// kk
		Serial.println();
		kk = 1;	   
		uuu++;
	}// uuu 
}





void DumpSRAM(void)
{
	Serial.println();
	Serial.println();
	
	EEbank = 20;
	ek = 20;
	uuu = 1;
	kk = 1;
	
	eeCheck();
	EEbank = 20;
	PROGset = 0;
	PROGMEMbank = 0;
	
	while (EEbank != 488)// was 884
	{// uuu
		while  (kk < 3)
		{// kk
			while (k < 18)
			{// k
				//Serial.print(eepromRead(ek),DEC); Serial.print(", ");
				
				Serial.print((ModeSetSRAM[PROGset][PROGMEMbank]),DEC); Serial.print(F(", "));
				EEbank++;
				PROGMEMbank++;
				if (PROGMEMbank == 36) {PROGset++; PROGMEMbank=0;}
				
				ek++;
				k++;
			}// k
			Serial.print(F(" // Mode "));  Serial.print(uuu);
			Serial.print(F(" (Prime "));
										if (kk==1){Serial.print(F("A"));}
										if (kk==2){Serial.print(F("B"));}
			Serial.println(F(") SSRAM"));
			k=0;
			kk++;
		}// kk
		Serial.println();
		kk = 1;
		uuu++;
	}// uuu
}

#endif

