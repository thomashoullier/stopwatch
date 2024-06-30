#include "Clock.h"

Clock::Clock () {
  t_start = std::chrono::high_resolution_clock::now();
  t_stop = t_start;
  running_p = false;
}

std::string Clock::get_duration() {
  auto t_cur = (running_p) ? std::chrono::high_resolution_clock::now() : t_stop;
  auto dur =
      std::chrono::duration_cast<std::chrono::milliseconds>(t_cur - t_start);
  auto dur_str = std::format("{:%T}", dur);
  return dur_str;
}

void Clock::stop() {
  t_stop = std::chrono::high_resolution_clock::now();
  running_p = false;
}

void Clock::resume() {
  auto t_resume = std::chrono::high_resolution_clock::now();
  t_start += t_resume - t_stop; /* Shift the clock by the time paused. */
  running_p = true;
}

//TODO: Add a toggle instead.
