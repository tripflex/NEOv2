```
                                        ____   _____ __  __                     _
                                       / __ \ / ____|  \/  |                   | |
   __      ____      ____      __     | |  | | (___ | \  / |       ___ ___   __| | ___  ___
   \ \ /\ / /\ \ /\ / /\ \ /\ / /     | |  | |\___ \| |\/| |      / __/ _ \ / _` |/ _ \/ __|
    \ V  V /  \ V  V /  \ V  V /   _  | |__| |____) | |  | |  _  | (_| (_) | (_| |  __/\__ \
     \_/\_/    \_/\_/    \_/\_/   (_)  \____/|_____/|_|  |_| (_)  \___\___/ \__,_|\___||___/
```
```
57 65 20 68 61 76 65 20 61 6c 6c 20 74 68 65 20 6c 69 67 68 74 20 77 65 20 6e 65 65 64 2c 20 77 65 20
6a 75 73 74 20 6e 65 65 64 20 74 6f 20 70 75 74 20 69 74 20 69 6e 20 70 72 61 63 74 69 63 65 2e 0d 0a
```

### Overview
---
This is an unofficial repository, I have no association with osm.codes other than my love for Ramiro and the fact that he has released an open source microlight.  Check the OSM Mode Swap facebook group for latest version and information.

- **OSM v2 Instructions**:
  - http://osm.codes/web/wp-content/uploads/2015/12/OSM_NEO_2-5_instructions.jpg

*As of version 2.5.7br you need to use Arduino 1.6.5 as the latest version, 1.6.7 is currently not compatible*
- **Arduino 1.6.5**:
  - https://www.arduino.cc/en/Main/OldSoftwareReleases#previous



### Details
---
* Credits: AAA_CREDITS.ino
* ♒ NEO ♒ for the Open Source Microlight
* Version: v2 Series
* Date: 09-30-2015
* Company: Quantum Hex LLC
* Author: Ramiro Montes De Oca
* Product Page: http://www.osm.codes
* Support: http://support.osm.codes
* Facebook Users Group: https://www.facebook.com/groups/osmModeSwap/
* Facebook Dev Group: https://www.facebook.com/groups/OSMdevelopers/
* Facebook Product Page: https://www.facebook.com/osmcodes
*
* This Software is licensed under Creative Commons Attribution-ShareAlike 4.0
*

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
