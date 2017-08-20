//
// Stuff done in initialisation of sketch
//

// Jetibox Start Screen
//
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F("  Fuel Sensor")

//
// Max screens in jetibox (navigating over this goes to start)
//
#define MAX_SCREEN 5

//
// Sensor ID (0x02) - Needs to be unique in a model
//
const unsigned char Jeti_SensorID4 = 0x06;

//
// Sensor variables & other init-stuff nede
//
// Jeti values
long uCons = 0;
long uFlow = 0;
// Sensor values
int count_raw = 0;
int count_last = 0;
long lastTime = 0;
float calVal = 1000;
