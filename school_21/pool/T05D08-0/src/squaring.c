// "Copyright [2022] <Copyright cleotilm>"  [legal/copyright]

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n = 0, data[NMAX];
  int err;
  err = input(data, &n);
  if (err) {
    printf("n/a");
    return 1;
  }
  squaring(data, n);
  output(data, n);

  return 0;
}

void squaring(int *a, int n) {
  for (int *p = a; p <= a + n; p++) {
    *p = *p * *p;
  }
}

void output(int *a, int n) {
  int *p = a;
  for (; p < a + n - 1; p++) {
    printf("%d ", *p);
  }
  printf("%d", *(p));
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
