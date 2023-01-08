// "Copyright 2022 <Copyright Owner>"  [legal/copyright]

#include <stdio.h>

int fibonacci(int N) {
  if (N == 1 || N == 2)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
  int N;
  char end;
  scanf("%d%c", & N, & end);

  if (N < 0 || end != '\n') {
    printf("n/a");
    return 1;
  }

  printf("%d", fibonacci(N));
  return 0;
}
