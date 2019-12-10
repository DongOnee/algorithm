#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, ans;
ll k, arr[15];
ll k2, arr2[15];
bool visited[101];

ll run(ll a, bool flag, int idx)
{
    ll ret = 0;

    while (++idx < k2) ret += run(a * arr2[idx], !flag, idx);
    ret += (flag ? -1:1) * (n/a);
    // printf("a : %3lld\t\tflag : %5s\tret : %lld\n", a, flag?"True":"False", ret);

    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%lld%lld", &n, &k);
    for (int i=0; i<k; i++) scanf("%lld", arr+i);
    
    sort(arr, arr+k);
    for (int i=0; i<k; i++) 
    {
        if (visited[arr[i]]) continue;
        arr2[k2++] = arr[i];
        for (int j = arr[i]; j<101; j += arr[i]) visited[j] = true;
    }

    for (int i=0; i<k2; i++) ans += run(arr2[i], false, i);
    
    printf("%lld\n", n - ans);
    
    return 0;
}
