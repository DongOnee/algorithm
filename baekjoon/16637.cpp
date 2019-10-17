#include <cstdio>
#include <algorithm>
using namespace std;

int dp[12][2];

int calc(const int a, const int b, const char c)
{
    if (c == '+') return a+b;
    else if (c == '-') return a-b;
    return a*b;
}

int main(int argc, char const *argv[])
{
    int n;
    char cmd[20];
    scanf("%d%s", &n, cmd);

    dp[0][0] = cmd[0]-'0';
    dp[0][1] = cmd[0]-'0';

    for (int i=1; i<n; i+=2)
    {
        int inMax1 = calc(dp[i/2][0], cmd[i+1]-'0', cmd[i]);
        int inMax2 = calc((i==1?0:dp[i/2-1][0]), calc(cmd[i-1]-'0', cmd[i+1]-'0', cmd[i]), (i==1?'+':cmd[i-2]));
        int inMin1 = calc(dp[i/2][1], cmd[i+1]-'0', cmd[i]);
        int inMin2 = calc((i==1?0:dp[i/2-1][1]), calc(cmd[i-1]-'0', cmd[i+1]-'0', cmd[i]), (i==1?'+':cmd[i-2]));
        
        dp[i/2+1][0] = max(inMax1, max(inMax2, max(inMin1, inMin2)));
        dp[i/2+1][1] = min(inMax1, min(inMax2, min(inMin1, inMin2)));
        // printf("%d %d\n", dp[i/2+1][0], dp[i/2+1][1]);
    }

    printf("%d\n", dp[n/2][0]);
    return 0;
}
