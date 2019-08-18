#include <stdio.h>
#include <math.h>

int main(void) {
  int a, b;
  scanf("%d",&a);
  scanf("%d",&b);
  int c[b-a+1];
  for (int i = 0; i < b-a+1; i++)
    c[i]=a+i;

  int sum=0;
  int min=10000;

  for (int i=0; i<b-a+1; i++){
    int T= 1;
    if (c[i]==1) T =0;
    else{
      for (int j=2; j<=(int)sqrt(c[i]) && T; j++)
        if (c[i]%j==0)
          T=0;
      }
    if (T) {
      sum += c[i];
      if (c[i]<min) min=c[i];
    }
  }
  if (sum==0) printf("-1");
  else printf("%d\n%d",sum, min);
  return 0;
}
