/**
 * 19.1.10.
 */
#include <cstdio>

#define mode 1000000007LL
long long N, K; 
long long fac[4000000];

long long mul(long long A, long long po)
{
    long long sol=1;
    while (po > 0)
    {
        if (po % 2 == 1)
        {
            sol *= A;
            sol %= mode;
        }

        A *= A;
        A %= mode;
        po >>=1;
    }
    return sol;
}

int main(int argc, char const *argv[])
{
    scanf("%lld %lld", &N, &K);
    if (K == 0 || K == N)
    {
        printf("1\n");
        return 0;
    }

    fac[0] = 1;
    for (int i=1; i<N; i++)
    {
        fac[i] = fac[i-1]*(i+1);
        fac[i] %= mode;
    }
    long long ret = fac[N-1];
    ret *= mul(fac[K-1], mode-2);
    ret %= mode;
    ret *= mul(fac[N-K-1], mode-2);
    ret %= mode;

    printf("%lld\n", ret);
    return 0;
}
