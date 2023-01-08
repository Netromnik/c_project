// Copyright 2022 <Copyright Cleotilde>

#include <stdio.h>

#include <math.h>

double calc_f(double x) {
  double val1 = 7 * (pow(10, (-3.0))) * pow(x, 4) + \
    ((22.8 * pow(x, (1 / 3.0)) - \
      (1 * pow(10, 3.0))) * x + 3);
  return val1 / (x * x / 2) - x * pow((10 + x), (2 / x)) - 1.01;
}

int main() {
  double t1;
  char end;
  int count = scanf("%lf%c", & t1, & end);
  if (count == 2 && end == '\n') {
    printf("%.1f\n", calc_f(t1));
  } else {
    printf("n/a\n");
    return 0;
  }
  return 0;
}
