#include "graphic.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int calc_x(double x) { return round((x * N) / (4 * M_PI)); }

int calc_y(double y) { return round(y * M / 2 + 12); }

point init_p(int i, int j) {
  point p = {.x = i, .y = j};
  return p;
}

char print_c(point p1, point p2) {
  return p1.x == p2.x && p1.y == p2.y ? '*' : '.';
}

void graphic(string rpm) {
  double sig = (4 * M_PI) / N;

  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      printf("%c",
             print_c(init_p(calc_x(sig * i), calc_y(sig * calc_polish(rpm, i))),
                     init_p(i, j)));
    }
    printf("\n");
  }
}
