#include "Clock.h"
#include "Win.h"
#include <chrono>
#include <thread>
#include <ncurses.h>

int main () {
  Win w;
  Clock clk;

  char ch {};
  do {
    auto dur_str = clk.get_duration();
    w.print(dur_str);

    switch (ch) {
    case ' ':
      w.toggle_nodelay();
      clk.toggle();
      break;
    case ERR:
      flushinp();
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
      break;
    case 'q':
      return 0;
    }
  } while ((ch = getch()) != 'q');
}
