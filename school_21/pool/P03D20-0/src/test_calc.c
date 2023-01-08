#include <stdio.h>

#include "graphic.h"
#include "stack_char.h"
#include "stack_double.h"

int main() {
  string data;
  string test_1 = {.len = 8, .str = "-1.1+1^x"};
  stack_char t = to_pn(test_1);

  data.len = t.len;
  data.str = t.start;
  for (int i = 0; i < t.max_len + 1; i++) {
    printf("%c ", t.start[i], t.start[i]);
  }
  printf("\n\n\n");
  double dd = calc_polish(data, 12.);

  printf("%lf", dd);
  return 1;
}