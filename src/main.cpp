#include <chrono>
#include <string>
#include <ncurses.h>
#include "Clock.h"

void print_in_middle(const std::string &str) {
  auto y = LINES / 2;
  auto x = (COLS - str.length()) / 2;
  mvprintw(y, x, "%s", str.c_str());
}

int main () {
  /* ncurses init */
  initscr();
  cbreak();
  curs_set(0); // Hide the cursor.
  halfdelay(1); // 100ms frame time on getch.
  noecho();

  Clock clk;

  char ch;
  while ((ch = getch()) != 'q') {
    switch (ch) {
    case ERR: // Update the timer with usual framerate.
      {
        auto dur_str = clk.get_duration();
        print_in_middle(dur_str);
        refresh();
        break;
      }
    case ' ': // Stop/resume timer.
      clk.stop();
      nocbreak(); cbreak(); // deactivate the halfdelay.
      while ((ch = getch()) != ' ') {
        switch (ch) {
        case 'q':
          // Quit the program.
          endwin();
          return 0;
        }
        // Do nothing otherwise.
      }
      clk.resume();
      halfdelay(1);
      break;
    }
  }

  /* ncurses quit */
  endwin();
}
