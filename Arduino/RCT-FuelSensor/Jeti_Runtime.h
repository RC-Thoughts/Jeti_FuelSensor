// 
// This is the main loop where the work is done
// May the flow be with you
// 

// Total consumption (calibrated)
uCons = ((double)count_raw / ( pulseCount / 1000 ));
if ( uCons < 0 ) {
  uCons = 0;
}

// Fuel gauge in percent
if ( tankSize > 0 && uCons > 0 ) {
  float tank = tankSize;
  float cons = uCons;
  uFuel = 100 - ( 100 / ( tank / cons ) );
  if ( uFuel < 0 ) {
    uFuel = 0;
  }
}

//Calc fuel flow in ml/m
if ( millis() > lastTime + 1000 && millis() > 5000 )
{
  int diff = millis() - lastTime;
  int timeCount = count_raw - count_last;
  uFlow = ( (double)timeCount / ( pulseCount / 1000 ) * 60 / ( (double)diff / 1000 ) );
  lastTime = millis();
  count_last = count_raw;
}
if (uFlow < 0) {
  uFlow = 0;
}

// If reset-function is in use and fuel is flowing monitor fuel-flow and set timer
if (resetFunction == 1 && uFlow > 0 && uCons > 0) {
  flowActive = 1;
  consStored = 0;
  resetTime = millis() + 15000; // If no fuel-flow 15 seconds timer to store value to EEPROM
} else {
  flowActive = 0;
}

// If reset-function is in use and if no fuel-flow for 15 seconds store consumed fuel once to EEPROM
curTime = millis();
if (resetFunction == 1 && flowActive == 0 && consStored == 0 && curTime > resetTime) {
  EEPROM.put(30, count_raw);
  consStored = 1;
}

// If reset-function is in use reset consumed fuel from Digital Output
// allowed only if there is no fuel flow! (Engine off)
if (resetFunction == 1) {
  resetState = digitalRead(pinReset); // HIGH when open, LOW when closed to GND
  if (flowActive == 0 && resetState == LOW) {
    count_raw = 0;
    count_last = 0;
    uCons = 0;
    uFuel = 100;
    EEPROM.put(30, count_raw);
    consStored = 1;
  }
}
