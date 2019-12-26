#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000

int n, arr[MAXN], dp[2][MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[i] > arr[j] && dp[0][i] < dp[0][j]) dp[0][i] = dp[0][j];
        }
        dp[0][i] += 1;
    }

    for (int i=n-1; 0<=i; i--)
    {
        for (int j=n-1; i<j; j--)
        {
            if (arr[i] > arr[j] && dp[1][i] < dp[1][j]) dp[1][i] = dp[1][j];
        }
        dp[1][i] += 1;
    }

    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, dp[0][i] + dp[1][i]-1);

    printf("%d\n", ans);

    return 0;
}
