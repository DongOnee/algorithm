#include <stdio.h>

long int A[100001]; //부모 노드의 인덱스 저장

int main(void) {
  long int n;
  scanf("%ld", &n);
  A[1]=0;
  for (int i =1; i <n; i++) {
    long int x, y;
    scanf("%ld %ld", &x, &y);
    if (A[x] != '\n') A[y] = x;
    else A[x] = y;
  }

  for (int i =2; i <=n; i++) printf("%ld\n", A[i]);
  return 0;
}
