/**
 * 19.2.26.
 * ref. https://jason9319.tistory.com/44
 * 이분탐색? 세그먼트 tree???
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100000
#define INF 1000000001

typedef long long ll;

int n;
int tree[MAXN*2+1];
int heights[MAXN];

void update(int idxHeight, int idxTree)
{
    tree[idxTree] = idxHeight;
    if (idxTree > 1 && heights[tree[idxTree/2]] > heights[idxHeight]) update(idxHeight, idxTree/2);
}

int searchMinimunIndex(int startTreeIdx, int endTreeIdx)
{

    if (endTreeIdx < startTreeIdx) return -1;
    if (startTreeIdx == endTreeIdx) return startTreeIdx;

    int l = -1, r = -1, m = -1;
    if (startTreeIdx%2 == 1) l = tree[startTreeIdx++];
    if (endTreeIdx%2 == 0) r = tree[endTreeIdx--];
    m = searchMinimunIndex(startTreeIdx/2, endTreeIdx/2);

    l = (l==-1?INF:heights[l])<(r==-1?INF:heights[r])?tree[l]:tree[r];
    m = (l==-1?INF:heights[l])<(m==-1?INF:heights[m])?tree[l]:tree[m];
    return m;
}

ll sol(int st, int ed)
{
    printf("sol %d %d ", st, ed);
    if (ed < st) return -1;
    // Find Lowest index
    int a = searchMinimunIndex(st, ed);
    printf("%d\n", a);
    // Calculate area
    ll ret = heights[a] * (ed-st+1);
    ll l = sol(st, MAXN+a-1), r = sol(MAXN+a+1, ed);
    return max(ret, max(l, r));
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while(n)
    {
        memset(heights, 0, sizeof(heights));
        int ans = 0;

        for (int i=1; i<=n; i++)
        {
            scanf("%d", heights+i);
            update(i, MAXN + i);
        }

        printf("%lld\n", sol(MAXN+1, MAXN+n));
        
        scanf("%d", &n);
    }
    return 0;
}
