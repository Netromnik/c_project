#include "s21_string.h"

#define NULL ((void *)0)

int s21_strlen(char *s) {
  char *sc = s;
  while (*sc != '\0') ++sc;

  return sc - s;
}

int s21_strcmp(char *cs, char *ct) {
  unsigned char c1, c2;
  while (1) {
    c1 = *cs++;
    c2 = *ct++;
    if (c1 != c2) return c1 < c2 ? -1 : 1;
    if (!c1) break;
  }
  return 0;
}

char *s21_strcpy(char *dest, char *src) {
  char *tmp = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  return tmp;
}

char *s21_strcat(char *dest, char *src) {
  char *tmp = dest;
  while (*dest) dest++;
  while (*src != '\0') *dest++ = *src++;
  return tmp;
}

char *s21_strchr(char *s, int c) {
  for (; *s != (char)c; ++s)
    if (*s == '\0') return NULL;
  return (char *)s;
}

int s21_memcmp(void *cs, void *ct, int count) {
  unsigned char *su1, *su2;
  int res = 0;
  for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
    if ((res = *su1 - *su2) != 0) break;
  return res;
}

char *s21_strstr(char *s1, char *s2) {
  int l1, l2;
  l2 = s21_strlen(s2);
  if (!l2) return (char *)s1;
  l1 = s21_strlen(s1);
  while (l1 >= l2) {
    l1--;
    if (!s21_memcmp(s1, s2, l2)) return (char *)s1;
    s1++;
  }
  return NULL;
}

int s21_strspn(char *s, char *accept) {
  char *p;
  for (p = s; *p != '\0'; ++p) {
    if (!s21_strchr(accept, *p)) break;
  }
  return p - s;
}

int s21_strcspn(char *s, char *reject) {
  char *p;
  for (p = s; *p != '\0'; ++p) {
    if (s21_strchr(reject, *p)) break;
  }
  return p - s;
}

char *s21_strtok(char *str, char *delim) {
  static char *p = 0;
  if (str)
    p = str;
  else if (!p)
    return 0;
  str = p + s21_strspn(p, delim);
  p = str + s21_strcspn(str, delim);
  if (p == str) return p = 0;
  p = *p ? *p = 0, p + 1 : 0;
  return str;
}
