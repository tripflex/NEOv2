```
                                     ___  ____  _____                     _           
__      ____      ____      __      / _ \/ ___||  ___|       ___ ___   __| | ___  ___ 
\ \ /\ / /\ \ /\ / /\ \ /\ / /     | | | \___ \| |_         / __/ _ \ / _` |/ _ \/ __|
 \ V  V /  \ V  V /  \ V  V /   _  | |_| |___) |  _|    _  | (_| (_) | (_| |  __/\__ \
  \_/\_/    \_/\_/    \_/\_/   (_)  \___/|____/|_|     (_)  \___\___/ \__,_|\___||___/
```
```
57 65 20 68 61 76 65 20 61 6c 6c 20 74 68 65 20 6c 69 67 68 74 20 77 65 20 6e 65 65 64 2c 20 77 65 20
6a 75 73 74 20 6e 65 65 64 20 74 6f 20 70 75 74 20 69 74 20 69 6e 20 70 72 61 63 74 69 63 65 2e 0d 0a
```

### Overview
---
This is an unofficial repository, I have no association with osm.codes other than my love for Ramiro and the fact that he has released an open source microlight.  ~~Check the OSM Mode Swap facebook group for latest version and information.~~

- **OSM v2 Instructions**:
  - http://osf.guru/viewtopic.php?f=20&t=25

*As of version 2.5.8br you need to use Arduino 1.6.5 as the latest version, 1.6.7 is currently not compatible*
- **Arduino 1.6.5**:
  - https://www.arduino.cc/en/Main/OldSoftwareReleases#previous

### Legal Battle
---
If you are not already aware, there was a legal battle between Ramiro (the creator of the OSM) and Emazing Farts ... i mean, Emazing Lights ... that resulted in a settlement which essentially prevents Ramiro from producing anymore OSMs, and forced him to take down all the facebook groups.  Since that time, we as a community have come together, and started http://osf.guru (or http://osf.codes), which stands for Open Souce Flow.  This is where you will find all the information you need, as well as tutorials, downloads, and more.

Thank you Ramiro for everything you have done, you have helped spark the fire that is Open Souce Flow, and we will continue on the path you started for us. 

**No matter how hard they try, or how much money they spend, they will not stop us, our creativity, or our innovation.  You can try to stifle innovation because of your greed, but in the end, we will prevail.**

### Details
---
* Credits: AAA_CREDITS.ino
* This Software is licensed under Creative Commons Attribution-ShareAlike 4.0

### Changelog
---
* **2.1b**    
  - Added "One Mode" toggle
  - Added Independent Prime color change
  - Fixed bugs
  - Changed Serial speed to 115200
  - MORE HIDDEN STUFF

* **2.1.5b**
  - BYE BYE LIBRARY

* *Self Contained project to avoid versions conflicts*

* **2.2**    
  - Compatibility with MMA86X  

* *Many things happened in between these versions*

* **2.3**
  - Tuned MMA86X speed clocks settings
  - Practically eliminated the stand alone MMA7660 library
  - Fixed Master reset
  - BEFORE BIG CHANGES TO V 3

* *Many things happened in between these versions*

* **2.4**
  - Fixed compatibility between the MMA family

* *Many things happened in between these versions*

* **2.5**      
  - Current Version

* **2.5.1bR**  
  - Beta Release

* **2.5.1bd**  
  - Beta Developer

* **2.5.2bd**  
  - Beta Developer
  - FIXING THE SLEEP MODE AFFECTING THE ACCELEROMETER RE-INIATILIZATON
  - OSM1 SUPPORT: UNCOMMENT LINE 88 FOR OSM SUPPORT (FIRST LINE OF THE PROGRAM)

* **2.5.3bd**
  - Added missing accelerometer sensitivity (Debug)
  - FIXING THE SLEEP MODE 	
  - OSM1 SUPPORT: UNCOMMENT LINE 92 FOR OSM SUPPORT (FIRST LINE OF THE PROGRAM)	   

* **2.5.4bd**  
  - Kroma variation  
  - Removed SLEEP MODE killer suspect

* **2.5.5bd**  
  - Dimmed Colors

* **2.5.61**  
  - Added delays to I2C

* **2.5.62**
  - Added EEPROM wipe

* **2.5.63**
  - I2C back delay CLEANUP
  - CTRL_REG1 CLEANUP
  - Changed modes

* **2.5.7br**  
  - (2.5.63 release)
  - Rule 11

* **2.5.75**
  - Added Battery Power ADC levels
  - ADC_I2C
  - Added TWADC.ino
  - Changed ACC_INIT.ino
  - Leaving comments on big changes for education purposes only.

* **2.5.7br-Kroma Edition / OSM1 & OSM**
  - Support for new accelerometer (OSM2).
  - Change one prime at the time with 3d gesture.
  -  New “Switch” mode
  -  Button Facing Up to change Prime A
  -  Button Facing Down to change Prime B
  -  Arduino: Support for Arduino 1.6.5
  -  No more library dependent.

* **2.5.8br OSM2POINT1 Compatible / OSM1 & OSM2.1**
  - Support for new configuration (OSM2.1).
  - Support for new accelerometer (OSM2).
  - Change one prime at the time with 3d gesture.
  - New “Switch” mode
  - Button Facing Up to change Prime A
  - Button Facing Down to change Prime B
  - Arduino: Support for Arduino 1.6.5
  - No more library dependent.
