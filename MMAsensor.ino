// MMAsensor.ino


volatile boolean ShakeX;
volatile boolean ShakeY;
volatile boolean ShakeZ;

//--------------------------------------------------------------------------------------------------

void mmaSensor( byte MMAselectMMA, byte mmaAxisMMA, int SensCounterMMA, byte PAccelSensitivityMMA )
{// void mmaSensor
	
////=====================================================================================================
	if (STATE == 1)// only available on Mode Play
	{// if STATE

////===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--===--TILT--==		
		/////////////////////////////////////////////////////////////////////////////////////////////////
		if ((MMAselectMMA == 1) && (ToBorNotToB))// Tilt
		{// if Tilt
			int Accel[3];
			accelCounter++;
			if (accelCounter>SensCounterMMA)
			{// if SenseY
				
							 
                I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);
				
				Accel[0] = xAcc;
				Accel[1] = yAcc;
				Accel[2] = zAcc;
				
				if ((Accel[mmaAxisMMA])  > 1 && (ToBorNotToB))
				{// if Tilt
					if (VARIATION == 0) {;}
					else
					{VARIATION = 0; ToBorNotToB = 0;}
				}// fi Tilt
				
				if ((Accel[mmaAxisMMA])  < 1 && (ToBorNotToB))
				{// if Tilt
					if (VARIATION == 1) {;}
					else
					{VARIATION = 1; ToBorNotToB = 0;}
				}// fi Tilt
				
				xAcc = 0;// clear
				yAcc = 0;// clear
				zAcc = 0;// clear
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
			if (accelCounter>(SensCounterMMA) && (ToBorNotToB))
			{// if accelCounter
				I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);

				if (OSMONE)
				{// if OSM1
					if ((xAcc < 37) && (xAcc > 24) )   {ShakeX = 1;} else {ShakeX = 0;}
					if ((yAcc < 37) && (yAcc > 24) )   {ShakeY = 1;} else {ShakeY = 0;}
					if ((zAcc < 37) && (zAcc > 24) )   {ShakeZ = 1;} else {ShakeZ = 0;}
				}// fi OSM1

				else
				{// if OSM2
					if ((xAcc < (-abs(PAccelSensitivityMMA)) ) || (xAcc > PAccelSensitivityMMA) )   {ShakeX = 1;} else {ShakeX = 0;}
					if ((yAcc < (-abs(PAccelSensitivityMMA)) ) || (yAcc > PAccelSensitivityMMA) )   {ShakeY = 1;} else {ShakeY = 0;}
					if ((zAcc < (-abs(PAccelSensitivityMMA)) ) || (zAcc > PAccelSensitivityMMA) )   {ShakeZ = 1;} else {ShakeZ = 0;}
				}//
								

				accelCounter=0;
				if ( ShakeX || ShakeY || ShakeZ )
				{// if Shake
					if (VARIATION == 1) {;}
					
					else
					{VARIATION = 1; ToBorNotToB = 0;}
					
					ShakeX = 0;
					ShakeY = 0;
					ShakeZ = 0;
				}// fi Shake
				else
				{// else
					VARIATION = 0;
					//if (VARIATION == 1) {ToBorNotToB = false;}
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
			
			
			if (accelCounter>(SensCounterMMA) && (ToBorNotToB))
			{// if accelCounter
				I2C_ACC_GET_XYZ(&xAcc,&yAcc,&zAcc);

				if (OSMONE)
				{// if OSM1
				if ((xAcc < 37) && (xAcc > 24) )   {ShakeX = 1;} else {ShakeX = 0;}
				if ((yAcc < 37) && (yAcc > 24) )   {ShakeY = 1;} else {ShakeY = 0;}
				if ((zAcc < 37) && (zAcc > 24) )   {ShakeZ = 1;} else {ShakeZ = 0;}
				}// fi OSM1


				else
				{// if OSM2
					if ((xAcc < (-abs(PAccelSensitivityMMA)) ) || (xAcc > PAccelSensitivityMMA) )   {ShakeX = 1;} else {ShakeX = 0;}
					if ((yAcc < (-abs(PAccelSensitivityMMA)) ) || (yAcc > PAccelSensitivityMMA) )   {ShakeY = 1;} else {ShakeY = 0;}
					if ((zAcc < (-abs(PAccelSensitivityMMA)) ) || (zAcc > PAccelSensitivityMMA) )   {ShakeZ = 1;} else {ShakeZ = 0;}
				}//
								

				accelCounter=0;

				if ( ShakeX || ShakeY || ShakeZ )
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
					
					Debouncer = 1;
					ShakeX = 0;
					ShakeY = 0;
					ShakeZ = 0;
				}// fi Shake

				
			}// fi accelCounter
		}// fi SWITCH
		///////////////////////////////////////////////////////////////////////////////////////////////////	
//////===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--===--SWITCH--



	}// fi STATE
}// diov mmaSensor

//--------------------------------------------------------------------------------------------------








//void FreeFall()
//{
	  //// Read source of interrupt
	  //intSource = I2C_readByte(MMA8652_INT_SOURCE);
//
	  //if(intSource & SRC_FF_MT_MASK)
	  //{
		  //if (OnlyONce)
		  //{
			  //if (VARIATION)
			  //{
				  //VARIATION = 0;
			  //}
			  //else
			  //{
				  //VARIATION = 1;
			  //}
		  //}
//
	  //}
	  //
	  //else
	  //{
		  //OnlyONce = 1;
	  //}
	  //
//}








