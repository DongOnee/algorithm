#include <stdio.h>

int main(void) {
  int A, B, C;
  scanf("%d",&A);
  scanf("%d",&B);
  scanf("%d",&C);

  int multiple = A*B*C;
  int count[10]={0,};

  while (multiple!=0) {
    count[multiple%10]++;
    multiple /=10;
  }

  for (int i =0; i<10 ; i++)
    printf("%d\n", count[i]);
  return 0;
}
