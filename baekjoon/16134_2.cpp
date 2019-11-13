// ref. https://www.acmicpc.net/blog/view/29
#include <cstdio>

#define MOD 1000000007LL

typedef long long ll;

ll t1=1, t2=1, t3=1;

ll reverse_mul(ll input)
{
    ll ret = 1, uppers = MOD-2;
    while (uppers)
    {
        if (uppers%2)
        {
            ret *= input;
            ret %= MOD;
        }
        input *= input;
        input %= MOD;
        uppers >>= 1;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int n, r, ans;
    scanf("%d%d", &n, &r);
    for (ll i=1; i<=n; i++)
    {
        t1 *= i;
        t1 %= MOD;
    }
    for (ll i=1; i<=r; i++)
    {
        t2 *= i;
        t2 %= MOD;
    }
    for (ll i=1; i<=n-r; i++)
    {
        t2 *= i;
        t2 %= MOD;
    }
    t3 = reverse_mul(t2) % MOD;

    ans = (t1*t3)%MOD;

    printf("%d\n", ans);
    return 0;
}
