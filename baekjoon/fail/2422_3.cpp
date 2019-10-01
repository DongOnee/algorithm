/**
 * 2019.10.01. 22:52 ~
 */
#include <cstdio>

int n, m;
int cnt[201];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        cnt[a]++; cnt[b]++;
    }

    int ans = n * (n-1) * (n-2) / 6;
    for (int i=1; i<=n; i++)
    {
        ans -= (n-2)*cnt[i];
        ans += cnt[i]*(cnt[i]-1)/2;
    }

    printf("%d\n", ans);

    return 0;
}