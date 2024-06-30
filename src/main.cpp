#include <chrono>
#include <string>
#include <ncurses.h>
#include "Clock.h"
#include<thread>

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
  noecho();

  Clock clk;

  char ch;
  nodelay(stdscr, FALSE); // Replace by toggle.
  while ((ch = getch()) != 'q') {
    auto dur_str = clk.get_duration();
    print_in_middle(dur_str);
    refresh();

    switch(ch) {
    case ' ':
      nodelay(stdscr, TRUE); // Replace by toggle.
      clk.resume(); // TODO: toggle clock.
      break;
    case 'q':
      endwin();
      return 0;
    case ERR:
      flushinp();
      std::this_thread::sleep_for(std::chrono::milliseconds(16));
      break;
    }
  }

  endwin();
}
