#include <stdio.h>

void logic(int[65][65], int, int, int);

int A[65][65];

int main(void) {
  int N;
  scanf("%d", &N);

  for(int i = 0; i<N; i++) {
    int temp;
    scanf("%d", &temp);
    for(int j = 0; j < N; j++) {
      A[i][N -1 - j] = (temp % 10);
      temp /= 10;
    }
  }
  logic(A, 0,0,N);

  return 0;
}

void logic(int a[65][65], int x, int y, int size) {
  int sol = a[x][y];
  int flag;
  for (int i = 0; i < size; i++) {
    flag =0;
    for (int j = 0; j < size; j++) {
      if (sol != a[x+i][y+j]) {
        flag =1;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag) printf("%d", sol);
  else {
    printf("(");
    logic(a, x, y, size/2);
    logic(a, x, y+size/2, size/2);
    logic(a, x+size/2, y, size/2);
    logic(a, x+size/2, y+size/2, size/2);
    printf(")");
  }

}
