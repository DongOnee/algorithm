#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10;
const int MAXM = 6;

int board[MAXN][MAXN];
int dp[MAXN][MAXN];
int memorize[MAXM];
int board_size, m, cc, ans;

inline int _calc_profit(int r, int c, int rem, int wid)
{
    if (wid == 0) return 0;
    if (rem < board[r][c+wid-1]) return _calc_profit(r,c,rem,wid-1);
    return max(board[r][c+wid-1] * board[r][c+wid-1] + _calc_profit(r,c,rem-board[r][c+wid-1],wid-1), _calc_profit(r,c,rem,wid-1));
}

int calc_profit(int r, int c)
{
    return _calc_profit(r,c,cc,m);
}

void init()
{
    cin >> board_size >> m >> cc;
    for (int r = 0; r < board_size; ++r) for (int c = 0; c < board_size; ++c) cin >> board[r][c];
    for (int i = 0; i < MAXM; ++i) memorize[i] = 0;
    
    ans = 0;
}

int main(int argc, char** argv)
{
	int T; cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case) {
        init();
        int idx = 0;
        for (int r = 0; r < board_size; ++r) {
            for (int c = 0; c <= board_size-m; ++c) {
                int get_honey = calc_profit(r,c);

                memorize[idx] = max(get_honey, memorize[(idx - 1 + MAXM) % MAXM]);
                ans = max(ans, get_honey + memorize[(idx - (c<m?c+1:m) + MAXM) % MAXM]);

                idx = ( idx + 1 ) % MAXM;
            }
        }

        cout << '#' << test_case << ' ' << ans << endl;
	}
	return 0;
}
