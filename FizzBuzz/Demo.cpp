#include <iostream>
using namespace std;

int main(void) {
  // Print the numbers 1 through 100 on the screen.
  for (int i = 0; i < 100; ++i) {
    if(((i + 1) % 3 == 0) && ((i + 1) % 5 == 0) ){
      cout << "Fizz Buzz" << endl;
    } else if((i + 1) % 3 == 0) {
      cout << "Fizz" << endl;
    } else if ((i + 1) % 5 == 0) {
      cout << "Buzz" << endl;
    } else {
      cout << i + 1 << endl;
    }
  }
  return 0;
}
