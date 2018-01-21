#include <stdio.h>
#include <iostream>

class IntRange {
 public:
  // Explicit prevents implicit conversions to IntRange
  // Initialises n_ with the value of n
  explicit IntRange(int n) : n_(n) {}

  class iter {
   public:
    // Explicit prevents implicit conversions to iter
    // Initialises i_ with the value of i
    explicit iter(int i) : i_(i) {}

    // Compare the given iter object to the end iter object
    bool operator!=(const iter& o) const {
      std::cout << "!= ";
      return i_ != o.i_;
    }

    int operator*() const {
      std::cout << "* ";
      return i_;
    }

    // Adcance the iterator
    iter& operator++() {
      std::cout << "++ ";
      // increment the stored value
      ++i_;
      // Return a reference to the current iter object
      return *this;
    }

   private:
    int i_;
  };

  iter begin() const { return iter(0); }
  iter end() const { return iter(n_); }

 private:
  int n_;
};

int main() {
  /*for (int i : IntRange(20)) {
    printf("I: %d\n", i);
  }*/

  auto&& __range = IntRange(20);
  for (auto __begin = __range.begin(), __end = __range.end(); __begin != __end;
       ++__begin) {
    int i = *__begin;
    printf("I: %d\n", i);
  }
  std::cout << std::endl;
}