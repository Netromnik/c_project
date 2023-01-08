// "Copyright 2022 <Copyright Owner>"  [legal/copyright]
#include <stdio.h>

#include <math.h>

#define M_PI_S 3.1415926
double f1(double x) {
  return 1. / (1. + pow(x, 2.));
}

double f2(double x) {
  double x2 = x * x;
  double
  var = sqrt(1. + 4. * x2) - x2 - 1.;
  if (var <= 0) {
    return 0;
  } else {
    return sqrt(var);
  }
}

double f3(double x) {
  return 1. / (x * x);
}

int main() {
  double count_d = (M_PI_S + M_PI_S) / 42;
  double point = -M_PI_S;
  double f2_buff = 0;

  while (point < M_PI_S) {
    if (point > -1e-7 && point < 1e-7) {
      point += count_d;
      continue;
    }
    f2_buff = f2(point);
    if (f2_buff) {
      printf("%.7lf | %.7lf | %.7lf | %.7lf\n", \
      point, f1(point), f2_buff, f3(point));
    } else {
      printf("%.7lf | %.7lf | - | %.7lf\n", point, f1(point), f3(point));
    }
    point += count_d;
  }
  return 0;
}
