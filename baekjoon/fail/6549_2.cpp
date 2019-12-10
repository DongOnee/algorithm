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
int heights[MAXN*2+1];

void update(int input, int idx)
{
    heights[idx] = input;
    if (idx > 1 && heights[idx/2] > input) update(input, idx/2);
}

int search(int st, int ed)
{
    if (st == ed) return st;
    int m = search((st+1)/2, (ed-1)/2);
    int ret = (heights[st]<heights[ed]?st:ed);

    return heights[ret]<heights[m]?ret:m;
}

ll sol(int st, int ed)
{
    printf("sol %d %d\n", st, ed);
    if (ed<st) return 0;
    int idx = search(st, ed);
    ll ret = (ll) heights[idx] * (ed-st+1), l=0, r=0;

    l = sol(st, idx-1), r = sol(idx+1, ed);
    return max(ret, max(l, r));
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    while(n)
    {
        memset(heights, INF, sizeof(heights));
        int ans = 0;

        for (int i=0, a; i<n; i++)
        {
            scanf("%d", &a);
            update(a, i + MAXN);
        }

        printf("%lld", sol(MAXN, MAXN+n-1));
        
        scanf("%d", &n);
    }
    return 0;
}
