/**
 * 19.3.14.
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, dp[50][500001], height[50];
// dp[i][j] = k : i 번째 조각까지 조합 결과 두 탑의 높이 차이가 j 일때 작은 탑의 높이
// 큰 탑의 높이 = k + j
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", height+i);
    sort(height, height+n);

    for (int j=0; j<n; j++) for (int i=0; i<=500000; i++) dp[j][i] = -1;
    dp[0][height[0]] = 0;

    for (int i=1; i<n; i++)
    {
        int segment_height = height[i];
        if (dp[i-1][segment_height] != -1) dp[i][0] = dp[i-1][segment_height] + segment_height;
        if (0<=i-2) dp[i][0] = max(dp[i][0], dp[i-2][0]);

        for (int diff = 1, s, l; diff<500001; diff++)
        {
            // 기존 차이가 diff 보다 작은경우
            int small_target = diff - segment_height;
            // 기존 차이가 diff 보다 큰경우
            int large_target = diff + segment_height;

            if (small_target < 0) s=-1;
            else s = dp[i-1][small_target];
            if (large_target > 500000) l=-1;
            else if (dp[i-1][large_target] == -1) l=-1;
            else l = dp[i-1][large_target] + segment_height;

            dp[i][diff] = max(dp[i-1][diff], max(s, l));
        }
    }
    return 0;
}
