#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include <string>
#include <format>

class Clock {
public:
  /* Initiate the clock. */
  Clock ();
  /* Get the current duration since start. */
  std::string get_duration();
  /* Stop the clock. */
  void stop();
  /* Resume the clock. */
  void resume();

private:
  /* Point from which to count the duration. */
  std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
  /* Time at which the clock was last stopped. */
  std::chrono::time_point<std::chrono::high_resolution_clock> t_stop;
  /* Is the clock currently running? */
  bool running_p;
};

#endif // CLOCK_H
