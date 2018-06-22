#include <stdio.h>
#include <string.h>

#define mod 1000000

char c[5002];
int d[5001];

int main(void){
    d[0]=1;
    scanf("%s", c+1);
    int n =strlen(c+1);
    int i;
    for(i=1; i<=n; i++) {
        int x = c[i] -'0';
        if (0<x && x<10) {
            d[i] +=d[i-1];
            d[i] %= mod;
        }
        if (i==1) continue;
        if (c[i-1]=='0') continue;
        x = (c[i-1]-'0')*10+x;
        if (10<=x && x<=26) {
            d[i] += d[i-2];
            d[i] %= mod;
        }
    }
    printf("%d", d[n]);
    return 0;
}