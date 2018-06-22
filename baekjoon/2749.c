#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  long long a = 0;
  long long b = 1;

  for (int i = 2; i <= N; i++) {
    long long temp = b;
    b += a;
    a = temp;
  }
  int result = (int) (b % 1000000);
  printf("%d\n", result);
  return 0;
}
