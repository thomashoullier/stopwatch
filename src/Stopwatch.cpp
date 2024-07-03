#include "Stopwatch.h"

void Stopwatch::run() {

  char ch{};
  do {
    this->refresh_display();

    switch (ch) {
    case STOP_RESUME:
      w.toggle_nodelay();
      clk.toggle();
      break;
    case RESET:
      clk.init();
      w.set_delay();
      this->refresh_display();
      break;
    case ERR: /* Counting */
      flushinp();
      std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_WAIT));
      break;
    case QUIT:
      return;
    }
  } while ((ch = getch()) != 'q');
}

void Stopwatch::refresh_display() {
  auto dur_str = clk.get_duration();
  w.print(dur_str);
}
