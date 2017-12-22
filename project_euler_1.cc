#include <iostream>
#include <string>

//
// Original problem: https://projecteuler.net/problem=1
//

// Number to count to
int maxNumber = 10;
// Variable to store the runing sum during calculation
int runningSum = 0;

// Irrelevant enum demo
enum stick { Thing, Thing2 };
stick stickThing = Thing;
// END irrelevane enum demo

int main() {
  // Loop the number of times defined in maxNumber
  for (int i = 0; i < maxNumber; ++i) {
    // If loop number is evenly divisible by wither 3 or 5...
    if (i % 3 == 0 || i % 5 == 0) {
      //... add the number to the running sum
      runningSum += i;
    }
  }

  // At the end. print out the final count
  ::std::cout << "Total: " << runningSum << ::std::endl;
}