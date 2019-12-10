#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100000

int seg[2*MAXN+3], n, k;

void update(int idx, int val)
{
    while (0<idx)
    {
        seg[idx] += val;
        idx >>= 1;
    }
}

int query(int idx)
{
    int ret = 0;
    while (0<idx)
    {
        if (idx%2) idx >>= 1;
        else
        {
            ret += seg[idx];
            idx -= 1;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    freopen("11659_input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i=1, a; i<=n; i++)
    {
        scanf("%d", &a);
        update(MAXN+i, a);
    }
    for (int i=0, a, b; i<k; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", query(MAXN+b) - query(MAXN+a-1));
    }
    return 0;
}
