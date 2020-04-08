/**
 * 2020.04.06 21:06 ~
 */
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 16'000'000

int n, cost[16][16], startIdx;
int dp[16][1<<16];

int func(int curIdx, int passedBit)
{
    if (passedBit == (1<<n)-1) return dp[curIdx][passedBit] + cost[curIdx][0]>0?cost[curIdx][0]:MAX;
    if (dp[curIdx][passedBit] > 0) return dp[curIdx][passedBit];
    dp[curIdx][passedBit] = MAX;
    for (int i=0; i<n; i++)
    {
        if (!((1<<i) & passedBit) && cost[curIdx][i] > 0 )
            dp[curIdx][passedBit] = min(dp[curIdx][passedBit], func(i, passedBit | (1<<i)) + cost[curIdx][i]);
    }
    return dp[curIdx][passedBit];
}

int main(int argc, char const *argv[])
{
    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> cost[i][j];

    cout << func(0, 1) << '\n';

    return 0;
}
