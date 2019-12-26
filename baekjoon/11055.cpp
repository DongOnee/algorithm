#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000

int n, arr[MAXN], dp[MAXN];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j]) dp[i] = dp[j];
        }
        dp[i] += arr[i];
    }

    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, dp[i]);

    printf("%d\n", ans);

    return 0;
}
