#SmoothFunc for Arduino
Functions for smoothing data, especially good for analogRead().
##Description
SmoothFunc has 3 simple function objects.

+ "GetAverage" : calculate average with incoming data and internal history data,then register new data to the history and throw away the oldest.
+ "IsNewInRecents" : return whether incoming data is new in internal history data,then register new data into the history and throw away the oldest.
+ "IsUniqueInUniques" : return whether incoming data is unique in internal history data,if so,register the data into the history and throw away the oldest.

"IsUniqueInUniques" is a variation of "IsNewInRecents".
If you use "IsNewInRecents" and your sketch still runs unstably,consider using "IsUniqueInUniques".
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

const int PIN0 = 5;
const int PIN[4]={0,1,2,3};

void setup(){
//...//
}
void loop(){
  // regular pattern :
  const int rawData = analogRead(PIN0);
  const int smoothedData = getAverage0(rawData);
  if (isNew0(smoothedData)) {
    //Do anything you want only when the data changed.
  }

  //regular pattern for array :
  for (int i=0; i < 4; i++) {
    const int rawData = analogRead(PIN[i]);
    const int smoothedData = getAverage[i](rawData);
    if (isNew[i](smoothedData)) {
      //Do anything you want only when the data changed.
    }
  }
  delay(10);
}
```




#License
This code is available under the [MIT License](http://opensource.org/licenses/mit-license.php).
