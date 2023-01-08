#define _XOPEN_SOURCE
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  useconds_t fps = 100000;
  initscr();
  noecho();
  nodelay(stdscr, 1);
  int count = 100;
  while (1) {
    clear();
    usleep(fps);

    switch (getch()) {
      case 'a':
        fps -= count;
        break;
      case 'b':
        fps += count;
        break;
      default:
        printw("No %d", fps);
    }
    printw("\nIS good");
    refresh();
  };

  endwin();
  return 0;
}
