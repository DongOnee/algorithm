#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef int* (*func_ptr)();

const int MAXN = 10'000;
const int INF = 654'321;

const int INNER  = 0;
const int OUTTER = 1;
const int BOTH   = 2;

int n, w;
int enemy_count[MAXN+4][2];
int enemy_count_cp[MAXN+4][2];
int dp[MAXN+4][3];

void init() 
{
    cin >> n >> w;
    for (auto& d : {INNER , OUTTER})
        for (int i = 0; i < n; ++i) {
            cin >> enemy_count_cp[i][d];
        }
}

int* case_none_combine()
{
    dp[0][INNER]    = 1;
    dp[0][OUTTER]   = 1;
    dp[0][BOTH]     = (enemy_count[0][INNER] + enemy_count[0][OUTTER] <= w ? 1 : 2);

    return &dp[n-1][BOTH];
}

int* case_inner_combine()
{
    dp[0][INNER]    = 1;
    dp[0][OUTTER]   = 1;
    dp[0][BOTH]     = 2;

    enemy_count[0][INNER] = INF;

    return &dp[n-1][OUTTER];
}

int* case_outter_combine()
{
    dp[0][INNER]    = 1;
    dp[0][OUTTER]   = 1;
    dp[0][BOTH]     = 2;

    enemy_count[0][OUTTER] = INF;

    return &dp[n-1][INNER];
}

int* case_both_combine()
{
    dp[0][INNER]    = INF;
    dp[0][OUTTER]   = INF;
    dp[0][BOTH]     = 2;

    enemy_count[0][INNER]   = INF;
    enemy_count[0][OUTTER]  = INF;

    return &dp[n-2][BOTH];
}

void run()
{
    int ans = INF;

    vector<func_ptr> cases;
    
    cases.push_back(case_none_combine);

    if (n > 2) {

    if (enemy_count_cp[0][INNER] + enemy_count_cp[n-1][INNER] <= w)
        cases.push_back(case_inner_combine);

    if (enemy_count_cp[0][OUTTER] + enemy_count_cp[n-1][OUTTER] <= w)
        cases.push_back(case_outter_combine);

    if (enemy_count_cp[0][INNER]  + enemy_count_cp[n-1][INNER]  <= w 
              && enemy_count_cp[0][OUTTER] + enemy_count_cp[n-1][OUTTER] <= w)
        cases.push_back(case_both_combine);
    }

    for (auto& func : cases) {
        for (int i = 0; i < n; ++i) {
            enemy_count[i][INNER]  = enemy_count_cp[i][INNER];
            enemy_count[i][OUTTER] = enemy_count_cp[i][OUTTER];
        }

        auto ret = func();

        for (int idx = 1; idx < n; ++idx) {
            dp[idx][INNER] = dp[idx][OUTTER] = dp[idx-1][BOTH] + 1;
            dp[idx][BOTH] = dp[idx-1][BOTH] + 2;

            if (enemy_count[idx-1][INNER] + enemy_count[idx][INNER] <= w) {
                dp[idx][INNER] = min(dp[idx][INNER], dp[idx-1][OUTTER] + 1);
            }

            if (enemy_count[idx-1][OUTTER] + enemy_count[idx][OUTTER] <= w) {
                dp[idx][OUTTER] = min(dp[idx][OUTTER], dp[idx-1][INNER] + 1);
            }

            dp[idx][BOTH] = min(dp[idx][BOTH], min(dp[idx][INNER], dp[idx][OUTTER]) + 1);
            if (enemy_count[idx][INNER] + enemy_count[idx][OUTTER] <= w) {
                dp[idx][BOTH] = min(dp[idx][BOTH], dp[idx-1][BOTH] + 1);
            }
            if (enemy_count[idx][INNER] + enemy_count[idx-1][INNER] <= w 
                        && enemy_count[idx][OUTTER] + enemy_count[idx-1][OUTTER] <= w ) {
                if (idx == 1) dp[idx][BOTH] = min(dp[idx][BOTH], 2);
                else dp[idx][BOTH] = min(dp[idx][BOTH], dp[idx-2][BOTH] + 2);
            } 
        }

        ans = min(ans, *ret);
    }

    cout << ans << '\n';
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t; cin >> t;
    while (t--){
        init();
        run();
    }

    return 0;
}
