/**
 * 2020.05.14. 21:01 ~
 */
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

typedef pair<int, int> loc;

const int INF = 0x3fffffff;

int n, w;
int dp[1002][1002]; // dp[x][y] : patrol 1 = x, patrol 2 = y 에 있을 때 이동 최소값..?

vector<loc> inc;

inline int calcDist(const int a, const int b)
{
    return abs(inc[a].first - inc[b].first) + abs(inc[a].second - inc[b].second);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    for (int i=0; i<w+2; i++) for (int j=0; j<w+2; j++) dp[i][j] = INF;
    inc.push_back({1, 1});
    inc.push_back({n, n});
    for (int i=0, a, b; i<w; i++)
    {
        cin >> a >> b;
        inc.push_back({a, b});
    }
    dp[0][1] = 0;
    dp[2][1] = calcDist(0, 2);
    dp[0][2] = calcDist(1, 2);

    for( int idxInc = 3; idxInc < w+2; idxInc++ )
    {
        for( int prevIdx = 0; prevIdx < idxInc-1; prevIdx++ )
        {
            dp[prevIdx][idxInc] = min(dp[prevIdx][idxInc], dp[prevIdx][idxInc-1] + calcDist(idxInc-1, idxInc));
            dp[idxInc][prevIdx] = min(dp[idxInc][prevIdx], dp[idxInc-1][prevIdx] + calcDist(idxInc-1, idxInc));

            dp[idxInc][idxInc-1] = min(dp[idxInc][idxInc-1], dp[prevIdx][idxInc-1] + calcDist(prevIdx, idxInc));
            dp[idxInc-1][idxInc] = min(dp[idxInc-1][idxInc], dp[idxInc-1][prevIdx] + calcDist(prevIdx, idxInc));
        }
    }

    for (int i=0; i<w+2; i++)
    {
        for (int j=0; j<w+2; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
