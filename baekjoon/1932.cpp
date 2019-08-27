/**
 * 2019-08-27 22:29 ~ 22:52
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int map[501][501], dp[501][501], n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            scanf("%d", map[i]+j);
            dp[i][j] = map[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    sort(dp[n] + 1, dp[n] + n + 1);

    printf("%d\n", dp[n][n]);

    return 0;
}
