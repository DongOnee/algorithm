#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void logic(int, int, int, int);

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n",(int) pow(2,n)-1);
  logic(1, 3, 2, n);

  return 0;
}

void logic(int A, int B, int C, int size) {
  if (size == 1) {
    printf("%d %d\n", A, B);
  }
  else {
    logic(A, C, B, size-1);
    logic(A, B, C, 1);
    logic(C, B, A, size-1);
  }
}
