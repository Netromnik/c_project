// Copyright [2022]

#include <stdio.h>
#include <stdlib.h>

void processing(int **ar, int n) {
  int tmp = 0;
  int *a = *ar;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

int input(int **a, int *n) {
  int err = 0;
  char c = ' ';
  int count = 0;
  scanf("%d%c", n, &c);
  if (c != '\n' || *n < 0) {
    err = 1;
  }
  if (!err) {
    c = ' ';
    *a = malloc(sizeof(int) * *n);
    for (int i = 0; i < *n && c == ' '; i++)
      count += scanf("%d%c", &(*a)[i], &c);
  }
  if (count / 2 != *n) {
    err = 1;
  }
  return err;
}

void print_result(int **arr, int n) {
  int *a = *arr;
  int *p = a;
  while (p - a < n - 1) {
    printf("%d ", *p);
    p++;
  }
  printf("%d", *p);
}

int main() {
  int n = 0;
  int *a = 0;
  int err = input(&a, &n);
  if (!err) {
    processing(&a, n);
    print_result(&a, n);
  } else {
    printf("n/a");
  }
  free(a);
  return err;
}
