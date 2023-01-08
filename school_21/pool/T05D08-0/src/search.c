// "Copyright [2022] <Copyright cleotilm>"  [legal/copyright]

#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int *a, int n, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];

  int err = input(data, &n);
  if (err) {
    printf("n/a");
    return 1;
  }

  output_result(data, n, mean(data, n), variance(data, n));
  return 0;
}

double mean(int *a, int n) {
  double summ = 0.;
  for (int *p = a; p < a + n; p++) {
    summ = summ + *p;
  }
  return summ / n;
}

double variance(int *a, int n) {
  double s1 = mean(a, n), s2 = 0.;

  for (int *p = a; p < a + n; p++) {
    s2 += pow(*p - s1, 2);
  }
  return s2 / n;
}

void output_result(int *a, int n, double mean_v, double variance_v) {
  for (int *p = a; p <= a + n; p++) {
    if (*p % 2 == 0 && *p != 0) {
      if (*p >= mean_v && *p <= mean_v + 3 * sqrt(variance_v)) {
        printf("%d", *p);
        return;
      }
    }
  }
  printf("0");
  return;
}

int input(int *a, int *n) {
  char c;
  scanf("%d%c", n, &c);

  if (c != '\n') return 1;
  if (0 < *n && *n > NMAX) return 1;

  for (int *p = a; p <= a + *n; p++) {
    scanf("%d%c", p, &c);
    if (c == '\n' && p - a == *n - 1) {
      return 0;
    } else if (c != ' ') {
      return 1;
    }
  }
  return 0;
}
