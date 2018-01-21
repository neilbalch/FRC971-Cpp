#include <cmath>
#include <iostream>

void roundDouble(double &value) {
  double whole;
  double decimal = modf(value, &whole);
  if (decimal > 0.5) whole++;
  value = whole;
}

int main() {
  double test1 = 6535.5435;
  double test2 = 6535.3435;
  std::cout << "Test1: " << test1 << std::endl;
  roundDouble(test1);
  std::cout << "Test1, rounded: " << test1 << std::endl;
  std::cout << "Test2: " << test2 << std::endl;
  roundDouble(test2);
  std::cout << "Test2, rounded: " << test2 << std::endl;
}