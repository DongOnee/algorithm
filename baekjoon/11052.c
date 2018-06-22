#include <stdio.h>

int main (void) {
  int N;
  scanf("%d", &N);
  int price[1001];
  price[0] = 0;
  for (int i = 1; i <=  N; i++) scanf("%d", &price[i]);

  int profit[N];
  profit[0] = 0;
  for (int i = 1; i <= N; i++) {
    profit[i] = price[i];
    for (int j = 0; j < i; j++)
      if (profit[i] < price[j] + profit[i-j])
        profit[i] = price[j] + profit[i-j];
  }
  printf("%d\n", profit[N]);
}
