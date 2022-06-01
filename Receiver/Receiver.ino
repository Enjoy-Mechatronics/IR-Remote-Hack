#include <IRremote.h>

IRrecv recv(2);

void setup() {
  recv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (recv.decode()) {
    //Serial.println(recv.decodedIRData.decodedRawData, HEX);
    recv.printIRResultShort(&Serial);
    delay(1000);
    recv.resume();
  }
}
