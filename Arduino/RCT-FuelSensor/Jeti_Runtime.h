//
// This is the main loop where the work is done
//
// May the flow be with you

// Total consumption (calibrated)

uCons = ((double)count_raw / ( pulseCount / 1000 ));
if ( uCons < 0 ) {
uCons = 0;
 }

// Fuel gauge in percent
if ( tankSize > 0 and uCons > 0 ) {
  float tank = tankSize;
  float cons = uCons;
  uFuel = 100 - ( 100 / ( tank / cons ) );
  if ( uFuel < 0 ) {
    uFuel = 0;
  }
}

//Calc fuel flow in ml/m (calibrated)
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
