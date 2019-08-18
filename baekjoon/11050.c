#include <stdio.h>

int main(void) {
  int N, K;
  scanf("%d %d", &N, &K);

  int result = 1;
  for (int i = 0; i < K; i++) {
    result *= (N-i);
  }
  for (int i = 1; i <= K; i++) {
    result /= i;
  }

  printf("%d\n", result);
  return 0;
}
