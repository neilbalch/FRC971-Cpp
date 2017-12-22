#include <iostream>
#include "FizzBuzz.h"
#include "FizzBuzz.cc"
using namespace std;

int fizzBuzzTest(int numTest, string expected) {
  bool result;
  if(testNum(numTest) == expected){
    result = true;
  } else {
    result = false;
  }
  return result;
}

int main(void) {
  cout << "This is a Test." << endl;
  cout << "2: " << fizzBuzzTest(2, "Nor") << endl;
  cout << "3: " << fizzBuzzTest(3, "Fizz") << endl;
  cout << "5: " << fizzBuzzTest(5, "Buzz") << endl;
  cout << "15: " << fizzBuzzTest(15, "Fizz Buzz") << endl;
  cout << "2: " << fizzBuzzTest(2, "Fizz") << endl;
  return 0;
}

