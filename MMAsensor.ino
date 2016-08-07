// MMAsensor.ino


//volatile boolean ShakeX;/// DISABLED FOR V2.1
//volatile boolean ShakeY;/// DISABLED FOR V2.1
//volatile boolean ShakeZ;/// DISABLED FOR V2.1
volatile boolean ShakeXYZ;// ADDED FOR OSMV2.1


//--------------------------------------------------------------------------------------------------

void mmaSensor( byte MMAselectMMA, byte mmaAxisMMA, int SensDebouncer, int PAccelSensitivityMMA )
{// void mmaSensor
	
////=====================================================================================================
	if (STATE == 1)// only available on Mode Play
	{// if STATE

////===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--==		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		if ((MMAselectMMA == 1) && (ToBorNotToB))// Tilt
		{// if Tilt
			
			accelCounter++;
			if (accelCounter>SensDebouncer)
			{// if SenseY
		         
				//int Accel[3];/// DISABLED FOR OSMV2.1
                //I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);/// DISABLED FOR OSMV2.1
				//Accel[0] = xAcc;/// DISABLED FOR OSMV2.1
				//Accel[1] = yAcc;/// DISABLED FOR OSMV2.1
				//Accel[2] = zAcc;/// DISABLED FOR OSMV2.1
				
				int AccelResult = TWADC_ACC_GET_VAL(mmaAxisMMA);// ADDED FOR OSMV2.1
				
				if ((AccelResult)  > 1 && (ToBorNotToB))// CHANGED ON V2.1
				{// if Tilt
					if (VARIATION == 0) {;}
					else
					{VARIATION = 0; ToBorNotToB = 0;}
				}// fi Tilt
				
				if ((AccelResult)  < 1 && (ToBorNotToB))// CHANGED ON V2.1
				{// if Tilt
					if (VARIATION == 1) {;}
					else
					{VARIATION = 1; ToBorNotToB = 0;}
				}// fi Tilt
				
				//xAcc = 0;/// DISABLED FOR OSMV2.1
				//yAcc = 0;/// DISABLED FOR OSMV2.1
				//zAcc = 0;/// DISABLED FOR OSMV2.1
				AccelResult = 0;// ADDED FOR OSMV2.1
				accelCounter=0;
			}// fi Sensey
		}// fi Tilt
////===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--==			
		/////////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////////
////===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE--		
		if ((MMAselectMMA == 2) && (ToBorNotToB))// Shake
		{// if Shake
			accelCounter++;
			if (accelCounter>(SensDebouncer) && (ToBorNotToB))
			{// if accelCounter
				//I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);// DISABLED

                int AccelResultIs = TWADC_ACC_GET_VAL(mmaAxisMMA);// ADDED FOR OSMV2.1
				
				if (OSMONE)
				{// if OSM1
					//if ((xAcc < 37) && (xAcc > 24) )   {ShakeX = 1;} else {ShakeX = 0;}/// DISABLED FOR OSMV2.1
					//if ((yAcc < 37) && (yAcc > 24) )   {ShakeY = 1;} else {ShakeY = 0;}/// DISABLED FOR OSMV2.1
					//if ((zAcc < 37) && (zAcc > 24) )   {ShakeZ = 1;} else {ShakeZ = 0;}/// DISABLED FOR OSMV2.1
					if ((AccelResultIs < 37) && (AccelResultIs > 24) )   {ShakeXYZ = 1;} else {ShakeXYZ = 0;}// ADDED FOR OSMV2.1
				}// fi OSM1

				else
				{// if OSM2
					//if ((xAcc < (-abs(PAccelSensitivityMMA)) ) || (xAcc > PAccelSensitivityMMA) )   {ShakeX = 1;} else {ShakeX = 0;}/// DISABLED FOR OSMV2.1
					//if ((yAcc < (-abs(PAccelSensitivityMMA)) ) || (yAcc > PAccelSensitivityMMA) )   {ShakeY = 1;} else {ShakeY = 0;}/// DISABLED FOR OSMV2.1
					//if ((zAcc < (-abs(PAccelSensitivityMMA)) ) || (zAcc > PAccelSensitivityMMA) )   {ShakeZ = 1;} else {ShakeZ = 0;}/// DISABLED FOR OSMV2.1
					  if ((zAcc < (-abs(PAccelSensitivityMMA)) ) || (AccelResultIs > PAccelSensitivityMMA) )   {ShakeXYZ = 1;} else {ShakeXYZ = 0;}	// ADDED FOR OSMV2.1
				}// fi OSM2
								

				accelCounter=0;
				//if ( ShakeX || ShakeY || ShakeZ )/// DISABLED FOR OSMV2.1
				if ( ShakeXYZ )// ADDED FOR OSMV2.1
				{// if Shake
					if (VARIATION == 1) 
					{;}
					
					else
					{
						VARIATION = 1; ToBorNotToB = 0;
					}
					
					//ShakeX = 0;/// DISABLED FOR OSMV2.1
					//ShakeY = 0;/// DISABLED FOR OSMV2.1
					//ShakeZ = 0;/// DISABLED FOR OSMV2.1
					ShakeXYZ = 0;// ADDED FOR OSMV2.1
				}// fi Shake
				
				else
				
				{// else
					VARIATION = 0;
				}// esle
				
			}// fi accelCounter
		}// fi Shake

////===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE===--SHAKE--			
		/////////////////////////////////////////////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////////////////////////////////////////////		
//////===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--
		if ((MMAselectMMA == 3) && (ToBorNotToB))// SWITCH
		{// if SWITCH
			
			///////////////////////// Debounce
			if (Debouncer > 0)
			{
				Debouncer++;
				if (Debouncer > 1000)
				{
					Debouncer = 0;
				}
			}
			else
			{
				accelCounter++;
			}
			////////////////////// Debounce
			
			
			if (accelCounter>(SensDebouncer) && (ToBorNotToB))
			{// if accelCounter
				//I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);/// DISABLED FOR OSMV2.1
			    int AccelResult = TWADC_ACC_GET_VAL(mmaAxisMMA);// ADDED FOR OSMV2.1
				
				if (OSMONE)
				{// if OSM1
				//if ((xAcc < 37) && (xAcc > 24) )   {ShakeX = 1;} else {ShakeX = 0;}/// DISABLED FOR OSMV2.1
				//if ((yAcc < 37) && (yAcc > 24) )   {ShakeY = 1;} else {ShakeY = 0;}/// DISABLED FOR OSMV2.1
				//if ((zAcc < 37) && (zAcc > 24) )   {ShakeZ = 1;} else {ShakeZ = 0;}/// DISABLED FOR OSMV2.1
				if ((AccelResult < 37) && (AccelResult > 24) )   {ShakeXYZ = 1;} else {ShakeXYZ = 0;}// ADDED FOR OSMV2.1
				}// fi OSM1


				else
				{// if OSM2
					//if ((xAcc < (-abs(PAccelSensitivityMMA)) ) || (xAcc > PAccelSensitivityMMA) )   {ShakeX = 1;} else {ShakeX = 0;}/// DISABLED FOR OSMV2.1
					//if ((yAcc < (-abs(PAccelSensitivityMMA)) ) || (yAcc > PAccelSensitivityMMA) )   {ShakeY = 1;} else {ShakeY = 0;}/// DISABLED FOR OSMV2.1
					//if ((zAcc < (-abs(PAccelSensitivityMMA)) ) || (zAcc > PAccelSensitivityMMA) )   {ShakeZ = 1;} else {ShakeZ = 0;}/// DISABLED FOR OSMV2.1
					if ((AccelResult < (-abs(PAccelSensitivityMMA)) ) || (AccelResult > PAccelSensitivityMMA) )   {ShakeXYZ = 1;} else {ShakeXYZ = 0;}// ADDED FOR OSMV2.1
				}//
								

				accelCounter=0;

				//if ( ShakeX || ShakeY || ShakeZ )/// DISABLED FOR OSMV2.1
				if ( ShakeXYZ )// ADDED FOR OSMV2.1
				{// if Shake
					if (VARIATION == 1) 
					{
						VARIATION = 0;
						ToBorNotToB = 0;
						
					}
					
					else
					
					{
						VARIATION = 1;
						ToBorNotToB = 0;
					}
					//Serial.print("AccelResult: ");Serial.print(AccelResult,DEC); // debug
					//Serial.print("   PAccelSensitivityMMA: ");Serial.println(PAccelSensitivityMMA,DEC); // debug
				Debouncer = 1;
				//xAcc = 0;/// DISABLED FOR OSMV2.1
				//yAcc = 0;/// DISABLED FOR OSMV2.1
				//zAcc = 0;/// DISABLED FOR OSMV2.1
				AccelResult = 0;// ADDED FOR OSMV2.1
				}// fi Shake

				
			}// fi accelCounter
		}// fi SWITCH
		///////////////////////////////////////////////////////////////////////////////////////////////////	
//////===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--



	}// fi STATE
}// diov mmaSensor

//--------------------------------------------------------------------------------------------------











