#include <stdio.h>

int main(void) {
  int count;
  scanf("%d",&count);

  for(int k=0; k<count; k++) {
    int N;
    scanf("%d",&N);
    int ret;
    int a0=1, a1=2, a2=3;
    for (int i=3; i<N; i++) {
      if (i%3 == 0) {
        a0 = a0+a1+a2;
        ret = a0;
      }
      else if (i%3 == 1) {
        a1 = a0+a1+a2;
        ret = a1;
      }
      else {
        a2 = a0+a1+a2;
        ret = a2;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
