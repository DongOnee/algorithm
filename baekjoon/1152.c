#include <stdio.h>
#include <string.h>

int main(void) {
  char c[1000000];
  gets(c);
  int i = 0;
  int count = 1;
  while (c[i] != '\0') {
    if(c[i++]==' ') {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
