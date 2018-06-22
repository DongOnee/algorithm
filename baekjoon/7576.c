#include <stdio.h>

int a[1001][1001];
int n, m;
int b[100][2];
int flag = 0;
int day = 0;
int count;

void logic(int, int);

int main(void) {
  count = 0;
  // 초기화
  scanf ("%d %d", &m, &n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) {
        b[flag][0] = i;
        b[flag][1] = j;
        flag++;
        count++;
      }
    }
  }

  //play logic
  while(flag) {
    logic(b[flag][0], b[flag][1]);
  }

  return 0;
}

void logic(int x, int y) {

}
