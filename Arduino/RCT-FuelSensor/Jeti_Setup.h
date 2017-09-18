//
// Stuff that needs to be inside void setup()
//

// Sensor Name
// Serial speed is 10240 for Pro Mini 3.3V due software serial
// Serial speed is 9800 for Pro Mini 5V due software serial
JB.Init(F("RCT Fuel"), JETI_RX, 9800);

// Pinmode for sensor
pinMode(PULSES_IN, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(PULSES_IN), flowTick, CHANGE);

// Calibration settings - Reset to defaults on first use of Arduino Pro Mini
if (EEPROM.read(0) != 1) {
  EEPROM.write(0, 1); // Reset byte
  EEPROM.write(1, 0); // Calibration not done = 0, done = 1
  EEPROM.put(10, tankSize);
  EEPROM.put(20, pulseCount);
}

// Read normal startup-settings
calibDone = EEPROM.read(1);
EEPROM.get(10, tankSize);
EEPROM.get(20, pulseCount);

// Define Jeti Sensor value name & unit & variable & precision (decimals)
// JB.setValue30(JB.addData(F("NAME"), F("UNIT")), &VARIABLE, DEC);
//
// Sensor-value ranges:
// JB.setValue6 =   -31 to 31               (Variable is uint8_t)
// JB.setValue14 =  -8191 to 8191           (Variable is int)
// JB.setValue30 =  -536870911 to 536870911 (Variable is long)

JB.setValue30(JB.addData(F("Consumption"), F("ml")), &uCons, 0);
JB.setValue30(JB.addData(F("Flow Speed"), F("ml/m")), &uFlow, 0);
JB.setValue14(JB.addData(F("Remaining"), F("%")), &uFuel, 0);
