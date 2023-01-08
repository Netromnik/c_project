
#include <stdlib.h>

#include "graphic.h"
#include "stack_char.h"
#include "validation.h"

int main(void) {
  int err = 0;
  stack_char sc;
  string ss = cast_string();
  if (ss.len == 0) err = 1;

  if (!err) {
    stack_char sc = to_pn(ss, &err);
    free(ss.str);
  }
  if (!err) {
    ss.len = sc.len;
    ss.str = sc.start;
    graphic(ss);
    free(ss.str);
  }
  return err;
}
