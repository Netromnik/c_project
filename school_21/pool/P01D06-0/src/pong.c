#include <stdio.h>

#define MAX_H 27
#define MAX_W 82

int is_merge(int y1, int y2) {
  if (y1 == y2 || y1 + 1 == y2 || y1 + 2 == y2) {
    return 1;
  } else {
    return 0;
  }
}

void line(char c) {
  for (int i = 0; i < MAX_W + 1; i++) printf("%c", c);
  printf("\n");
}

void print_win(int count) {
  line('#');
  for (int i = 0; i <= MAX_H; i++) {
    for (int j = 0; j <= MAX_W; j++) {
      if (i == MAX_H / 2 && j == 32) {
        printf("WINNER PLAYER %d", count);
        j += 14;
      } else if (j == 0 || j > MAX_W - 1) {
        printf("|");
      } else {
        printf("%c", ' ');
      }
    }
    printf("\n");
  }
  line('#');
}

int main() {
  int ball_x = MAX_W / 2, ball_y = MAX_H / 2 - 1;
  int ball_x_a = 1, ball_y_a = 1;
  int user1_p1x = 1, user1_p1y = MAX_H / 2 - 1;

  int user2_p1x = MAX_W - 1, user2_p1y = MAX_H / 2 - 1;

  char c = '\n';
  char c_print = ' ';
  int next = 0;

  int score_user1 = 0;
  int score_user2 = 0;
  int mid = (MAX_W - 5) / 2;
  int user_win = 0;

  while (c_print != 'q' && !user_win) {
    for (int j = 0; j <= mid; j++) {
      printf(" ");
    }
    printf("%d : %d\n", score_user1, score_user2);

    for (int y = 0; y <= MAX_H; y++) {
      if (y == 0 || y == MAX_H) {
        line('#');
        continue;
      }
      for (int x = 0; x <= MAX_W; x++) {
        if (x == 0 || x == MAX_W) {
          printf("|");
          continue;
        }

        if (is_merge(user1_p1y, y) && user1_p1x == x) {
          c_print = '|';
        }

        if (is_merge(user2_p1y, y) && user2_p1x == x) {
          c_print = '|';
        }

        if (ball_y == y && ball_x == x) {
          c_print = '*';
        }

        putchar(c_print);

        c_print = ' ';

        if (score_user1 == 21) {
          user_win = 1;
        } else if (score_user2 == 21) {
          user_win = 2;
        }
      }

      putchar('\n');
    }
    if (is_merge(user1_p1y, ball_y) && user1_p1x == ball_x) {
      ball_x_a *= -1;
    }

    if (is_merge(user2_p1y, ball_y) && user2_p1x == ball_x) {
      ball_x_a *= -1;
    }

    if (MAX_H - 2 < ball_y || 2 > ball_y) {
      ball_y_a *= -1;
    }

    if (ball_x == 0) {
      score_user2++;
      ball_x = MAX_W / 2;
      ball_y = MAX_H / 2 - 1;
      ball_x_a = 1;
      ball_y_a = 1;
    } else if (ball_x == MAX_W) {
      score_user1++;
      ball_x = MAX_W / 2;
      ball_y = MAX_H / 2 - 1;
      ball_x_a = -1;
      ball_y_a = -1;
    }

    while (!next) {
      scanf("%c", &c);
      if (c == 'a' || c == 'A') {
        if (user1_p1y >= 2 && user1_p1y <= 24) {
          user1_p1y--;
        }
        next = 1;
      } else if (c == 'z' || c == 'Z') {
        if (user1_p1y >= 1 && user1_p1y <= 23) {
          user1_p1y++;
        }
        next = 1;
      }

      if (c == 'k' || c == 'K') {
        if (user2_p1y >= 2 && user2_p1y <= 24) {
          user2_p1y--;
        }
        next = 1;
      } else if (c == 'm' || c == 'M') {
        if (user2_p1y >= 1 && user2_p1y <= 23) {
          user2_p1y++;
        }
        next = 1;
      }

      if (c == ' ') {
        next = 1;
      }
      if (c == 'q') {
        next = 1;
      }
    }
    next = 0;
    ball_x += ball_x_a;
    ball_y += ball_y_a;
  }
  if (user_win != 0) {
    print_win(user_win);
  }

  return 0;
}
