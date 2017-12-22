#include <iostream>
#include "FizzBuzz.h"
#include "FizzBuzz.cc"
using namespace std;

int main(void) {
  for(int i = 0; i < 1000; ++i){
    cout << testNum(i + 1) << endl;
  }
  return 0;
}
