#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_
#define RULE 5
#define PRIORY 13
#define MAX_PRIORITY 4

typedef struct {
  int len;
  char* str;
} string;

typedef struct {
  char c;
  char* str;
} rule;

typedef struct {
  char c;
  int p;
} priory;

priory* init_priory();
double calc_polish(string rpm, double x);
void graphic(string);

#endif  // SRC_HEADER_H_
