#include <cstring>
#include <iostream>

// Custom implementation of std::strlen
int str_len(char *str) {
  int len = 0;

  while (true) {
    // If there is no char @ place len, then stop counting
    if (str[len] == 0) {
      break;
    } else {
      len++;
    }
  }

  return len;
}

int main() {
  char str[] = "This is a string. HELLO WORLD!";
  std::cout << "New str_len   : " << str_len(str) << std::endl;
  std::cout << "Default strlen: " << std::strlen(str) << std::endl;
}