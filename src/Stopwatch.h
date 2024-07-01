#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "Clock.h"
#include "Win.h"
#include <chrono>
#include <thread>
#include <ncurses.h>

class Stopwatch {
public:
  void run ();

private:
  Win w;
  Clock clk;

  void refresh_display ();
};

#endif // STOPWATCH_H
