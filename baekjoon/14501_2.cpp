#include <iostream>

using namespace std;

const int MAXDAY = 15;
const int INF = 987654321;

int dday;
int t[MAXDAY], p[MAXDAY];
int dp[MAXDAY + 1][2];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> dday;
    for (int i = 0 ; i < dday; ++i) {
        cin >> t[i]; 
        cin >> p[i];
        dp[i+1][0] = -INF;
        dp[i+1][1] = -INF;
    }

    dp[dday][0] = dp[dday][1] = 0;
    for (int d = dday - 1; 0 <= d; --d) {
        dp[d][0] = max(dp[d+1][0], dp[d+1][1]);
        if (d + t[d] <= dday)
            dp[d][1] = p[d] + max(dp[d + t[d]][0], dp[d + t[d]][1]);
    }


    cout << max(dp[0][0], dp[0][1]) << '\n';

    return 0;
}
