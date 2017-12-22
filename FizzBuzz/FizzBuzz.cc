#include <iostream>
#include "FizzBuzz.h"
using namespace std;

string testNum(int numTest) {
  if((numTest % 3 == 0) && (numTest % 5 == 0) ){
    //cout << "Fizz Buzz" << endl;
    return "Fizz Buzz";
  } else if(numTest % 3 == 0) {
    //cout << "Fizz" << endl;
    return "Fizz";
  } else if (numTest % 5 == 0) {
    //cout << "Buzz" << endl;
    return "Buzz";
  } else {
    //cout << numTest << endl;
    return "Nor";
  }
}

