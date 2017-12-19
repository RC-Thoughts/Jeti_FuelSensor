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
#define MAX_SCREEN 7

//
// Sensor ID (0x02) - Needs to be unique in a model
//
const unsigned char Jeti_SensorID4 = 0x06;

//
// Sensor variables & other init-stuff needed
//
// Jeti values
long uCons = 0;
long uFlow = 0;
int uFuel = 100;
// Sensor values
long count_raw = 0;
long count_last = 0;
long lastTime = 0;
long tankSize = 0;
long pulseCount = 0;
int calibDone = 0;
// Reset function
int pinReset = 5;
int resetFunction = 0;
int resetState = 0;
int flowActive = 0;
int consStored = 0;
long resetTime = 0;
long curTime = 0;
