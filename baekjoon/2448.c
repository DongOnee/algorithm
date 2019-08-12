#include <stdio.h>

char star[3072][6144];

void starset(int i, int j){
  star[i][j+2]='*';
  star[i+1][j+1]='*';
  star[i+1][j+3]='*';
  star[i+2][j]='*';
  star[i+2][j+1]='*';
  star[i+2][j+2]='*';
  star[i+2][j+3]='*';
  star[i+2][j+4]='*';
}

void printStar(int count, int i, int j) {
  if(count==3) starset(i, j);
  else {
    printStar(count/2, i, j+count/2);
    printStar(count/2, i+count/2, j);
    printStar(count/2, i+count/2, j+count);
  }
}


int main(void) {
  int a;
  scanf("%d", &a);

  int count =0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a*2; j++) {
      star[i][j]=' ';
    }
  }
  printStar(a,0,0);
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < a*2; j++) {
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
  return 0;
}
