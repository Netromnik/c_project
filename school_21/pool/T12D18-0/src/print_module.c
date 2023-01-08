#include "print_module.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

char print_char(char* ch) { return puts(ch); }

void print_log(char (*print)(char*), char* message) {
  char str[80];
  char cutT[30];
  time_t rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(cutT, 128, " %H:%M:%S ", timeinfo);
  strcat(str, Log_prefix);
  strcat(str, cutT);
  strcat(str, message);
  (*print)(str);
}
