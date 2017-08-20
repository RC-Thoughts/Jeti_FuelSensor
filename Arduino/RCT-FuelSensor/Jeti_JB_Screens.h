//
// Build Jetibox screens
//

case 0 : {
  JB.JetiBox_P(ABOUT_1, ABOUT_2);
  break;
}
case 1 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Cons: "));
  temp[0] = 0;
  floatToString((char*)&temp, uCons, 0);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("ml"));
  strcat_P((char*)&msg_line2, (const char*)F("Flow: "));
  temp[0] = 0;
  floatToString((char*)&temp, uFlow, 0);
  strcat((char*)&msg_line2, (char*)&temp);
  strcat_P((char*)&msg_line2, (const char*)F("ml/s"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 2 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Reset Consumpt."));
  strcat_P((char*)&msg_line2, (const char*)F("Press Up & Dn"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 3 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Calibr.: "));
  temp[0] = 0;
  floatToString((char*)&temp, calVal, 0);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("ml"));
  strcat_P((char*)&msg_line2, (const char*)F("Press > to Save"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 99 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Settings Stored!"));
  strcat_P((char*)&msg_line2, (const char*)F("Press < To Exit"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case MAX_SCREEN : {
  JB.JetiBox_P(ABOUT_1, ABOUT_2);
  break;
}
