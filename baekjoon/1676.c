#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  int Nfacto = 1;
  int i = 1;
  int count = 0;
  do {
    if(Nfacto % 10 == 0) {
      count++;
      Nfacto /= 10;
      continue;
    } else {
      Nfacto *= ++i;
    }
  } while (i <= N);
  printf("%d\n", count);
  return 0;
}
