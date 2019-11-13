#include <cstdio>
#include <vector>
using namespace std;

#define MOD 1000000007LL

typedef long long ll;

ll t1=1, t2=1, t3=1;

ll xgcd(ll a, ll b)
{
    ll s[2] = {1, 0}, t[2] = {0, 1}, r[2] = {a, b}, q;
    bool toggle = false;
    while (true)
    {
        ll r1 = r[toggle], r2 = r[!toggle];
        q = r1 / r2;
        r[toggle] = r1 % r2;

        if (r[toggle] == 0) break;
        ll s1 = s[toggle], s2 = s[!toggle];
        ll t1 = t[toggle], t2 = t[!toggle];

        s[toggle] = s1 - s2*q;
        t[toggle] = t1 - t2*q;
        toggle ^= true;
    }
    
    return t[!toggle];
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
    t3 = xgcd(MOD, t2);

    ans = (t1*t3)%MOD;

    printf("%lld\n", ans<0?MOD+ans:ans);
    return 0;
}
