#include <chrono>
#include <thread>
#include <format>
#include <ncurses.h>

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
  printw(dur_str.c_str());
  refresh();

  /* ncurses quit */
  getch();
  endwin();
}
