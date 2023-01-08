#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define FAIL 0
#define SUCCESS_M "SUCCESS"
#define FAIL_M "FAIL"

int assert_equal(int val1, int val2) { return val1 == val2 ? SUCCESS : FAIL; }

void test_n(int n) {
  printf("\n");
  printf("Test %d\n", n);
}
void print_str(char *c, int len) {
  printf("[");
  for (int i = 0; i < len; i++) printf(" %d ", (int)*(c + i));
  printf("]");
}

void print(int n, char *c1, int len, int resualt, char *output) {
  printf("\n");
  test_n(n);
  printf("INPUT DATA:\n");
  print_str(c1, len);
  printf("\nOUTPUT DATA:\n");
  printf("%s\n", output);
  printf("STATUS:\n");
  printf("%s\n", resualt ? SUCCESS_M : FAIL_M);
}

void s21_strlen_test() {
  char buf[200] = {0};
  // Given
  char str[19] = "write;wrote;written";
  char str_0[19] = "write;wrote;written";
  str_0[0] = 0;
  char str_1[2] = {0, 0};

  // When
  int real = s21_strlen(str);
  int real0 = s21_strlen(str_0);
  int real1 = s21_strlen(str_1);

  // Then
  const int expected = 21;
  const int expected0 = 19;
  const int expected1 = 0;

  // Print

  if (!sprintf(buf, "%d", real)) printf("n/a");
  print(1, str, 19, assert_equal(expected, real), buf);

  if (!sprintf(buf, "%d", real0)) printf("n/a");
  print(2, str_0, 19, assert_equal(expected0, real0), buf);

  if (!sprintf(buf, "%d", real1)) printf("n/a");
  print(3, str_1, 2, assert_equal(expected1, real1), buf);
}

void s21_strcmp_test() {
  // Given
  char str[5] = "abcd";
  char str_1[5] = "abc";

  // When
  int real = s21_strcmp(str, "abcd");
  int real0 = s21_strcmp(str, "");
  char test[] = {'a', 'b', 'c', 0, 'v'};
  int real1 = s21_strcmp(str_1, test);
  // Then
  const int expected = 0;
  const int expected0 = 1;
  const int expected1 = -1;

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(str, 4);
  printf("\n");
  print_str("abcd", 4);

  printf("\nOUTPUT DATA:\n");
  printf("%d\n", real);
  printf("STATUS:\n");
  printf("%s\n", assert_equal(expected, real) ? SUCCESS_M : FAIL_M);

  test_n(2);
  printf("INPUT DATA:\n");
  print_str(str, 4);
  printf("\n");
  print_str("", 1);

  printf("\nOUTPUT DATA:\n");
  printf("%d\n", real0);
  printf("STATUS:\n");
  printf("%s\n", assert_equal(expected0, real0) ? SUCCESS_M : FAIL_M);

  test_n(3);
  printf("INPUT DATA:\n");
  print_str(str_1, 4);
  printf("\n");
  print_str(test, 5);

  printf("\nOUTPUT DATA:\n");
  printf("%d\n", real1);
  printf("STATUS:\n");
  printf("%s\n", assert_equal(expected1, real1) ? SUCCESS_M : FAIL_M);
}

void s21_strcpy_test() {
  char buf[10] = {0};

  char test_1[] = "test";

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(test_1, 4);
  printf("\n");
  print_str(buf, 9);
  s21_strcpy(buf, test_1);
  printf("\nOUTPUT DATA:\n");
  print_str(buf, 9);
  printf("\nSTATUS:\n");
  if (buf[3] == test_1[3]) printf("%s\n", SUCCESS_M);

  for (int i = 0; i < 10; i++) buf[i] = 0;

  test_n(2);
  printf("INPUT DATA:\n");
  test_1[2] = 0;
  print_str(test_1, 4);
  printf("\n");
  print_str(buf, 9);
  s21_strcpy(buf, test_1);
  printf("\nOUTPUT DATA:\n");
  print_str(buf, 9);
  printf("\nSTATUS:\n");
  if (buf[3] != test_1[3]) printf("%s\n", FAIL_M);
  for (int i = 0; i < 10; i++) buf[i] = 0;

  test_n(3);
  printf("INPUT DATA:\n");
  print_str("", 1);
  printf("\n");
  print_str(buf, 9);
  s21_strcpy(buf, "");
  printf("\nOUTPUT DATA:\n");
  print_str(buf, 9);
  printf("\nSTATUS:\n");
  if (!buf[3]) printf("%s\n", SUCCESS_M);
}

