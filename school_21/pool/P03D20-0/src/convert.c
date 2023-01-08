
#include <stdio.h>

#include "stack_char.h"

int mydigit(char c) {
  int is_digital = 0;
  if ('0' <= c && c <= '9') is_digital = 1;
  if ('.' == c || c == ',') is_digital = 1;
  return is_digital;
}

int check_prior(char c) {
  static priory* priority;
  int prior = -2;
  if (priority == 0) {
    priority = init_priory();
  }
  for (int i = 0; i < PRIORY; i++) {
    if (priority[i].c == c) prior = priority[i].p;
  }
  return prior;
}

stack_char to_pn(string s_str, int* err) {
  int is_unar = 1;
  char data = 0;
  stack_char stac_out = init_stack_char(err);
  stack_char stac_oper = init_stack_char(err);
  for (int i = 0; i < s_str.len && !*err; i++) {
    char c = s_str.str[i];
    if (mydigit(c)) {
      is_unar = 0;
      stac_out = append_c(stac_out, c, err);
    } else if (c == 'x') {
      is_unar = 0;
      stac_out = append_c(stac_out, 0, err);
      stac_out = append_c(stac_out, 'x', err);
      stac_out = append_c(stac_out, 0, err);

    } else {
      if (is_unar && c == '-') c = '?';

      is_unar = 1;

      if (c == '(') {
        stac_oper = append_c(stac_oper, c, err);
      } else {
        if (stac_oper.len) {
          while (stac_oper.len && check_prior(stac_oper.start[stac_oper.len]) >=
                                      check_prior(c)) {
            stac_out = append_c(stac_out, 0, err);
            stac_oper = pop_c(stac_oper, &data);
            stac_out = append_c(stac_out, data, err);
            stac_out = append_c(stac_out, 0, err);
          }
        } else {
          stac_out = append_c(stac_out, 0, err);
        }
        if (c == ')') {
          stac_oper = pop_c(stac_oper, &data);
        } else {
          stac_oper = append_c(stac_oper, c, err);
        }
      }
    }
  }

  for (int i = stac_oper.len; i > 0; i--) {
    stac_oper = pop_c(stac_oper, &data);
    stac_out = append_c(stac_out, 0, err);
    stac_out = append_c(stac_out, data, err);
    stac_out = append_c(stac_out, 0, err);
  }
  delete_c(stac_oper);
  return stac_out;
}
