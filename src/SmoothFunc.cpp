#include "SmoothFunc.h"

boolean elem(int x,const int ary[],int arySize){
  for(int i=0;i < arySize;i++){
    if(x == ary[i])return true;
  }
  return false;
}

SmoothFunc::SmoothFunc(int mod):MOD(mod){
  history = new int[MOD];
  for(int i = 0; i < MOD ; i++){
    history[i] = 0;
  }
  index = 0;
}
void SmoothFunc::updateEnv(int newVal){
  history[index] = newVal;
  index = (index+1) % MOD;
}

GetAverage::GetAverage():smoothFunc(8){
  sum = 0;
}
GetAverage::GetAverage(int mod):smoothFunc(mod){
  sum = 0;
}
int GetAverage::operator()(int newVal){
  sum += ( newVal - smoothFunc.history[smoothFunc.index] );
  smoothFunc.updateEnv(newVal);
  return sum / smoothFunc.MOD;
}

IsNewInRecents::IsNewInRecents():smoothFunc(3){
}
IsNewInRecents::IsNewInRecents(int mod):smoothFunc(mod){
}

boolean IsNewInRecents::operator()(int newVal){
  const boolean ANSWER = !elem(newVal, smoothFunc.history, smoothFunc.MOD);
  smoothFunc.updateEnv(newVal);
  return ANSWER;
}

IsUniqueInUniques::IsUniqueInUniques():smoothFunc(3){
}
IsUniqueInUniques::IsUniqueInUniques(int mod):smoothFunc(mod){
}

boolean IsUniqueInUniques::operator()(int newVal){
  const boolean ANSWER = !elem(newVal, smoothFunc.history, smoothFunc.MOD);
  if (ANSWER) smoothFunc.updateEnv(newVal);
  return ANSWER;
}
