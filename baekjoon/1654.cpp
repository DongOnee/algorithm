/**
 * 19.06.13 23:39 ~ 24:40
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<long long> vt;
long long ans;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &k, &n);
    for (int i=0; i<k; i++)
    {
        long long a;
        scanf("%lld", &a);
        vt.push_back(a);
    }

    sort(vt.begin(), vt.end());

    long long l = 1, r = vt[k-1]+1;
    while (l < r)
    {
        long long mid = (l+r)/2;
        int cnt = 0;
        for (auto x : vt) cnt += x/mid;
        if (cnt < n) r = mid;
        else
        {
            l = mid+1;
            ans = max(ans, mid);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
