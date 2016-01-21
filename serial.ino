// serial.ino


byte Sred;
byte Sgreen;
byte Sblue;
volatile byte inputChar ;
volatile char inChar;




/*
This is just a vanity welcome screen to the serial ouptut.
*/
void PrintWelcome1(void)
{
#if defined(VISUAL)
  //Serial.println(F("                               #######  #####  #     # "));
  //Serial.println(F("#    # #    # #    #           #     # #     # ##   ##            ####   ####  #####  ######  ####"));
  //Serial.println(F("#    # #    # #    #           #     # #       # # # #           #    # #    # #    # #      #"));
  //Serial.println(F("#    # #    # #    #           #     #  #####  #  #  #           #      #    # #    # #####   ####"));
  //Serial.println(F("# ## # # ## # # ## #    ###    #     #       # #     #    ###    #      #    # #    # #           #"));
  //Serial.println(F("##  ## ##  ## ##  ##    ###    #     # #     # #     #    ###    #    # #    # #    # #      #    #"));
  //Serial.println(F("#    # #    # #    #    ###    #######  #####  #     #    ###     ####   ####  #####  ######  ####"));
  
  Serial.println();
  Serial.print(F(" www.OSM.codes * ")); PRINTVERSION;
  Serial.println();
#endif  
}

void PrintWelcome2(void)
{
#if defined(VISUAL)
	//Serial.println();
	//Serial.println(F("        **************************************************"));
	Serial.println(F("        *           GREETINGS PROFESSOR FALKEN           *"));
	//Serial.println(F("        *                                                *"));
	//Serial.println(F("        *              SHALL WE PLAY A MODE?             *"));		
	//Serial.println(F("        **************************************************"));
	//Serial.println();
	//Serial.println(F("            ****************************************"));
	//Serial.println(F("            *      PLEASE CLICK YOUR SELECTION     *"));
	//Serial.println(F("            ****************************************"));		
	//Serial.println();
	//Serial.println();
	//Serial.println();
#endif	
}
