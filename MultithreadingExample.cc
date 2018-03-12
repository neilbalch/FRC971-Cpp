#include <iostream>
#include <thread>
#include <mutex>

// Shared resource locker.
std::mutex m;

void DoWork() {
  // Lock the mutex or block until locking is possible.
  m.lock();
  
  std::cout << "Worker thread: std::this_thread::get_id()=" << std::this_thread::get_id() << std::endl;
  std::cin.get();
  
  // Unlock the mutex for other threads to lock.
  m.unlock();
}

int main()
{
  std::cout << "Parent thread: std::this_thread::get_id()=" << std::this_thread::get_id() << std::endl;

    
  std::thread worker1(DoWork);
  std::thread worker2(DoWork);
  std::thread worker3(DoWork);
  
  worker1.join();
  worker2.join();
  worker3.join();
}
