/**
 * GG
 * 
 * DP 문제인데 굉장히 심플하게 생각하고 
 * 심플하게 공식을 구하고
 * 심플하게 ... 했으면 좋았을듯 싶다.
 * 굉장히 많은 참조는 이 블로그에 있다 https://blog.naver.com/PostView.nhn?blogId=pasdfq&logNo=221327312217
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
using namespace std;

typedef pair<int, int> loc;

int n, w;
vector<loc> inc;

int dp[1002][1002];
bool choosed[1002][1002];

inline int calcDist(const int a, const int b)
{
    return abs(inc[a].first - inc[b].first) + abs(inc[a].second - inc[b].second);
}

int solv(int pat1, int pat2)
{
    int cur = max(pat1, pat2) + 1;
    if ( cur == w+2 ) return 0;

    int& ret = dp[pat1][pat2];
    if( ret != -1 ) return ret;

    // pat1 이 cur 사건 해결할 경우
    ret = solv(cur, pat2) + calcDist(pat1, cur);

    // pat2 가 cur 사건을 해결할 경우
    int ret2 = solv(pat1, cur) + calcDist(pat2, cur);
    if( ret2 < ret )
    {
        ret = ret2;
        choosed[pat1][pat2] = true;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n >> w;
    inc.push_back({1, 1});
    inc.push_back({n, n});

    for (int i=0, a, b; i<w; i++)
    {
        cin >> a >> b;
        inc.push_back({a, b});
    }

    cout << solv(0, 1) << '\n';

    for (int pat1 = 0, pat2 = 1; max(pat1, pat2)+1 < w+2; )
    {
        cout << (choosed[pat1][pat2]?2:1) << '\n';
        if( choosed[pat1][pat2] ) pat2 = max(pat1, pat2)+1;
        else pat1 = max(pat1, pat2)+1;
    }

    return 0;
}
