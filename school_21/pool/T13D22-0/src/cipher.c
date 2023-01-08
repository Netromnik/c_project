#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stac.h"

#define MENU_SIZE 3

typedef struct {
  int number;
  stack_char stack;
} s_item;

s_item input_item(int* err) {
  s_item new_item = {};
  *err = !scanf("%d", &new_item.number);
  while (getchar() != '\n') {
  }
  if (0 < new_item.number && new_item.number <= MENU_SIZE) {
    new_item.stack = stdin_input(err);
  } else if (new_item.number != -1) {
    printf("n/a\n");
  }
  return new_item;
}

void cprint(stack_char stack, int* err) {
  FILE* fp;
  char ch;
  #ifdef LOGGER
  char c[1000] = {};
  #endif

  if ((fp = fopen(stack.start, "r")) == NULL) {
    *err = 2;
  } else {
    ch = getc(fp);
    if (feof(fp) != 0) {
      *err = 1;
    } else {
      printf("%c", ch);
      while (!*err && (ch = getc(fp)) != EOF) printf("%c", ch);
    }
    fclose(fp);
  }
  if (*err) {
    printf("n/a\n");
  } else {
    printf("\n");
  }
}

void fprint(stack_char file_name, stack_char write) {
  FILE* fp;
  if ((fp = fopen(file_name.start, "r+")) == NULL) {
    printf("n/a");
  } else {
    while (getc(fp) != EOF) {
    }

    fprintf(fp, "%s", write.start);
    fclose(fp);
  }
}

void decode(char* path_dir, int shift) {
  FILE* fp = fopen(path_dir, "r+");
  if (fp == NULL) {
    return;
  }
  int ch;
  while ((ch = getc(fp)) != EOF) {
    ch += shift;
    fseek(fp, -1, SEEK_CUR);
    putc(ch, stdin);
    putc(ch, fp);
  }
}

int test_header(char* str) {
  int type = 0;
  while (*str != '\0') str++;
  str--;
  switch (*str) {
    case 'c':
      type = 1;
      break;
    case 'h':
      type = 2;
      break;
    default:
      type = 0;
      break;
  }
  str--;
  return *str == '.' ? type : 0;
}

void process_cripted(stack_char dir_name, int shift) {
  struct dirent* pDirent;
  DIR* pDir;
  pDir = opendir(dir_name.start);
  char full_path[200] = {0};
  if (pDir == NULL) {
    printf("n/a");
    return;
  }

  while ((pDirent = readdir(pDir)) != NULL) {
    strcpy(full_path, dir_name.start);
    strcat(full_path, "/");
    strcat(full_path, pDirent->d_name);
    switch (test_header(pDirent->d_name)) {
      case (1):
        decode(full_path, shift);
        break;
      case (2):
        fclose(fopen(full_path, "w"));
      default:
        break;
    }
  }
  closedir(pDir);
}

int switcher(int* err) {
  s_item item = {.number = 0, {.len = 0, .start = 0}};
  s_item item_old = {.number = 0, {.len = 0, .start = 0}};
  int shift = 0;
  while (item.number != -1) {
    item = input_item(err);
    switch (item.number) {
      case 1:
        cprint(item.stack, err);
        break;
      case 2:
        if (item_old.number == 1) {
          fprint(item_old.stack, item.stack);
          cprint(item_old.stack, err);
        } else {
          printf("n/a\n");
        }
        break;
      case 3:
        scanf("%d", &shift);
        process_cripted(item.stack, shift);
        break;
    }
    if (item_old.stack.start) free(item_old.stack.start);

    item_old = item;
  }
  if (item.stack.start) free(item_old.stack.start);
  return 0;
}

int main() {
  int err = 0;
  switcher(&err);
  return 0;
}
