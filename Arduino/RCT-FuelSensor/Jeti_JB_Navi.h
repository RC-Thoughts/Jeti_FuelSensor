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
    EEPROM.write(1, type);
    EEPROM.put(2, calVal);
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
  calVal = calVal + 1;
}
break;
case 176 : // DOWN
if (current_screen == 3) {
  calVal = calVal - 1;
}
if (current_screen == 4) {
  if (type == 1) {
    type = 0;
    EEPROM.write(1, type);
  } else {
    type = 1;
    EEPROM.write(1, type);
  }
}
break;
case 144 : // UP+DOWN
if (current_screen == 2) {
  count_raw = 0;
  current_screen = 1;
}
if (current_screen == 3) {
  calVal = calVal + 10;
}
if (current_screen == 5) {
  type = 0;
  calVal = 1000;
  EEPROM.write(0, 1);
  EEPROM.write(1, type);
  EEPROM.put(2, calVal);
  delay(200);
  resetFunc();
}
break;
case 96 : // LEFT+RIGHT
if (current_screen == 3) {
  calVal = calVal - 10;
}
break;
