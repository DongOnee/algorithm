#include <stdio.h>

int main(void) {
	char str[101];

	while(gets(str) != '\0')
		puts(str);
  return 0;
}
