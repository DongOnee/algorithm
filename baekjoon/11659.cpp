#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100000

int seg[MAXN+1], n, k;

int main(int argc, char const *argv[])
{
    // freopen("11659_input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i=1, a; i<=n; i++)
    {
        scanf("%d", &a);
        seg[i] = seg[i-1]+a;
    }
    for (int i=0, a, b; i<k; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", seg[b] - seg[a-1]);
    }
    return 0;
}
