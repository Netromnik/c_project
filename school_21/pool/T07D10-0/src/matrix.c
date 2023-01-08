
// Copyright [2022]

#include <stdio.h>
#include <stdlib.h>
#define N 10

int input_c(int *n, char end, int is_positiv) {
  char c = ' ';
  int err = 0;
  int count = scanf("%d%c", n, &c);
  if (c != end || count != 2) {
    err = 1;
  }
  if (is_positiv && *n < 0) {
    err = 2;
  }
  return err;
}

int input(int *n, int *row, int *coll) {
  int err = 0;
  err = input_c(n, '\n', 1);
  if (!err) {
    err = input_c(coll, ' ', 1);
    err = input_c(row, '\n', 1);
  }
  return err;
}

int read_line(int *a, int n) {
  int err = 0;
  char c = ' ';
  int i = 1;
  scanf("%d%c", a, &c);
  while (i < n && c == ' ') {
    scanf("%d%c", a + i, &c);
    i++;
  }
  if (i != n || c != '\n') {
    err = 1;
  }
  return err;
}

int v1(int row, int coll, int *arr) {
  int err = 0;
  for (int i = 0; i < row && !err; i++) {
    err = read_line(arr + i * row, coll);
  }
  return err;
}

int v2(int row, int coll, int ***p) {
  int err = 0;

  int **pa = malloc(row * sizeof(int *));
  if (pa == 0) {
    err = 1;
  }
  for (int i = 0; i < row && !err; i++) {
    pa[i] = malloc(coll * sizeof(int));
  }
  for (int i = 0; i < row && !err; i++) {
    err = read_line(pa[i], coll);
  }
  *p = pa;
  return err;
}

int v3(int row, int coll, int ***p) {
  int err = 0;

  int **pa = malloc(row * sizeof(int *) + row * coll * sizeof(int));
  if (pa == 0) {
    err = 1;
  } else {
    int *ptr = (int *)pa + row;

    for (int i = 0; i < row; i++) {
      pa[i] = ptr + coll * i;
    }
  }

  for (int i = 0; i < row && !err; i++) {
    err = read_line(pa[i], coll);
  }
  *p = pa;
  return err;
}

int v4(int row, int coll, int ***p, int **pp) {
  int err = 0;

  int **pa = malloc(row * sizeof(int *));
  int *v_a = malloc(row * coll * sizeof(int));

  if (pa == 0 || v_a == 0) {
    err = 1;
  } else {
    for (int i = 0; i < row; i++) {
      pa[i] = v_a + coll * i;
    }
  }

  for (int i = 0; i < row && !err; i++) {
    err = read_line(pa[i], coll);
  }
  *p = pa;
  *pp = v_a;
  return err;
}

void output_static(int *p, int row, int coll) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < coll; j++) {
      printf("%d ", *(p + i * row + j));
    }
    printf("\n");
  }
  printf("\b");
}

void output_dim(int **p, int row, int coll) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < coll; j++) {
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
  printf("\b");
}

int main() {
  int arr[N * N] = {0};
  int n = 0;
  int **a = 0;
  int *p2 = 0;
  int row = 0, coll = 0;
  int err = input(&n, &row, &coll);
  if (err) {
    printf("n/a");
  } else if (n == 1) {
    v1(row, coll, arr);
    output_static(arr, row, coll);
  } else if (n == 2) {
    v2(row, coll, &a);
    output_dim(a, row, coll);
    for (int i = 0; i < row; i++) free(a[i]);
    free(a);
  } else if (n == 3) {
    v3(row, coll, &a);
    output_dim(a, row, coll);
    free(a);
  } else if (n == 4) {
    v4(row, coll, &a, &p2);
    output_dim(a, row, coll);
    free(a);
    free(p2);
  } else {
    printf("n/a");
  }

  return err;
}
