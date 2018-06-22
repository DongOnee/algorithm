#include <stdio.h>

long long d[100001][2];  // d[i][j] = i 줄 j 번째 스티커의 가치
long long a[100001][3];  // a[i][j] = i 번째 스티커 중 j = 0 : 첫번째줄 꺼 선택 했을때 총 가치
                          //                           = 1 : 두번째줄   "  = 3 선택 안함
#define max(a,b) (((a)>(b))?(a):(b))

int main(void) {
  int count;
  scanf("%d", &count);
  while (count--) {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
      scanf("%lld", &d[i][0]);
    }
    for (int i = 1; i <= N; i++) {
      scanf("%lld", &d[i][1]);
    }
    a[0][0] = 0;
    a[0][1] = 0;
    a[0][2] = 0;
    for (int i = 1; i <= N; i++) {
      a[i][0] = max(a[i-1][1], a[i-1][2]) + d[i][0];
      a[i][1] = max(a[i-1][0], a[i-1][2]) + d[i][1];
      a[i][2] = max(a[i-1][2], max(a[i-1][0], a[i-1][1]));
    }
    long long ans = 0;
      for (int i=1; i<=N; i++) {
          ans = max(max(ans,a[i][0]),max(a[i][1],a[i][2]));
      }
      printf("%lld\n",ans);
  }
  return 0;
}
