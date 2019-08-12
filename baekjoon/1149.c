#include <stdio.h>

void DP_RGB(int);

int** ptr;

int main(void) {
  int N;
  scanf("%d", &N);
  int RGB[N][3];
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &RGB[i][0], &RGB[i][1], &RGB[i][2]);
  }
  ptr = RGB;


  return 0;
}
