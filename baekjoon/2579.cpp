/**
 * 19.4.12.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[301];
int dp[301][2];

// dp[n][2] = max(dp[n-2][j])+arr[n]; (0<=j<3)
// dp[n][1] = dp[n-1][2] + arr[n];
// dp[n][0] = dp[n-1][1] + arr[n];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", arr+i);

    dp[1][1] = arr[1];
    dp[2][0] = dp[1][1] + arr[2];
    dp[2][1] = arr[2];
    dp[3][1] = dp[1][1] + arr[3];
    dp[3][0] = dp[2][1] + arr[3];

    for (int i=4; i<=n; i++)
    {
        dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
        dp[i][0] = dp[i-1][1] + arr[i];
    }

    printf("%d\n", max(dp[n][0], dp[n][1]));

    return 0;
}
