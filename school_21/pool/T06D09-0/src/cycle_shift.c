// Copyright [2022]

#include <stdio.h>
#define N 10

int input(int *a, int *n, int *shift) {
  char c = ' ';
  int err = 0;
  int count = scanf("%d%c", n, &c);
  if (count != 2 || *n < 1 || *n > N) {
    err = 1;
  } else {
    c = ' ';

    for (int *p = a; p - a < *n && c == ' '; p++) scanf("%d%c", p, &c);
    if (c != '\n') {
      err = 2;
    }

    count = scanf("%d%c", shift, &c);
    if (count != 2 && c != '\n') {
      err = 3;
    }
  }
  return err;
}

void shift_left(int *a, int n) {
  int first = *a;
  for (int i = 1; i < n; ++i) a[i - 1] = a[i];
  a[n - 1] = first;
}

int main() {
  int err = 0;
  int n = 0;
  int shift = 0;

  int arr[N];
  err = input(arr, &n, &shift);
  if (!err) {
    if (shift < 0) {
      shift = shift % n;
      shift = n + shift;
    }
    for (int i = 0; i < shift; i++) shift_left(arr, N);
    for (int i = 0; i < n - 1; i++) printf("%d ", arr[i]);
    printf("%d", arr[n - 1]);
  } else {
    printf("n/a");
  }
  return err;
}
