#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100001
#define INF 1000000001

typedef long long ll;
typedef pair<int, int> pii;

int n;
pii tree[MAXN*2+1];

void update(int treeIdx, pii val)
{
    // printf("Update %d %d %d\n", treeIdx, val.first, val.second);
    tree[treeIdx] = val;
    if (treeIdx > 1 && tree[treeIdx/2].first > val.first) update(treeIdx/2, val); 
}

pii query(int startIdx, int endIdx)
{
    if (endIdx < startIdx) return {INF, -1};
    if (startIdx == endIdx) return tree[startIdx];

    pii l = {INF, -1}, r = {INF, -1}, ret = {INF, -1};
    if (startIdx%2) l = tree[startIdx++];
    if (endIdx%2==0) r = tree[endIdx--];
    ret = query(startIdx/2, endIdx/2);

    return min(min(l, r), ret);
}

ll sol(int st, int ed)
{
    // printf("sol %d %d\n", st, ed);
    if (ed < st) return -1;
    pii tmp = query(MAXN+st, MAXN+ed);
    int height = tmp.first, idx = tmp.second;

    ll l = sol(st, idx-1), r = sol(idx+1, ed);
    // printf("height : %d\tidx : %d\nl : %lld\tr : %lld\n", height, idx, l, r);
    ll ret = (ll) height * (ed - st +1);
    return max(max(l, r), ret);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while (n)
    {
        for (int i=0; i<MAXN*2+1; i++) tree[i] = {INF, INF};
        for (int i=1, a; i<=n; i++)
        {
            scanf("%d", &a);
            update(MAXN + i, {a, i});
        }

        printf("%lld\n", sol(1, n));

        scanf("%d", &n);
    }
    return 0;
}
