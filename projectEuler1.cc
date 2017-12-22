#include <iostream>
#include <string>

int maxNumber = 10;
int runningSum = 0;

void waitForEnd() {
  int l;
  ::std::cin >> l;
}

enum stick { Thing, Thing2 };
stick stickThing = Thing;
void thingrwe() {
  int var = 0;
  switch (var) {
    case 0:
      std::cout << "hi" << std::endl;
    case 1:
      std::cout << "nope" << std::endl;
  }
}

int main() {
  for (int i = 0; i < maxNumber; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      runningSum += i;
    }
  }
  ::std::cout << "Total: " << runningSum << ::std::endl;
  waitForEnd();
}