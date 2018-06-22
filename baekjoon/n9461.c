#include <stdio.h>
#include <stdlib.h>

unsigned int *res;
int d[101];

void sol(int tt) {
    int N;
    scanf("%d", &N);
    if (5<N) 
    for (int i=6; i<=N; i++) {
        if (d[i]!=0) continue;
        if (i==1 || i==2||i==3) d[i] =1;
        else if(i==4||i==5) d[i] = 2;
        else d[i] = d[i-1] + d[i-5];
    }
    res[tt]=d[N];
}

int main(void) {
    int t;
    scanf("%d", &t);
    d[1]=d[2]=d[3]=1;
    d[4]=d[5]=2;
    res=(unsigned int*)malloc(sizeof(unsigned int)*t);
    int tt;
    for (tt=1; tt<=t; tt++) sol(tt);
    for (tt=1; tt<=t; tt++) printf("%u\n",res[tt]);

    return 0;
}