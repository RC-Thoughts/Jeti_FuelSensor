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
  if (current_screen == 5) {
    pulseCount = count_raw;
    EEPROM.write(0, 1); // Reset byte
    EEPROM.write(1, 1); // Calibration done
    EEPROM.put(10, tankSize);
    if (calibDone == 0) {
      pulseCount = count_raw;
      EEPROM.put(20, pulseCount);
    }
    delay(200);
    resetFunc();
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
break;
case 176 : // DOWN
if (current_screen == 2) {
  count_raw = 0;
  current_screen = 1;
}
if (current_screen == 3) {
  tankSize = tankSize + 1000;
}
if (current_screen == 4) {
  count_raw = 0;
  calibDone = 0;
}
break;
case 144 : // UP+DOWN
if (current_screen == 3) {
  tankSize = tankSize + 50;
}
if (current_screen == 5) {
  EEPROM.write(0, 0); // Reset byte
  delay(200);
  resetFunc();
}
break;
case 96 : // LEFT+RIGHT
if (current_screen == 3) {
  tankSize = 0;
}
break;
