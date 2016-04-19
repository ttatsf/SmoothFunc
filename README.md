#SmoothFunc for Arduino
Functions for smoothing data, especially good for analogRead().
##Description
SmoothFunc has 3 simple function objects.

+ "GetAverage" : calculate sum of incoming data and internal history data,register new data to the history and throw away the oldest, then return the average.
+ "IsNewInRecents" : calculate whether incoming data is new in internal history data, register new data into the history and throw away the oldest, then return the result.
+ "IsUniqueInUniques" : calculate whether incoming data is unique in internal history data,if so, register the data into the history and throw away the oldest, then return the result.

"IsUniqueInUniques" is a variation of "IsNewInRecents".
If you use "IsNewInRecents" and your sketch still runs unstably,consider using "IsUniqueInUniques".
It may stabilize your sketch on smaller history size.

##Installation
[Download ZIP](https://github.com/ttatsf/SmoothFunc/archive/master.zip) and [follow instructions here.](https://www.arduino.cc/en/Guide/Libraries)

##Typical usage
As these are "function" object, you can(and have to) use each instance as  "function" directly.


```
#include <SmoothFunc.h>

//Instantiate function objects.
// By default,the history sizes are 8(GetAverage) and 3(others).
GetAverage getAverage0;  //or: GetAverage getAverage(10);  //you can set history size:
IsNewInRecents isNew0;  //    IsNewInRecents isNew(5);

//Instantiate array:
GetAverage getAverage[4]; //or: GetAverage getAverage[4]={10,10,10,10};	  //You can also set array's element's history size.This sets each to 10.
IsNewInRecents isNew[4];  //    IsNewInRecents isNew[4]={5,5,5,5};  //set each history size to 5.

const int PIN_0 = 5;
const int PIN[4]={0,1,2,3};

void setup(){
//...//
}
void loop(){
  // regular pattern :
  const int RAW_DATA = analogRead(PIN_0);
  const int SMOOTHED_DATA = getAverage0(RAW_DATA);
  if (isNew0(SMOOTHED_DATA)) {
    //Do anything you want only when the data changed.
  }

  //regular pattern for array :
  for (int i=0; i < 4; i++) {
    const int RAW_DATA = analogRead(PIN[i]);
    const int SMOOTHED_DATA = getAverage[i](RAW_DATA);
    if (isNew[i](SMOOTHED_DATA)) {
      //Do anything you want only when the data changed.
    }
  }
  delay(10);
}
```




#License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
