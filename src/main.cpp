#include <chrono>
#include <string>
#include <ncurses.h>
#include "Clock.h"
#include <thread>

void print_in_middle(const std::string &str) {
  auto y = LINES / 2;
  auto x = (COLS - str.length()) / 2;
  mvprintw(y, x, "%s", str.c_str());
}

void toggle_nodelay () {
  if (is_nodelay(stdscr)) {
    nodelay(stdscr, FALSE);
  } else {
    nodelay(stdscr, TRUE);
  }
}

int main () {
  /* ncurses init */
  initscr();
  cbreak();
  curs_set(0); // Hide the cursor.
  noecho();

  Clock clk;

  char ch;
  while ((ch = getch()) != 'q') {
    auto dur_str = clk.get_duration();
    print_in_middle(dur_str);
    refresh();

    switch(ch) {
    case ' ':
      toggle_nodelay();
      clk.toggle();
      break;
    case ERR:
      flushinp();
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
      break;
    case 'q':
      endwin();
      return 0;
    }
  }

  endwin();
}
