// "Copyright [2022] <Copyright cleotilm>"  [legal/copyright]

#include <math.h>
#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];

  int err = input(data, &n);
  if (err) {
    printf("n/a");
    return 1;
  }

  output(data, n);
  output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

  return 0;
}

int max(int *a, int n) {
  int max_data = *a;
  for (int *p = a; p < a + n; p++) {
    if (*p > max_data) {
      max_data = *p;
    }
  }
  return max_data;
}

int min(int *a, int n) {
  int min_data = *a;
  for (int *p = a; p < a + n; p++) {
    if (*p < min_data) {
      min_data = *p;
    }
  }
  return min_data;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}

void output(int *a, int n) {
  int *p = a;
  for (; p < a + n - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d\n", *(p));
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
