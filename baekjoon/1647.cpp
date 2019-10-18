#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define MAX_M 1000000

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m;
pipii edges[MAX_M];
int pars[MAX_N], sums[MAX_N];

int findFunc(int idx)
{
    if (idx == pars[idx]) return idx;
    return pars[idx] = findFunc(pars[idx]);
}

bool unionFunc(int s, int l, int pay)
{
    int ss = findFunc(s);
    int ll = findFunc(l);
    
    if (ss == ll) return false;
    else if (ll < ss) swap(ll, ss);
    pars[ll] = ss;
    sums[ss] += sums[ll] + pay;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<n; i++) pars[i] = i;
    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {c, {a-1, b-1}};
    }

    sort(edges, edges+m);

    int idx = 0;
    for (int i=0; i<m; i++)
    {
        pii x = edges[i].second;
        int p = edges[i].first;
        if (unionFunc(x.first, x.second, p)) idx = i;
    }

    printf("%d", sums[0] - edges[idx].first);

    return 0;
}
