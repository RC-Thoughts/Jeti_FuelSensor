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
  if (current_screen == 3) {
    EEPROM.put(1, calVal);
    current_screen = 99;
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
break;
case 144 : // UP+DOWN
if (current_screen == 2) {
  count_raw = 0;
  current_screen = 99;
}
if (current_screen == 3) {
  calVal = calVal + 10;
}
break;
case 96 : // LEFT+RIGHT
if (current_screen == 3) {
  calVal = calVal - 10;
}
break;
