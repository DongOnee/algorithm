#include <stdio.h>

int res[41][2] = {{1,0}, {0,1}, };

void fib(int n) {
    if(n>1) 
        for(int i=2; i<=n; i++) 
            if(res[i][0]==0) {
                res[i][0] = res[i-1][0] + res[i-2][0];
                res[i][1] = res[i-1][1] + res[i-2][1];
            }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        fib(N);
        printf("%d %d\n", res[N][0], res[N][1]);
    }
    return 0;
}