#include <stdio.h>

int max(int[]);

int value[10001];
int d[10001][3];

int main(void){
  int n;
  scanf("%d", &n);

  int i = 1;
  d[0][0] = d[0][1] = d[0][2] = 0;
  while(i <= n) {
    scanf("%d", &value[i]);
    d[i][0] = max(d[i-1]);
    d[i][1] = d[i-1][0] + value[i];
    d[i][2] = d[i-1][1] + value[i];
    i++;
  }
  printf("%d\n", max(d[n]));


  return 0;
}

int max(int a[3]) {
  int maximum = a[0];
  if (maximum < a[1]) maximum = a[1];
  if (maximum < a[2]) maximum = a[2];
  return maximum;
}
