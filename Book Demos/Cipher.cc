#include <cstring>
#include <iostream>

int main() {
  char str[] = "Hello, can you read me?";
  int key = 77;

  std::cout << "message: " << str << std::endl;

  for (int i = 0; i < std::strlen(str); i++) {
    str[i] = str[i] ^ key;
  }

  std::cout << "encoded: " << str << std::endl;

  for (int i = 0; i < std::strlen(str); i++) {
    str[i] = str[i] ^ key;
  }

  std::cout << "message? " << str << std::endl;
}