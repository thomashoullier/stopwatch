#ifndef WIN_H
#define WIN_H

#include <ncurses.h>
#include <string>

/* Class to manage the init, display and state of ncurses. */
class Win {
public:
  Win ();
  ~Win ();

  void set_delay ();
  void toggle_nodelay ();
  void print (const std::string &str);
};

#endif // WIN_H
