/**
 * 19.1.7.
 */
#include <cstdio>
#include <cmath>
#define mod 1000000007

int main(int argc, char const *argv[])
{
    long long A, X; scanf("%lld %lld", &A, &X);
    long long ans=1, cnt=1;
    A %= mod;

    while (X)
    {
        if (X%2==1)
        {
            ans *= A;
            ans %= mod;
        }

        A *= A;
        A %= mod;

        X >>= 1;
        cnt <<= 1;
    }
    
    printf("%lld\n", ans);
    return 0;
}
