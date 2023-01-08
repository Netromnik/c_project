#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DEAD ' '
#define LIVE '*'

#define W 80
#define H 25

void input(int *a);
int check(int state_p, int count);
int draw(int state[][W]);
int check_cell(int current_field[][W], int y, int x);
void copy(int cur_state[][W], int **next_state);
void test_point(int cur_state[][W], int **next_state);
void update_line(int cur_state[][W], int **next_state);
void process(int cur_state[][W]);
void update(int state[][W]);

void input(int *a) {
  for (int *p = a; p - a < H * W; p++) scanf("%d", p);
}

int check(int state_p, int count) {
  int state = 0;
  if (state_p) {
    count -= 1;
    state = count == 2 || count == 3 ? 1 : 0;
  } else {
    state = count == 3 ? 1 : 0;
  }
  return state;
}

void copy(int cur_state[][W], int **next_state) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cur_state[i][j] = next_state[i][j];
    }
  }
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

int main(void) {
  int state[H][W] = {0};
  input((int *)state);
  freopen("/dev/tty", "r", stdin);
  initscr();
  noecho();
  nodelay(stdscr, 1);
  update(state);
  endwin();
  return 0;
}

void update(int state[][W]) {
  int end = 1;
  int fps = 100000;

  while (end) {
    clear();
    usleep(fps);
    draw(state);
    process(state);
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
}

void process(int cur_state[][W]) {
  int **next_state = (int **)malloc(sizeof(int *) * H);
  for (int i = 0; i < H; i++) {
    next_state[i] = (int *)malloc(sizeof(int) * W);
  }

  test_point(cur_state, next_state);
  copy(cur_state, next_state);

  for (int i = 0; i < H; i++) {
    free(next_state[i]);
  }

  free(next_state);
}

void test_point(int cur_state[][W], int **next_state) {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      next_state[i][j] = check_cell(cur_state, i, j);
    }
  }
}

int fix_pint(int p, int max) {
  if (p >= max) {
    p = 0;
  } else if (p < 0) {
    p = max - 1;
  }
  return p;
}

int check_cell(int current_field[][W], int y, int x) {
  int count = 0;
  for (int i = y - 1; i < y + 2; i++) {
    for (int j = x - 1; j < x + 2; j++) {
      count += current_field[fix_pint(i, H)][fix_pint(j, W)];
    }
  }
  return check(current_field[y][x], count);
}
