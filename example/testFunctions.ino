#include <SmoothFunc.h>

int pin[2]={0,1};
// constractors of function objects' array.
GetAverage getAverage[2];
IsNewInRecents isNew[2];
IsUniqueInUniques isUnique[2];
// By default, each history size is 8(GetAverage),3(others).
// You can set history size like below:
//GetAverage getAverage[2] = {32,32};
//IsNewInRecents isNew[2] = {5,5};
//IsUniqueInUniques isUnique[2] = {5,5};

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.print("Start!!\n");
}

void loop() {
  for (int i = 0; i < 2; i++) {
    const int rawData = analogRead(pin[i]);
    const int smoothedData = getAverage[i](rawData);
    const int IsDataNew = isNew[i](smoothedData);
    const int IsDataUnique = isUnique[i](smoothedData);
    Serial.print("raw");
    Serial.print(i);
    Serial.print(":");
    Serial.print(rawData);
    Serial.print(" avr:");
    Serial.print(smoothedData);
    Serial.print(" New?:");
    Serial.print(IsDataNew);
    Serial.print(" Unique?:");
    Serial.print(IsDataUnique);
    Serial.print("    ");
  }
  delay(500);
  Serial.print("\n");
}
