#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, ans, k, arr[15];
bool visited[101];

ll run(ll a, bool flag, int idx)
{
    ll ret = 0;

    while (++idx < k) ret += run(a * arr[idx], !flag, idx);
    ret += (flag ? -1:1) * (n/a);


    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%lld%lld", &n, &k);
    for (int i=0; i<k; i++) scanf("%lld", arr+i);

    for (int i=0; i<k; i++) ans += run(arr[i], false, i);
    
    printf("%lld\n", n - ans);
    
    return 0;
}
