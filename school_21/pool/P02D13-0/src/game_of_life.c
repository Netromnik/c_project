#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEAD ' '
#define LIVE '*'

#define W 80
#define H 25

int input(int *a) {
  for (int *p = a; p - a < H * W; p++) scanf("%d", p);
}

int check(int state_p, int count) {
  int state = 0;
  if (state_p) {
    count -= 1;
    state = count == 2 || count == 3 ? 1 : 0;
  } else
    state = count == 3 ? 1 : 0;
  return state;
}

int draw(int state[][W]) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printw("%c", state[i][j] == 1 ? LIVE : DEAD);
    }
    printw("\n");
  }
  return 0;
}

int check_cell(int current_field[][W], int y, int x) {
  int count = 0;

  for (int i = y - 1; i < y + 2; i++) {
    for (int j = x - 1; j < x + 2; j++) {
      count += current_field[i][j];
    }
  }
  return check(current_field[y][x], count);
}

int check_cell_ext_up(int current_field[][W], int y, int x) {
  // You implementation 1
  int c = 0;
  if (x == 0 && y == 0) {
    c = current_field[H - 1][W - 1];
  } else if (x == W - 1 && y == 0) {
    c = current_field[H - 1][0];
  } else if (y == H - 1 && x == 0) {
    c = current_field[H - 1][0];
  } else if (y == 0) {
    c = current_field[0][W - 1];
  } else if (x == 0) {
    c = current_field[H - 1][0];
  }
  return check(current_field[y][x], c);
}

int check_cell_ext_down(int current_field[][W], int y, int x) {
  // You implementation 2
  int c = 0;
  if (x == W - 1 && y == H - 1) {
    c = current_field[H - 1][W - 1];
  } else if (x == W - 1) {
    c = current_field[H - 1][0];
  } else if (y == H - 1) {
    c = current_field[H - 1][0];
  }
  return check(current_field[y][x], c);
}

void update(int cur_state[][W]) {
  int next_state[H][W] = {0};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i == 0 || j == 0)
        next_state[i][j] = check_cell_ext_up(cur_state, i, j);
      else if (j == W - 1 || i == H - 1)
        next_state[i][j] = check_cell_ext_down(cur_state, i, j);
      else
        next_state[i][j] = check_cell(cur_state, i, j);
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cur_state[i][j] = next_state[i][j];
    }
  }
}

int main(void) {
  int state[H][W] = {0};
  char c = 0;
  int t = 2;
  int end = 1;
  int fps = 100000;
  input((int *)state);
  freopen("/dev/tty", "r", stdin);
  initscr();
  noecho();
  nodelay(stdscr, 1);

  while (end) {
    clear();
    usleep(fps);
    draw(state);
    update(state);
    switch (getch()) {
      case 'a':
        fps += 10000;
        break;
      case 'z':
        fps -= 10000;
        break;
      case 'q':
        end = 0;
        break;
      case -1:
        freopen("/dev/tty", "r", stdin);
        break;
    }
    refresh();
  }
  endwin();
  return 0;
}