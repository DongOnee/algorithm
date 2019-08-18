#include <stdio.h>

#define MOD 1000000000

long long d[2][10];

int main(int argc, char const *argv[])
{
    d[1][0] = 0;
    for (int i=1; i<10; i++) d[1][i] = 1;
    int n;
    scanf("%d", &n);

    for (int i=2; i<=n; i++)
    {
        d[i%2][0] = (d[(i+1)%2][1])%MOD;
        for (int j=1; j<9; j++) d[i%2][j] = (d[(i+1)%2][j-1] + d[(i+1)%2][j+1])%MOD;
        d[i%2][9] = (d[(i+1)%2][8])%MOD;
    }
    long long sol=0;
    for (int i=0; i<10; i++)
    {
        sol += d[n%2][i];
        sol %= MOD;
    }

    printf("%lld\n", sol);
    return 0;
}
