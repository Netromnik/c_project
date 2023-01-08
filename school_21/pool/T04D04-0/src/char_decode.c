#include <stdio.h>


int convChar() {
  char end = ' ';
  unsigned int w = 0;
  while (end != '\n' )
  {
    scanf("%c%c", &w, &end);
    if(w>256 || !( end == ' ' || end == '\n')){
      printf("n/a");
      return 0;
    }
  	printf("%x", w);
    if (end != '\n') {
      printf(" ");
    }
  }
  return 0;
}

int convHex() {
  char end = ' ';
  unsigned int w = 0;
  while (end != '\n' )
  {
    scanf("%x%c", &w, &end);
    if(w>256){
      printf("n/a");
      return 0;
    }
  	printf("%c", w);
    if (end != '\n') {
      printf(" ");
    }
  }
  return 0;
}

int main(int arg, char **args) {
    if(arg == 0) {
      printf("n/a");
      return 0;
    }
    else if (args[1][0] == '0')
    {
        convChar();
    }else if (args[1][0] == '1')
    {
        convHex(); 
    } 
}
