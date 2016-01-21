
// Author's Contributions:
// - pwms.ino
// - BPM.ino
// - BUILDERS.ino
// - ColorMode.ino
// - HeartBeat.ino
// - Interrupts.ino
// - modeChange.ino
// - Morphed_Plus.ino
// - OSMserial.ino
// - PRIMES.ino
// - pus.ino
// - pwms.ino
// - SleepMode.ino
// - TripleRainbow.ino
// Quantum Hex LLC / Ramiro Montes De Oca / 2015

//THIS CODE IS DISTRIBUTED UNDER CREATIVE COMMONS SHARE ALIKE 4.0
//Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
//You are free to:
//Share � copy and redistribute the material in any medium or format
//Adapt � remix, transform, and build upon the material
//for any purpose, even commercially.
//The licensor cannot revoke these freedoms as long as you follow the license terms.
//Under the following terms:
//Attribution � You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
//ShareAlike � If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
//http://creativecommons.org/licenses/by-sa/4.0/legalcode
//Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
//
//
//ACKNOWLEDGE:
//
//Modified code out of:
//- Reading a serial ASCII-encoded string. / created 13 Apr 2012 / by Tom Igoe (Arduino.cc)
//- Serial Event / Created 9 May 2011 / by Tom Igoe (Arduino.cc)
//- PWM Frequencies / 02-15-2012 / by yanngg (Arduino.cc)
//- Timer interrupts / June 2012 / by Amanda Ghassaei
//
//Libraries:
//- <avr/sleep.h>  * Copyright (C) 2006 MacSimski 2006-12-30 / Copyright (C) 2007 D. Cuartielles 2007-07-08 - Mexico DF


//
//
//      Imagine a world without real alternatives... 
//      Well, stop imagining and thank yourself for making this possible!
//      
//      
//              ,----,                                                                ,---,  
//            ,/   .`|       ,--,                        ,--.       ,--.           ,`--.' |  
//          ,`   .'  :     ,--.'|   ,---,              ,--.'|   ,--/  /| .--.--.   |   :  :  
//        ;    ;     /  ,--,  | :  '  .' \         ,--,:  : |,---,': / '/  /    '. '   '  ;  
//      .'___,/    ,',---.'|  : ' /  ;    '.    ,`--.'`|  ' ::   : '/ /|  :  /`. / |   |  |  
//      |    :     | |   | : _' |:  :       \   |   :  :  | ||   '   , ;  |  |--`  '   :  ;  
//      ;    |.';  ; :   : |.'  |:  |   /\   \  :   |   \ | :'   |  /  |  :  ;_    |   |  '  
//      `----'  |  | |   ' '  ; :|  :  ' ;.   : |   : '  '; ||   ;  ;   \  \    `. '   :  |  
//          '   :  ; '   |  .'. ||  |  ;/  \   \'   ' ;.    ;:   '   \   `----.   \;   |  ;  
//          |   |  ' |   | :  | ''  :  | \  \ ,'|   | | \   ||   |    '  __ \  \  |`---'. |  
//          '   :  | '   : |  : ;|  |  '  '--'  '   : |  ; .''   : |.  \/  /`--'  / `--..`;  
//          ;   |.'  |   | '  ,/ |  :  :        |   | '`--'  |   | '_\.'--'.     / .--,_     
//          '---'    ;   : ;--'  |  | ,'        '   : |      '   : |     `--'---'  |    |`.  
//                   |   ,/      `--''          ;   |.'      ;   |,'               `-- -`, ; 
//                   '---'                      '---'        '---'                   '---`"  
//                                                                                        
//  To the original Dev Crowd @ 
//  https://www.facebook.com/groups/OSMdevelopers/
//
//  AARON SON
//  ADAM LUSSIER
//  ANDREW SUCHAN
//  ANDY GABRIEL
//  BRUCE NEAL ALVAREZ
//  GABRIELLE LIANA
//  JAT GOODWIN
//  JONATHAN FOSTER
//  MICHAEL PIVONKA
//  NOAH LITOV
//  RAYMOND STONE
//  THEO DEE
//
//      ... and the Kickstarter backers:
//      
//      [3M]~Raffi
//      [EMT][LB][NL]Tikieeky
//      [VT][NL] Mayhem
//      1ndustrial
//      Aaron Son
//      Alec
//      Alex Meissner
//      Andrew Suchan
//      ballk00zie
//      Binka
//      Bird&Cricket
//      Brendan Emler
//      Brenndan Thomas
//      Brock Wilmer
//      Bruce Alvarez
//      Chris Ziegler
//      Cletus Ugenes
//      Clinten R. Campbell
//      Colin Flaherty
//      Conner staton
//      David benabu
//      David Boyd
//      Dele Eribo
//      desmond kim
//      DTseng
//      Dylan Conger
//      Dylan DeArmond
//      Dylan fabozzi
//      eeka eric
//      Eric Pan
//      Erlan calilung
//      Ezra Davis
//      FresnoTranceFamily
//      Garrett Pacheco
//      Greg Roberti
//      HawaiiLoa Durante
//      Hayden Yeung
//      Henry Q
//      Holger Willeke
//      Hunter Bruno- [IYF] Finn
//      Ian Yates Hopkins -- iBot
//      Jacoby Dooley
//      James Luong
//      James Mort
//      Jasmine Franklin
//      Jeffporqupine
//      Jeffrey McHatton -Nonsense
//      Joe Pagano (Wheatyz)
//      Joey “muze“
//      Jonathan Bradley-Gowan
//      Jonathan cronque
//      Jong Kyu Jung
//      Jordan Ritchie
//      Jovam Gumball Villegas
//      Justin $ʞƏƤ†!☪ɅⱢ Drzymkowski
//      K. Dunn
//      Kan Pang
//      kandekreations
//      Keaton Webley
//      Kellen Linse
//      Kevin Britz
//      Kevin Keovixay
//      Kieran Junge
//      Kira W.
//      Kole Seeber
//      Kory Donlon
//      Kyle Corbett
//      Kyle Jones
//      Lifted N Gifted
//      Linh Mai
//      Logan “The Warlock“ Pereira
//      Lucas Nance
//      Mack Dean
//      Maliq
//      Marco Castillo
//      Masha Paramonova
//      Mat Choi
//      Matt “Lycan“ Lee
//      Matthew D Rentz
//      Michael Mahan
//      Michael Marchette
//      Miles M.D.I.
//      "Morgan Stangle 
//      Mary Tippens"
//      Mountain Evan Chang
//      Neil “phozee“ Merchant
//      Nikita Ivanov
//      Noah Litov
//      Omar A Hakim
//      Oscar Alegria
//      Paul Faryna
//      Paul Piffery Hugo
//      Rated-E
//      Ruben D
//      Ryan Gessner
//      Sean Andrew Cain
//      seanbeanjovi
//      Shane Bumpus
//      Sir Macbeth
//      Stephanie A. Chuah
//      Steve Nguyen
//      Steven HungZoR Nguyen
//      Symplicity
//      Taco Nelson- Abroham Blinkin
//      Theodore D 'Tdot'
//      Trey wolf
//      Tuan Mai
//      Vincent “The Poet“ Coleman
//      Wavicle
//      Wheellis
//      Taylor Alsleben
//      Zero
//      
//      ... and the rest who desire to be Anonymous to the Kickstarter pledge...
//      Thank you!
//      
//      
//      Ramiro Montes De Oca
//      Quantum HEX LLC
//      www.osm.codes

