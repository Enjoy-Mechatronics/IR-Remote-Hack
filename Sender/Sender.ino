#include <IRremote.h>

int IRSenderPin = 3;

int onPin = 12;
int offPin = 11;

void setup() {
  IrSender.begin(IRSenderPin, 13);
  pinMode(onPin, INPUT_PULLUP);
  pinMode(offPin, INPUT_PULLUP);
}

void loop() {
  //IrSender.sendNECRaw(0xFD02EF00,2);
  if (digitalRead(onPin) == 0) {
    IrSender.sendNEC(0xEF00, 0x3, 5);
  }

  if (digitalRead(offPin) == 0) {
    IrSender.sendNEC(0xEF00, 0x2, 2);
  }

  delay(20);
}
