#include <stdio.h>

int main(void) {
  int N;
  scanf("%d", &N);

  double a = 0;
  double b = 1;

  for (int i = 2; i <= N; i++) {
    double temp = b;
    b += a;
    a = temp;
  }

  printf("%.0f\n", b);
  return 0;
}
