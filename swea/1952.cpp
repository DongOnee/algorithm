#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

enum PAYMENT {
    PPD,
    PPM,
    PPM3,
    PPY,
    PPMAX
};

int payment[PPMAX];
int dp[12 + 3][2];
int use_count[12 + 3];

void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < PPMAX; ++i) cin >> payment[i];
    for (int i = 0; i < 12; ++i) cin >> use_count[i];
}

void run()
{
    for (int month = 12; 0 < month; --month) {
        int idx = month - 1;
        int month_pay = (use_count[idx] == 0? 0 : min(payment[PPM], use_count[idx] * payment[PPD]));
        dp[idx][0] = month_pay + min(dp[idx+1][0], dp[idx+1][1]);
        dp[idx][1] = (use_count[idx] == 0 && use_count[idx+1] == 0 && use_count[idx+2] == 0?0:payment[PPM3]) + min(dp[idx+3][0], dp[idx+3][1]);
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << min(payment[PPY], min(dp[0][0], dp[0][1])) << '\n';
    }

    return 0;
}
