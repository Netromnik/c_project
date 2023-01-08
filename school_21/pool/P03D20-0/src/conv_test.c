#include <stdio.h>
#include <stdlib.h>

#include "stack_char.h"

void test(string s ) {
  stack_char t;
  t = to_pn(s);
  if (t.start) {
    for (int i = 0; i < t.max_len + 1; i++) {
      printf("%d[%c] ", t.start[i], t.start[i]);
    }
  }
  printf("\n");
  delete(t);
}
void main() {
  string test_1 = {.len = 5, .str = "1.1+1"};
  string test_2 = {.len = 5, .str = "1*1+1"};
  string test_3 = {.len = 8, .str = "1+(1)*1"};
  string test_4 = {.len = 7, .str = "(1+1)*1"};

  test(test_1);
  test(test_2);
}
