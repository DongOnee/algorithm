#include<cstdio>
#include<vector>
using namespace std;

typedef long long ll;

ll a[17],n,m;
ll visited[17];
ll sum;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < m; i++) scanf("%lld", a+i);

    ll x = (1 << m);
    for (int i = 0; i < x; i++)
    {
        ll ch = 0;
        ll gap = 0;
        for (int y = 0; y < m; y++)
        {
            if (i & (1 << y))
            {
                ch++;
                if (gap == 0) gap = a[y];
                else gap = gap*a[y] / gcd(gap, a[y]);
            }
        }
        if (ch)
        {
            ll p = n / gap;
            if (ch % 2 == 0) p = -p;
            sum += p;
        }
    }
    printf("%lld\n", n-sum);
}
