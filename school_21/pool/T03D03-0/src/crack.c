// Copyright 2022 <Copyright Cleotilde>

#include <stdio.h>

int main() {
  int t1, t2;
  char end;
  int count = scanf("%f%f%c", & t1, & t2, & end);
  if (count == 3 && end == '\n') {
    double r = t1 * t1 + t2 * t2;
    if (r > 25) {
      printf("GOTCHA\n");
    } else {
      printf("MISS\n");
    }
  } else {
    printf("n/a\n");
    return 0;
  }
  return 0;
}
