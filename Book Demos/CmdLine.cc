#include <iostream>

// Takes command line arguments and prints them out
int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) std::cout << *argv[i] << std::endl;
}