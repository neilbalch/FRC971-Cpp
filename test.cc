#include <iostream>
class thing {
 public:
  int operator+(thing h) { return 4; }
};

int main() {
  thing a;
  thing b;
  std::cout << a + b << std::endl;
}