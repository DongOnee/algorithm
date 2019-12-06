#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, pages[501], dp[501][501], sum[501];
// dp[i][j] : pages[i] ~ pages[j] 를 합치는데 드는 비용 + min(k = i ... j)( min[i][k] + min[k+1][j] )

void run()
{
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 1; i+gap <= n; i++)
        {
            int j = i + gap;
            for (int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
        }
    }
}

void init()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", pages+i);
        sum[i] = sum[i-1] + pages[i];
        for (int j=1; j<=n; j++) dp[i][j] = INF;
        dp[i][i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    while (t--)
    {
        init();
        run();
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