void s21_strcat_test() {
  char str1[10] = "Th";

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(str1, 10);
  printf("\n");
  print_str("asd", 4);
  s21_strcat(str1, "asd");
  printf("\nOUTPUT DATA:\n");
  print_str(str1, 10);
  printf("\nSTATUS:\n");
  printf("%s\n", SUCCESS_M);

  test_n(2);
  printf("INPUT DATA:\n");
  print_str(str1, 10);
  printf("\n");
  print_str("", 1);
  s21_strcat(str1, "");
  printf("\nOUTPUT DATA:\n");
  print_str(str1, 10);
  printf("\nSTATUS:\n");
  printf("%s\n", SUCCESS_M);

  str1[3] = 0;
  test_n(3);
  printf("INPUT DATA:\n");
  print_str(str1, 10);
  printf("\n");
  print_str("t", 2);
  s21_strcat(str1, "t");
  printf("\nOUTPUT DATA:\n");
  print_str(str1, 10);
  printf("\nSTATUS:\n");
  printf("%s\n", FAIL_M);
}

void s21_strchr_test() {
  char str1[10] = "T:T";

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(str1, 10);
  printf("\n");

  print_str(":", 1);
  char *d = s21_strchr(str1, ':');
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (d == &str1[1]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("%s\n", FAIL_M);
  }
  str1[1] = 0;
  str1[2] = ':';
  str1[3] = 'T';
  test_n(2);
  printf("INPUT DATA:\n");
  print_str(str1, 10);
  printf("\n");
  print_str(":", 1);
  d = s21_strchr(str1, ':');
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");

  if (d == &str1[1]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("%s\n", FAIL_M);
  }
  char str2[] = "";

  test_n(3);
  printf("INPUT DATA:\n");
  print_str(str2, 1);
  printf("\n");
  print_str("", 1);
  d = s21_strchr(str1, ':');
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");

  if (d == &str2[0]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("%s\n", FAIL_M);
  }
}

void s21_strstr_test() {
  char test_s[] = "T--D";

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(test_s, 4);
  printf("\n");

  print_str("--", 3);
  char *d = s21_strstr(test_s, "--");
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (d == &test_s[1]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("%s\n", FAIL_M);
  }

  test_n(2);
  printf("INPUT DATA:\n");
  print_str(test_s, 4);
  printf("\n");

  print_str(":", 2);
  d = s21_strstr(test_s, ":");
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (d == 0) {
    printf("%s\n", FAIL_M);
  } else {
    printf("n/a");
  }

  test_n(3);
  printf("INPUT DATA:\n");
  print_str(test_s, 4);
  printf("\n");

  print_str(test_s, 4);
  d = s21_strstr(test_s, test_s);
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (d == &test_s[0]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("n/a");
  }
}

void s21_strtok_test() {
  char test_s[] = "T--D";

  test_n(1);
  printf("INPUT DATA:\n");
  print_str(test_s, 4);
  printf("\n");

  print_str("-", 2);
  char *d = s21_strtok(test_s, "-");
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);

  printf("\nSTATUS:\n");

  if (0 == test_s[1]) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("%s\n", FAIL_M);
  }
  char test_d[10] = "T--D";

  test_n(2);
  printf("INPUT DATA:\n");
  print_str(test_d, 4);
  printf("\n");

  print_str(":", 2);
  d = s21_strtok(test_d, ":");
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (*d == test_d[0]) {
    printf("%s\n", FAIL_M);
  } else {
    printf("n/a");
  }

  test_n(3);
  printf("INPUT DATA:\n");
  print_str(test_s, 4);
  printf("\n");

  print_str("::", 2);
  d = s21_strtok(test_s, "--");
  printf("\nOUTPUT DATA:\n");
  printf("%p", d);
  printf("\nSTATUS:\n");
  if (d != 0) {
    printf("%s\n", SUCCESS_M);
  } else {
    printf("n/a");
  }
}

int main() {
#ifdef TEST1
  s21_strlen_test();
#endif
#ifdef TEST2
  s21_strcmp_test();
#endif
#ifdef TEST3
  s21_strcpy_test();
#endif
#ifdef TEST4
  s21_strcat_test();
#endif
#ifdef TEST5
  s21_strchr_test();
#endif

#ifdef TEST6
  s21_strstr_test();
#endif

#ifdef TEST7
  s21_strtok_test();
#endif

  return 1;
}
