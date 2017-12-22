#include <iostream>

class object {
 public:
  object(double hhh) {
    storage = hhh;
    std::cout << "This is the num: " << hhh << std::endl;
  }

 protected:
  double storage;
};

class thing : object {
 public:
  void printStorage() { std::cout << "Storage is: " << storage << std::endl; }
};

int main() {
  constexpr double myThing = 666.666;
  object ohWow(myThing);
  thing thisIsCool(myThing);
}
