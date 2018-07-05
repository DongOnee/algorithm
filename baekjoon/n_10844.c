#include <stdio.h>

unsigned long a[10] = {0,1,1,1,1,1,1,1,1,1};

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i=1; i < N; i++) {
    int b[10]={0,};
    int j=0;
    while (j<10) {
      if (j == 0) b[0] = a[1];
      else if (j == 9) b[9] = a[8];
      else b[j] = a[j-1] + a[j+1];
      j++;
    }
    for (int i = 0; i < 10; i++) {
      a[i] = b[i];
    }
  }
  unsigned long ret=0;
  for (int i=0; i<10; i++) {
    ret += a[i];
  }
  for (int i=0; i<10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("%lu\n", ret%1000000000);
  return 0;
}
