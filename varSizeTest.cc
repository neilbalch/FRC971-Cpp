#include <chrono>
#include <iostream>
#include <typeinfo>

int main() {
  std::chrono::seconds sec(90);
  std::chrono::minutes min =
      ::std::chrono::duration_cast<::std::chrono::minutes>(sec);
  double tick = ::std::chrono::duration<double>(sec).count();

  auto start = std::chrono::steady_clock::now();
  std::cout << "tick is a(n): " << typeid(tick).name() << ::std::endl;
  std::cout << tick << " Ticks in " << sec.count() << " seconds" << ::std::endl;
  std::cout << min.count() << " Minute(s) in " << sec.count() << " seconds "
            << ::std::endl;
  std::chrono::steady_clock::time_point end =
      ::std::chrono::steady_clock::now();

  std::chrono::duration<double> diff = end - start;
  std::cout << "Time Duration: " << diff.count() << std::endl;

  double ggg = 645;
}