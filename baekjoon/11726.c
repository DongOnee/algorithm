#include <stdio.h>

int main(void) {
  int n;
  int ret;
  scanf("%d",&n);

  int a1=1, a2=2;

  if (n==1) ret = a1;
  else if (n==2) ret = a2;
  else {
    for (int i=2; i<n; i++) {
      if (i%2 == 0) {
        a1 = (a1+a2)%10007;
        ret = a1;
      } else {
        a2 = (a2+a1)%10007;
        ret = a2;
      }
    }
  }
  printf("%d\n",ret);
  return 0;
}
