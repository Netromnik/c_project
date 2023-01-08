// Copyright [2022]

#include <stdio.h>
#define N 10

int input(int *buffer, int *length);
void output(int *buffer);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
            Функция получает массив данных
            через stdin.
            Выдает в stdout особую сумму
            и сформированный массив
            специальных элементов
            (выбранных с помощью найденной суммы):
            это и будет частью ключа
    -------------------------------------*/
int main() {
  int a[N];
  int n = 0;
  int input_a[N + 1];
  int err = input(a, &n);

  if (!err) {
    int summ = sum_numbers(a, n);
    printf("%d\n", summ);
    err = find_numbers(a, 10, summ, input_a);
  }

  if (!err) {
    output(input_a);
  }

  if (err) {
    printf("n/a");
  }
  return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
  int sum = 0;

  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      sum = sum + buffer[i];
    }
  }

  return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
  int *p = numbers;
  int err = 0;
  int count = -1;
  for (int i = 1; i < length + 1; i++) {
    if (buffer[i] == 0) {
      continue;
    }
    if (number % buffer[i] == 0) {
      *p = buffer[i];
      p++;
      count++;
    }
  }
  if (p == numbers) {
    err = 1;
  } else {
    numbers[0] = count;
  }
  return err;
}

void output(int *buffer) {
  for (int i = 1; i < buffer[0]; i++) {
    printf("%d ", buffer[i]);
  }
  printf("%d", buffer[buffer[0]]);
}

int input(int *buffer, int *length) {
  char c = ' ';
  int err = 0;
  int *p = buffer;
  int count = scanf("%d%c", length, &c);
  if (count != 2 || *length < 1 || *length > N) {
    err = 1;
  } else {
    c = ' ';
    while (p - buffer < *length && c == ' ') {
      scanf("%d%c", p, &c);
      p++;
    }
    if (c != '\n' || p - buffer != *length) {
      err = 2;
    }
  }
  return err;
}
