#include <stdio.h>

long long a[101][2]; // a[i][j] : 문자의 길이 i, 맨 오른쪽 자리 j 인 수의 갯수

int main(void) {
  int N;
  scanf("%d", &N);

  a[1][0] = 0;
  a[1][1] = 1;

  for (int i = 2; i <= N; i++) {
    a[i][0] = a[i-1][0] + a[i-1][1];
    a[i][1] = a[i-1][0];
  }

  printf("%lld\n", a[N][0] + a[N][1]);
  return 0;
}
