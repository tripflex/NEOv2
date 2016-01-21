



void Alpha_Omega(void)// Blank Sleep
{//////////// Alpha_Omega
	JUSTONCE = 1;
	STATE = 1;
	
	if (!ONEMODE)
	{// if not ONEMODE
			
		while (digitalRead (BUTTON) == LOW)
		{// debounce
			osmPWM_Plane(0, 0, 0, 100);
		}// debounce
	
		//osmPWM_Plane(0, 128, 0, 10);
	

	}// fi not ONEMODE
	
	
	eeCheck();EEPROM.write(5,1);eeCheck();// went to sleep
	 	
	#if defined(VISUAL)
	//Serial.println();
	//Serial.println(F("I"));
	#endif

	osmPWM_Plane(0, 0, 0, 10);


	 	
	/////////////////////////////////////////////////////////////////////////
	 	
	//UserCmodes[CurrentUserBundle][CurrentUserMode];

	if (!ONEMODE)
	{
		eeCheck();
		EEPROM.write(2,CurrentUserBundle);eeCheck(); // CurrentUserBundle
		EEPROM.write(3,1);eeCheck(); // CurrentUserMode
	}
	
	else
	{
		Serial.println(F("~OFF~")); ////// debug
	}

	long CountDownSleep = 7200;// 7200 = 1:00 min (120 counts x second) 
	while ( (CountDownSleep > 0) && (digitalRead (BUTTON) == HIGH) )
	{
		CountDownSleep--;
		osmPWM_Plane(0, 0, 0, 10);
	}
	
	if (digitalRead (BUTTON) == LOW)
	{
		goto OutOfSleep;
	}


    Serial.println(F("... SLEEP~"));

	//// Watchdog Reset	////////////
	//I2C_MMA_standby();
	digitalWrite(LDO, LOW); // Power LDO off
	delay(30);
	
	wdt_enable(WDTO_15MS);
	
	Serial.println(F("wdt_enable(WDTO_15MS);"));
	while(1)
	{
		;
	}
	/////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////
	// THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
	
	
	OutOfSleep:
	if (!ONEMODE)
	{// if not ONEMODE
		delay(30);
	
		#if defined(VISUAL)
		Serial.println();
		Serial.println(F("... wakey wakey!"));
		#endif
//Serial.println(F("... I WAS HERE!... !ONEMODE"));////// DEBUG
	
		//////////////////////////////////////////////////////
		//delay(4000);
		//MMA7660.init();
		// check zflip here
		
		//MMA_Active();
		zAcc = 0;
		delay(40);
		//MMA7660.getRaw(&xAcc,&yAcc,&zAcc);
		I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);
		
		Serial.print(F("  Z: "));Serial.println(zAcc);
		if (zAcc < -1)// check zflip here
		{
			Zflipped = 1;
		}
		else
		{
			Zflipped = 0;
		}
		//////////////////////////////////////////////////////

	}// if not ONEMODE

				Zflip(); // Uncomment for default
				NoZflip();

	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////

	noInterrupts();	// disable interrupts

	if (AllYourBaseAreBelongToUs)// full blast factory reset
	{// AllYourBaseAreBelongToUs
		// reset here
		eeCheck();
		EEPROM.write(0,0);// Reset Version value
		eepromWriteFactory();
		eepromLoad();
		BLINKPWM(150,150,150 ,300,10);
		AllYourBaseAreBelongToUs = 0;
	}// AllYourBaseAreBelongToUs

	////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////

	CurrentOffCounter = 0;
	BPM_Counter=0;
	if (!ONEMODE)
	{// if NOT ONEMODE
			eeCheck();
			CurrentUserBundle   = EEPROM.read(2);eeCheck(); // CurrentUserBundle
			//CurrentUserMode     = EEPROM.read(3);eeCheck(); // CurrentUserMode
			CurrentUserMode = 1;
			MaxUserModes = UserCmodes[CurrentUserBundle][0];
	}// fi NOT ONEMODE
	
	else // One Mode
	
	{// else ONEMODE
		eeCheck();
		CurrentUserBundle   = EEPROM.read(2);eeCheck(); // CurrentUserBundle
		CurrentUserMode     = EEPROM.read(3);eeCheck(); // CurrentUserMode
		MaxUserModes = UserCmodes[CurrentUserBundle][0];
	}// esle ONEMODE

	
	Mode = UserCmodes[CurrentUserBundle][CurrentUserMode];	
	
	//if (SLIDERPRO_FLAG)
	//{
		//Mode = 100;
		//STATE = 3;
	//}
	//else
	//{
	    //Mode = UserCmodes[CurrentUserBundle][CurrentUserMode];	
	//}
			
	if (ONEMODE)
	{
	//Serial.print(F("Mode#: "));
	Serial.println(Mode);
	}
		
	eeCheck();EEPROM.write(5,0);eeCheck();// did not went to sleep		
	ToBorNotToB = 1;
	osmPWM_Plane(0, 0, 0, 1);
	Zflipped = 0;
	OFF_MODE = 0;
	STATE = 1;
	Click = 0;
	Int0count = 0;

	interrupts(); // enable interrupts
	
}// Alpha_Omega
/////////////////////////////////////////////








