// "Copyright 2022 <Copyright Owner>"  [legal/copyright]

#include <stdio.h>

int isDivv(int c, int b) {
  double a = c;
  while (a >= b) {
    a -= b;
  }
  if (a == 0) {
    return 1;
  } else {
    return 0;
  }
}

int isSimple(int a) {
  double count = a - 1;
  while (count > 1) {
    if (isDivv(a, count) == 1) {
      return 0;
    }
    count--;
  }
  return 1;
}

int main() {
  int count, a;
  char c;
  scanf("%d%c", & a, & c);
  if (a < 0) {
    a = -1 * a;
  }
  count = a - 1;
  if (c != '\n') {
    printf("%d", c);
  }
  while (count > 1) {
    if (isSimple(count) && isDivv(a, count)) {
      printf("%d\n", count);
      return 0;
    } else {
      count--;
    }
  }
  printf("%d", a);
  return 0;
}
