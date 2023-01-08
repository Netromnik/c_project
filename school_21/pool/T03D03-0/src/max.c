// Copyright 2022 <Copyright Cleotilde>

#include <stdio.h>

int max(int t1, int t2);
int test_end();

int main() {
  int t1, t2;
  scanf("%d%d", & t1, & t2);
  if (test_end()) {
    printf("n/a\n");
    return 0;
  }
  printf("%d\n", max(t1, t2));
  return 0;
}
int test_end() {
  char c = fgetc(stdin);
  while (c != '\n') {
    if (c != ' ') {
      return 1;
    }
    c = fgetc(stdin);
  }
  return 0;
}

int max(int t1, int t2) {
  if (t1 >= t2) {
    return t1;
  } else {
    return t2;
  }
}
