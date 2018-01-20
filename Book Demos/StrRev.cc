#include <cstring>
#include <iostream>

int main() {
  char str[] = "This is text.";
  char *start, *end;
  int length = std::strlen(str);
  start = str;
  end = str + (length - 1);

  std::cout << "Original: " << str << std::endl;

  char t;
  while (start < end) {
    std::cout << "Working: " << str << std::endl;
    char t = *end;
    *end = *start;
    *start = t;
    start++, end--;
  }
  std::cout << "Reversed: " << str << std::endl;
}