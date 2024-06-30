#include <chrono>
#include <thread>
#include <format>
#include <string>
#include <ncurses.h>

void print_in_middle(const std::string &str) {
  auto y = LINES / 2;
  auto x = (COLS - str.length()) / 2;
  mvprintw(y, x, "%s", str.c_str());
}

int main () {

  /* ncurses init */
  initscr();


  auto t_start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds(767));
  auto t_stop = std::chrono::high_resolution_clock::now();

  auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t_stop -
                                                                   t_start);
  dur *= 4500;

  auto dur_str = std::format("{:%T}", dur);
  print_in_middle(dur_str);
  refresh();

  /* ncurses quit */
  getch();
  endwin();
}
