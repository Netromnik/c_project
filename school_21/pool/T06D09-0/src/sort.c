// Copyright [2022]

#include <stdio.h>
#define N 10

void processing(int *a) {
  int tmp = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int *p = a; p - a < N - 1; p++) {
      if (*p > *(p + 1)) {
        tmp = *p;
        *p = *(p + 1);
        *(p + 1) = tmp;
      }
    }
  }
}

int input(int *a) {
  char c = ' ';
  int err = 0;
  for (int *p = a; p - a < N && c == ' '; p++) scanf("%d%c", p, &c);
  if (c != '\n') {
    err = 1;
  }
  return err;
}

void print_result(int *a) {
  int *p = a;
  while (p - a < N - 1) {
    printf("%d ", *p);
    p++;
  }
  printf("%d", *p);
}

int main() {
  int a[N];
  int err = input(a);
  if (err) {
    processing(a);
    print_result(a);
  } else {
    printf("n/a");
  }
  return 0;
}
