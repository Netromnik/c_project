#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length);
void shift(int *buff, int len);
void clear(int *buff, int len);
/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
  int arr_c1[LEN];
  int arr_c2[LEN];
  int arr_c1 = {1, 9, 4, 4, 6, 7, 4, 4, 0, 7, 3, 7, 0, 9, 5, 5, 1, 6, 1};
  int arr_c2 = {2, 9};

  int c1l = 19;
  int c2l = 2;
  int result[LEN] = {0};
  int result_length;

  shift(arr_c1, c1l);
  shift(arr_c2, c2l);

  if (c2l > c1l) {
    printf("n/a");
    return 1;
  }
  sum(arr_c1, c1l, arr_c2, c2l, result, &result_length);

  return 0;
}
/*
  v1 = max
  v2 = min
*/
void clear(int *buff, int len) {
  for (int i = 0; i < len; i++) {
    buff[i] = 0;
  }
}

void shift(int *buff, int len) {
  for (int i = LEN - len; i < LEN; i++) {
    buff[i] = buff[LEN - i];
  }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  int tmp;

  int *a = buff1 + len1;
  int *b = buff2 + len2;
  int *c = result;

  while (a != buff1 && b != buff2) {
    tmp = *a + *b;
    if (tmp / 10 && tmp != 0) {
      if (c) c = tmp % 10;
      c++;
      c = tmp / 10;
      c++;
    } else {
      c = tmp;
      c++;
    }
    a--;
    b--;
  }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result,
         int *result_length) {
  int tmp;
  int *a = buff1 + len1;
  int *b = buff2 + len2;
  int *c = result;

  while (a != buff1 && b != buff2) {
    tmp = *a + *b;
    if (tmp / 10 && tmp != 0) {
      if (c) c = tmp % 10;
      c++;
      c = tmp / 10;
      c++;
    } else {
      c = tmp;
      c++;
    }
    a--;
    b--;
  }
}