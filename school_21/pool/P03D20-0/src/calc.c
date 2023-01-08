#include <math.h>
#include <stdio.h>

#include "header.h"
#include "stack_double.h"

stack_double process_op(stack_double stack, char c, int* err) {
  double d1, d2;
  switch (c) {
    case '*':
      stack = pop_d(stack, &d1);
      stack = pop_d(stack, &d2);
      stack = append_d(stack, d1 * d2, err);
      break;
    case '+':
      stack = pop_d(stack, &d1);
      stack = pop_d(stack, &d2);
      stack = append_d(stack, d1 + d2, err);
      break;
    case '/':
      stack = pop_d(stack, &d1);
      stack = pop_d(stack, &d2);
      if (d1 == 0) {
        *err = 0;
      } else {
        stack = append_d(stack, d2 / d1, err);
      }
      break;
    case '^':
      stack = pop_d(stack, &d1);
      stack = pop_d(stack, &d2);
      if (d1 == 0) {
        *err = 0;
      } else {
        stack = append_d(stack, pow(d2, d1), err);
      }
      break;
    case '?':
      stack = pop_d(stack, &d1);
      if (d1 == 0) {
        *err = 0;
      } else {
        stack = append_d(stack, -d1, err);
      }
      break;
    case 'q':
      stack = pop_d(stack, &d1);
      if (d1 < 0) {
        *err = 0;
      } else {
        stack = append_d(stack, sqrt(d1), err);
      }
      break;
    case 's':
      stack = pop_d(stack, &d1);
      stack = append_d(stack, sin(d1), err);
      break;
    case 'c':
      stack = pop_d(stack, &d1);
      stack = append_d(stack, cos(d1), err);
      break;
    case 'a':
      stack = pop_d(stack, &d1);
      stack = append_d(stack, tan(d1), err);
      break;
    case 'g':
      stack = pop_d(stack, &d1);
      stack = append_d(stack, 1. / tan(d1), err);
      break;
    case 'l':
      stack = pop_d(stack, &d1);
      stack = append_d(stack, log(d1), err);
      break;
  }
  return stack;
}

double calc_polish(string rpm, double x) {
  int err = 0;
  double data = 0;
  double res_data = 0;
  int count = 0;
  stack_double stack = init_stack_double(&err);

  for (int i = 0; i < rpm.len && !err; i++) {
    while (*(rpm.str + i)) i++;
    count = sscanf(rpm.str + i + 1, "%lf", &data);
    if (count == 1) {
      stack = append_d(stack, data, &err);
    } else {
      if (rpm.str[i + 1] == 'x') {
        stack = append_d(stack, x, &err);
      } else {
        stack = process_op(stack, rpm.str[i + 1], &err);
      }
    }
  }
  stack = pop_d(stack, &res_data);
  return res_data;
}
