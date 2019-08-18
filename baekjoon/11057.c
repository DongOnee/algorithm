#include <stdio.h>

int main(int argc, char const *argv[])
{
    // input data
    int n;

    // input 
    scanf("%d", &n);

    // algorithm
    long long d[n+1][10];
    for (int i=0; i<10; i++)
    {
        d[1][i] = 1;
    }
    long long sol=10;

    for (int i=2; i<=n; i++)
    {
        long long sum = 0;
        long long tmp = 0;
        for (int j=0; j<10; j++)
        {
            sum += d[i-1][j];
            d[i][j] = sum% 10007;
            tmp += d[i][j];
            tmp %= 10007;
        }
        if (i == n) 
        {
            sol = tmp;
            // for (int k=0; k<10; k++) printf("%lld ", d[i-1][k]);
            // puts("");
            // for (int k=0; k<10; k++) printf("%lld ", d[i][k]);
        }
    }
    printf("%lld\n", sol);
    return 0;
}
