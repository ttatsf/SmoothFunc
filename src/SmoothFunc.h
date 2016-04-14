#ifndef SMOOTH_FUNC_H
#define SMOOTH_FUNC_H
#include <Arduino.h>

class SmoothFunc{
  public:
    const int MOD ;
    int *history;
    int index;
    void updateEnv(int newVal);
    SmoothFunc(int mod);
};

class GetAverage{
  private:
    SmoothFunc smoothFunc;
    int sum;
  public:
    GetAverage();
    GetAverage(int mod);
    int operator()(int newVal);
};

class IsNewInRecents{
  private:
    SmoothFunc smoothFunc;
  public:
    IsNewInRecents();
    IsNewInRecents(int mod);
    boolean operator()(int newVal);
};

class IsUniqueInUniques{
  private:
    SmoothFunc smoothFunc;
  public:
    IsUniqueInUniques();
    IsUniqueInUniques(int mod);
    boolean operator()(int newVal);
};

#endif
