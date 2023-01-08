#include "validation.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

void remove_space(char* string) {
  char dest[1000];
  int i, j;
  for (i = j = 0; string[i] != '\0'; i++)
    if (string[i] != ' ') {
      dest[j] = string[i];
      j++;
    }
  dest[j] = '\0';
  strcpy(string, dest);
}

int check_bracket(char* const string) {
  int count = 0;
  int flag = 1;
  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == '(') {
      count++;
    } else if (string[i] == ')') {
      count--;
    }
    if (count < 0) {
      flag = 0;
    }
  }
  if (count != 0) {
    flag = 0;
  }
  return flag;
}

int check_symbol(char* const string) {
  int flag = 1;
  for (int i = 0; string[i] != '\0'; i++) {
    if ((string[i] < 48 || string[i] > 57) && string[i] != 120 &&
        string[i] != 46 && string[i] != 42 && string[i] != 43 &&
        string[i] != 45 && string[i] != 47 && string[i] != 94) {
      flag = 0;
    }
  }
  return flag;
}

void replace_substring(char* string, char* sub_str, char* sub_str_rep) {
  const int BUFFER_SIZE = 256;
  char* buffer = NULL;
  int buffer_len = 0;
  while (strstr(string, sub_str) != NULL) {
    buffer = (char*)malloc(BUFFER_SIZE);

    memset(buffer, buffer_len, strlen(string));

    strncpy(buffer, string, strlen(string) - strlen(strstr(string, sub_str)));
    strcat(buffer, sub_str_rep);
    strcat(buffer, strstr(string, sub_str) + strlen(sub_str));

    strcpy(string, buffer);

    free(buffer);
  }
}

int check_validation(char* string) {
  int flag = 1;
  struct operator oper[6] = {{"sqrt", "q"}, {"cos", "c"}, {"sin", "s"},
                             {"ctg", "g"},  {"tan", "a"}, {"ln", "l"}};
  char* test = (char*)malloc(1000);
  remove_space(string);
  strcpy(test, string);
  if (check_bracket(test)) {
    replace_substring(test, "(", "");
    replace_substring(test, ")", "");
  } else {
    flag = 0;
  }
  for (int i = 0; i < 6; i++) {
    replace_substring(test, oper[i].name, "");
  }
  if (!check_symbol(test)) {
    flag = 0;
  }
  free(test);
  return flag;
}

string cast_string() {
  struct operator oper[6] = {{"sqrt", "q"}, {"cos", "c"}, {"sin", "s"},
                             {"ctg", "g"},  {"tan", "a"}, {"ln", "l"}};
  int flag = 1;
  string test;
  char* string_in = malloc(1000 * sizeof(char));
  printf("Input string:\n");
  if (scanf("%1000[^\n]", string_in)) {
    if (check_validation(string_in)) {
      for (int i = 0; i < 6; i++) {
        replace_substring(string_in, oper[i].name, oper[i].polperf);
      }
    } else {
      flag = 0;
    }
  }
  test.len = strlen(string_in);
  if (flag == 0) {
    printf("Incorrect input");
    test.len = 0;
  }
  test.str = string_in;
  return test;
}
