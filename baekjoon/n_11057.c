#include <stdio.h>

int main(int argc, char const *argv[])
{
    // input data
    int n;

    // input 
    scanf("%d", &n);

    // algorithm
    signed long long d[n+1][10];
    int sol=10;
    for (int i=0; i<10; i++)
    {
        d[1][i] = 1;
    }

    for (int i=2; i<=n; i++)
    {
        d[i][0] = 0;
        d[i][1] = 1;
        signed long long tmp = 1;
        signed long long sum = 1;
        for (int j=2; j<10; j++)
        {
            tmp += d[i-1][j];
            d[i][j] = tmp;
            sum += d[i][j];
            sum %= 10007;
        }
        sol = sum;
    }
    printf("%d\n", sol);
    return 0;
}
