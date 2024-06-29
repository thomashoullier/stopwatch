#include <iostream>
#include <chrono>
#include <thread>
#include <format>

int main () {
  std::cout << "Hello" << std::endl;

  auto t_start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  auto t_stop = std::chrono::high_resolution_clock::now();

  auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t_stop -
                                                                   t_start);
  dur *= 4500;
  std::cout << std::format("{:%T}", dur) << std::endl;
  //std::cout << dur.count() << std::endl;
}
