#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int** reduce_matrix(int** a, int n, int pos) {
  int i, j;
  int** ret = (int**)malloc(sizeof(int*) * (n - 1));
  for (i = 0; i < n - 1; i++) {
    ret[i] = (int*)malloc((n - 1) * sizeof(int));
    for (j = 0; j < pos; j++) ret[i][j] = a[i + 1][j];
    for (j = pos; j < n - 1; j++) ret[i][j] = a[i + 1][j + 1];
  }
  return ret;
}

double det(int** a, int n) {
  double sum = 0;
  int i;
  if (n == 1) return a[0][0];
  for (i = 0; i < n; i++)
    sum += a[0][i] * pow(-1.0, i) * det(reduce_matrix(a, n, i), n - 1);
  return sum;
}

int main() {
  int n = 0, s1 = 0, s2 = 0, i, j;
  int** a;
  scanf("%d%d", &s1, &s2);
  if (s1 == s2 || s1 != 0) {
    n = s1;
  } else {
    printf("n/a");
    return 1;
  }
  a = (int**)malloc(n * sizeof(int*));
  for (i = 0; i < n; i++) a[i] = (int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &(a[i][j]));
  printf("%.6lf", det(a, n));
  for (i = 0; i < n; i++) free(a + i);
  free(a);
}
