#include <stdio.h>

#define mod 1000000000

int d[202][202];

void sol(int n, int k){
    int kk, nn;
    for (nn=0; nn<=n; nn++) {
        d[1][nn] =1;
        d[0][nn] =1;
    }
    for (kk=2; kk<=k; kk++) {
        for (nn=0; nn<=n; nn++) {
            for (int m=0; m<=nn; m++){
                d[kk][nn]+=d[kk-1][nn-m];
                d[kk][nn] %=mod;
            }
        }
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    sol(n, k);
    printf("%d", d[k][n]);
    return 0;
}