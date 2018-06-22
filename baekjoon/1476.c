#include <stdio.h>

int minimum(int, int, int);

int main(void) {
  int E, S, M;
  scanf ("%d %d %d",&E,&S,&M);

  while (!(E==S && S==M && M==E)){
    int min = minimum(E,S,M);
    if (min==E) E+=15;
    else if (min==S) S+=28;
    else M+=19;
  }
  printf("%d\n", E);
  return 0;
}

int minimum(int a, int b, int c) {
  int min;
  if (a<=b) min=a;
  else min=b;
  if(min<=c) return min;
  else return c;
}
