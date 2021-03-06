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
  strcat_P((char*)&msg_line2, (const char*)F("ml/m"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 2 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Reset Consumpt."));
  strcat_P((char*)&msg_line2, (const char*)F("Rst Dn   Next >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 3 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Tank cap: "));
  temp[0] = 0;
  floatToString((char*)&temp, tankSize, 0);
  strcat((char*)&msg_line1, (char*)&temp);
  strcat_P((char*)&msg_line1, (const char*)F("ml"));
  strcat_P((char*)&msg_line2, (const char*)F("Rst LeRi Next >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 4 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Calibr.: "));
  temp[0] = 0;
  if (calibDone == 0) {
    floatToString((char*)&temp, count_raw, 0);
    strcat((char*)&msg_line1, (char*)&temp);
  } else {
    floatToString((char*)&temp, pulseCount, 0);
    strcat((char*)&msg_line1, (char*)&temp);
    strcat_P((char*)&msg_line1, (const char*)F("*"));
  }
  strcat_P((char*)&msg_line2, (const char*)F("Rst LeRi Next >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 5 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Dig.Reset: "));
  if (resetFunction == 0) {
    strcat_P((char*)&msg_line1, (const char*)F("No"));
  }
  if (resetFunction == 1) {
    strcat_P((char*)&msg_line1, (const char*)F("Yes"));
  }
  strcat_P((char*)&msg_line2, (const char*)F("Change Dn Next >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case 6 : {
  msg_line1[0] = 0; msg_line2[0] = 0;
  strcat_P((char*)&msg_line1, (const char*)F("Reset or Save"));
  strcat_P((char*)&msg_line2, (const char*)F("Rst UpDn Save >"));
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
  break;
}
case MAX_SCREEN : {
  JB.JetiBox_P(ABOUT_1, ABOUT_2);
  break;
}