#include <cstdio>
#define MOD 1000000007LL

typedef long long ll;

int n, k;
ll answer, fac_n = 1, fac_k, fac_n_k;

ll multiple(ll input, ll p)
{
    if (input == 1) return 1;
    ll ans = 1, mul = input;
    while (p)
    {
        if (p % 2) ans *= mul;
        
        p >>= 1;
        mul *= mul;
        mul %= MOD;
        ans %= MOD;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    
    for (int i=0; i<=n; i++)
    {
        fac_n *= (i == 0?1:i);
        fac_n %= MOD;
        if (i == k) fac_k = fac_n;
        if (i == n-k) fac_n_k = fac_n;
    }

    answer = fac_n;
    answer *= multiple(fac_k, MOD-2);
    answer %= MOD;
    answer *= multiple(fac_n_k, MOD-2);
    answer %= MOD;

    printf("%lld\n", answer);
    return 0;
}
