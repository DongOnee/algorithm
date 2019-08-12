/**
 * 19.4.9. 15:07~15:55
 */
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, int> tp[21];
int dp[21];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        tp[i] = {a, b};
    }

    for (int i=n-1; 0<=i; i--)
    {
        // printf("i: %d\n", i);
        if (n<i+tp[i].first)
        {
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(tp[i].second+dp[i+tp[i].first], dp[i+1]);
    }
    // for (int i=0; i<n; i++) printf("dp[%d] : %d\n", i, dp[i]);
    sort(dp, dp+n);
    printf("%d\n", dp[n-1]);
    return 0;
}
