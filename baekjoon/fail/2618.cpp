/**
 * 2002.05.13. 20:18 ~
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> loc;

int n, w;
int dp[1003];
vector<loc> incident;

const int INF = 987654321;

int calc_distance(const loc& a, const loc& b)
{
    return (a.first-b.first)*(a.first>=b.first?1:-1) + (a.second-b.second)*(a.second>=b.second?1:-1);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;
    incident.push_back({1, 1});
    incident.push_back({n, n});
    for (int i=0, a, b; i<w; i++)
    {
        cin >> a >> b;
        incident.push_back({a, b});
    }

    // i = 2
    dp[0] = calc_distance(incident[1], incident[2]); // 1 을 2로 보냄
    dp[1] = calc_distance(incident[0], incident[2]); // 0 을 2로 보냄

    for (int i=3; i<w+2; i++)
    {
        dp[i-1] = INF;
        for (int j=0; j<i-1; j++)
        {
            // j 위치와 , i-1 위치에 패트롤이 있는데
            // dp[j] : j 와 i 위치에 패트롤이 있다.
            // j 위치에 있던것이 i 위치로 이동 i-1, i 위치에 패트롤이 위치
            dp[i-1] = min(dp[i-1], dp[j]+calc_distance(incident[j], incident[i]));
            // i-1 위치에 있던 패트롤이 i 위치로 이동 j, i 위칭 패트롤이 위치
            dp[j] = dp[j] + calc_distance(incident[i-1], incident[i]);
        }
    }

    // 최소 값 을 가지고 있는 인덱스 구하기...
    // idx, w+1 incident 위치에 패트롤이 있으면 최소..?
    int idx = 0;
    for (int i=0; i<=w; i++) 
        if (dp[i] < dp[idx]) idx = i;
    cout << dp[idx] << '\n';

    bool toggle = true;
    int prev_idx = -1;
    vector<bool> vt;
    for (int i = w+1; 2<=i; --i)
    {
        for (int j=0; j<i; j++) cout << dp[j] << ' ';
        cout << '\n';
        vt.push_back(toggle);
        if (i-1 > idx)
        {
            int tmp = calc_distance(incident[i-1], incident[i]);
            for (int j=0; j<i; j++)
                dp[j] -= tmp;
        }
        else
        {
            if (prev_idx == -1) prev_idx = i;
            else

            idx = 0;
            for (int j=0; j<i-1; j++)
                if (dp[j] < dp[idx]) idx = j;
            toggle ^= true;
        }
    }

    for (long i = vt.size()-1; 0<i; --i)
    {
        cout << (vt[i-1]^!toggle?1:2) << '\n';
    }


    return 0;
}