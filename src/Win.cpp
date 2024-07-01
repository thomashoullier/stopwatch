#include "Win.h"

Win::Win() {
  initscr();
  cbreak();
  curs_set(0);
  noecho();
}

Win::~Win () {
  endwin();
}

void Win::print(const std::string &str) {
  auto y = LINES / 2;
  auto x = (COLS - str.length()) / 2;
  mvprintw(y, x, "%s", str.c_str());
  refresh();
}

void Win::set_delay() {
  nodelay(stdscr, FALSE);
}

void Win::toggle_nodelay() {
  if (is_nodelay(stdscr)) {
    nodelay(stdscr, FALSE);
  } else {
    nodelay(stdscr, TRUE);
  }
}
