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
  cbreak();
  curs_set(0); // Hide the cursor.
  halfdelay(1); // 100ms frame time on getch.
  noecho();

  auto t_start = std::chrono::high_resolution_clock::now();

  char ch;
  while ((ch = getch()) != 'q') {
    switch (ch) {
    case ERR: // Update the timer with usual framerate.
      {
        auto t_cur = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(t_cur -
                                                                         t_start);
        auto dur_str = std::format("{:%T}", dur);
        print_in_middle(dur_str);
        refresh();
        break;
      }
    case ' ': // Stop/resume timer.
      // Save the time at which we stopped.
      auto t_stop = std::chrono::high_resolution_clock::now();
      nocbreak(); cbreak();
      while ((ch = getch()) != ' ') {
        switch (ch) {
        case 'q':
          // Quit the program.
          endwin();
          return 0;
        }
        // Do nothing otherwise.
      }
      // Continue, with clock shifted by the pause time
      auto t_resume = std::chrono::high_resolution_clock::now();
      t_start += (t_resume - t_stop);
      halfdelay(1);
      break;
    }
  }

  /* ncurses quit */
  endwin();
}
