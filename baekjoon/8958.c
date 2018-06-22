#include <stdio.h>
#include <string.h>

int main(void) {
  int N;
  scanf("%d",&N);
  char[80] Q[N];
  int result[N]={0,};
  for(int i=0; i<N; i++) {
    scanf("%s",Q[i]);
    
  }

  for (int i=0; i<N; i++)
    printf("%d\n",result[i]);
  return 0;
}
