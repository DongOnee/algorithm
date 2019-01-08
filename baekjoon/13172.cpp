/**
 * 19.1.8.
 */
#include <cstdio>
#define mod 1000000007

long long mul(long long A, long long po)
{
    long long sol=1;
    while (po > 0)
    {
        if (po % 2 == 1)
        {
            sol *= A;
            sol %= mod;
        }

        A *= A;
        A %= mod;
        po >>=1;
    }
    return sol;
}

long long measure(long long A, long long B)
{
    long long remain = A % B;
    if (remain == 0) return B;
    return measure(B, remain);
}

int main(int argc, char const *argv[])
{
    int M; scanf("%d", &M);
    long long ret=0;
    while (M--)
    {
        long long N, S; scanf("%lld %lld", &N, &S);
        long long remain = measure(N, S);
        N /= remain;
        S /= remain;
        long long sol = (mul(N, mod-2)*S)%mod;
        ret += sol;
        ret %= mod;
    }
    printf("%lld\n", ret);
    return 0;
}