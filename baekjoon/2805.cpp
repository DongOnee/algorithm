/**
 * 19.06.13 00:23 ~
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long ans;
vector<long long> trees;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
    {
        long long a; scanf("%lld", &a);
        trees.push_back(a);
    }

    sort(trees.begin(), trees.end());

    long long l = 0, r = trees[n-1];
    while (l < r)
    {
        long long cutter = (l + r) /2 ;
        long long asemble = 0;
        for (long long tree : trees) asemble += (tree < cutter ? 0 : tree - cutter);
        if (asemble < m) r = cutter;
        else
        {
            l = cutter+1;
            ans = max(ans, cutter);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
