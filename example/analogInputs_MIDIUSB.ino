#include <MIDIUSB.h>
#include <SmoothFunc.h>

GetAverage getAverage[2] = {10,10};
IsNewInRecents isNewInRecents[2] = {4,4};
const int ANAPIN[2]={0,1};
const byte CHANNEL = 0;
const byte CC[2] ={25,26};

void setup() {
  Serial.begin(115200);
}

void loop() {
  for(int i=0;i < 2; i++){
    const int smoothedData = getAverage[i]( analogRead(ANAPIN[i]) >> 3 );
    if( isNewInRecents[i]( smoothedData )){
      controlChange(CHANNEL,CC[i],smoothedData);
      MidiUSB.flush();
    };
  delay(10);
  };
}

//controll value or velocity
// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
