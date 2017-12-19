// 
// Jetibox navigation and button actions
//

// Button codes
// 224  RIGHT
// 112  LEFT
// 208  UP
// 176  DOWN
// 144  UP & DOWN
// 9    LEFT & RIGHT
//
case 224 : // RIGHT
if (current_screen != MAX_SCREEN)
{
  if (current_screen == 6) {
    pulseCount = count_raw;
    EEPROM.write(0, 1); // Reset byte
    EEPROM.write(1, 1); // Calibration done
    EEPROM.write(2, resetFunction); // Calibration done
    EEPROM.put(10, tankSize);
    if (calibDone == 0) {
      pulseCount = count_raw;
      EEPROM.put(20, pulseCount);
    }
    delay(200);
    resetSensor();
  } else {
    current_screen++;
  }
}
break;

case 112 : // LEFT
if (current_screen == 99) {
  current_screen = 0;
}
if (current_screen != 0) {
  current_screen--;
}
break;

case 208 : // UP
if (current_screen == 3) {
  tankSize = tankSize + 100;
}
if (current_screen == 4) {
  count_raw = count_raw + 100;
  calibDone = 0;
}
break;

case 176 : // DOWN
if (current_screen == 2 && resetFunction == 0) {
  count_raw = 0;
  current_screen = 1;
}
if (current_screen == 2 && resetFunction == 1 && flowActive == 0) {
  count_raw = 0;
  count_last = 0;
  uCons = 0;
  uFuel = 100;
  EEPROM.put(30, count_raw);
  consStored = 1;
  current_screen = 1;
}
if (current_screen == 3) {
  tankSize = tankSize + 1000;
}
if (current_screen == 4) {
  count_raw = count_raw + 1000;
  calibDone = 0;
}
if (current_screen == 5) {
  if (resetFunction == 0) {
    resetFunction = 1;
    current_screen = 5;
  } else {
    resetFunction = 0;
    current_screen = 5;
  }
}
break;

case 144 : // UP+DOWN
if (current_screen == 3) {
  tankSize = tankSize + 50;
}
if (current_screen == 4) {
  count_raw = count_raw + 10;
  calibDone = 0;
}
if (current_screen == 6) {
  EEPROM.write(0, 0); // Reset byte
  delay(200);
  resetSensor();
}
break;

case 96 : // LEFT+RIGHT
if (current_screen == 3) {
  tankSize = 0;
}
if (current_screen == 4) {
  count_raw = 0;
  calibDone = 0;
}
break;
