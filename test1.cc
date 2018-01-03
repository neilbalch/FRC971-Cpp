#include <stdio.h>

class A {
 public:
  explicit A(int i) { printf("A(%d)\n", i); }
};

class B {
 public:
  B() : a(3) {}
  A a;
};

B b;

int main() {}