void Zflip(void) // BUNDLES CHANGES //  // FROM OFF BUTTON DOWN
{// void Zflip
	
	if ( (Zflipped) && (!ONEMODE) && (ClearToGo) )
		{
			OgooD = 0;
			CurrentUserBundle=0;// thank you Omar! (moved this line here)
		}
		
	while ((digitalRead (BUTTON) == LOW)  && (Zflipped))
	{// while Zflipped
		
		OgooD = 1;
		while ((CurrentUserBundle == 0) && (digitalRead (BUTTON) == LOW)  && (ClearToGo) ) // RED
		{
			OOOgood();
			BLINKPWM(30,0,0 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 1) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // GREEN
		{
			OOOgood();
			BLINKPWM(0,30,0 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 2) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // BLUE
		{
			OOOgood();
			BLINKPWM(0,0,30 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 3) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // PURPLE
		{
			OOOgood();
			BLINKPWM(15,0,15 ,100,2);
		}
		
		OgooD = 1;
		while ((CurrentUserBundle == 4) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // WHITE
		{
			OOOgood();
			BLINKPWM(10,10,10 ,100,2);
		}
		
	}// elihw Zflipped
	
		if (OgooD)// SAVE BUNDLE AND MODE 
		{
			noInterrupts();	// disable interrupts
			eeCheck();
			EEPROM.write(2,CurrentUserBundle);eeCheck();
			EEPROM.write(3,CurrentUserMode);eeCheck();
			OgooD = 0;
			interrupts(); // enable interrupts
		}
	
}// vdiov Zflip





void NoZflip(void) // FROM OFF BUTTON UP
{// void NoZflip
	while ((digitalRead (BUTTON) == LOW)  && (!Zflipped) )
	{// while Zflipped
		
    	if (ONEMODE)
		{
			BLINKPWM(0,0,0 ,0,0);
		}
		
		else
		
		{// else
			OgooD = 1;
			while ((CurrentOffCounter == 0) && (digitalRead (BUTTON) == LOW) ) // BLANK // NOTHING HAPPENS (RESERVED) // @ YETZIRAH
			{
				AllYourBaseAreBelongToUs = 0;
				ClearToGo = 1;
				BLINKPWM(0,0,0 ,50,2);
				SLIDERPRO_FLAG = 0;
			}
					
			OgooD = 1;
			while ((CurrentOffCounter == 1) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // GREEN  // NOTHING HAPPENS (RESERVED) // @ YETZIRAH
			{
				BLINKPWM(0,60,0 ,50,2);
				SLIDERPRO_FLAG = 1;
				
			}
					
			OgooD = 1;
			while ((CurrentOffCounter == 2) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // BLANK  // NOTHING HAPPENS (RESERVED) // @ YETZIRAH
			{
				BLINKPWM(0,0,0 ,50,2);
				SLIDERPRO_FLAG = 0;
				
			}
					
			OgooD = 1;
			while ((CurrentOffCounter == 3) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // BLANK  // NOTHING HAPPENS (RESERVED)  // @ YETZIRAH
			{
				BLINKPWM(0,0,0 ,50,2);
				SLIDERPRO_FLAG = 0;
			}
					
			OgooD = 1;
			while ( (CurrentOffCounter == 4) && (digitalRead (BUTTON) == LOW) && (ClearToGo) ) // WHITE ( MODE FACTORY DEFAULT )  // @ YETZIRAH
			{
				noInterrupts();	// disable interrupts
				BLINKPWM(70,70,70 ,150,40);
				AllYourBaseAreBelongToUs = 1;
				SLIDERPRO_FLAG = 0;
				ClearToGo = 0;
				interrupts(); // enable interrupts
			}
		}// esle

		
	}// elihw Zflipped
}// diov NoZflip



