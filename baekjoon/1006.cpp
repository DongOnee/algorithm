/**
 * 19.1.29.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, W;
int T;

int enemy[10002][2];
int dp[10002][2][3]; // 0: 개인방어, 1: 이전것과 묶어서 방어, 2: 인접한것과 묶어서 방어

void func(int case_)
{
    if (case_ & 1) {enemy[0][0] = enemy[N][0]; enemy[N][0] = W+1;}
    if (case_ & 2) {enemy[0][1] = enemy[N][1]; enemy[N][1] = W+1;}
        
    dp[0][0][0] = (enemy[0][0] <= W ? 1 : 0)
    dp[0][1][0] = (enemy[0][1] <= W ? 1 : 0)
    
    dp[0][0][1] = 0;
    dp[0][1][1] = 0;
    dp[0][0][2] = 0;
    dp[0][1][2] = 0;

    for (int i=1; i<=N; i++)
    {
        for (int j=0; j<2; j++)
        {
            if (enemy[i][j] <= W ) dp[i][j][0] = min(dp[i-1][j][0], min(dp[i-1][j][1], dp[i-1][j][2])) +1;
            if (enemy[i-1][j] + enemy[i][j] <= W) dp[i][j][1] = dp[i-1][j][0];
            else dp[i][j][1] = W+1;
        }

        if (enemy[i][0] + enemy[i][1] <= W)
        {
            dp[i][0][2] = min(dp[i-1][0][1], dp[i-1][0][0]) + min(dp[i-1][1][1], dp[i-1][1][0]) +1;
        }
        else dp[i][0][2] = W+1;
    }
    if (case_ & 1) {enemy[N][0] = enemy[0][0]; enemy[0][0] = W+1;}
    if (case_ & 2) {enemy[N][1] = enemy[0][1]; enemy[0][1] = W+1;}
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int test_case = 0; test_case<T; test_case++)
    {
        scanf("%d %d", &N, &W);
        for (int i=0; i<2; i++) for (int j=1; j<=N; j++)
        {
            scanf("%d", &enemy[j][i]);
        }
        for (int i=0; i<4; i++) func(i)
    }
    return 0;
}
