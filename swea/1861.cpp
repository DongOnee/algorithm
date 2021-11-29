#include <iostream>
#include <string.h>

using namespace std;

const int MAXN = 1000;
const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int board[MAXN+2][MAXN+2], board_size;
int memorize[MAXN+2][MAXN+2];
int ans1, ans2;

int dfs(int r, int c)
{
    int ret = 0;
    if (memorize[r][c] > 0) return memorize[r][c];

    for (int d = 0; d < 4; ++d) {
        int nr = r + dirs[d][0];
        int nc = c + dirs[d][1];
        if (board[nr][nc] == board[r][c] + 1) ret = dfs(nr, nc);
    }

    return memorize[r][c] = ret + 1;
}

void init()
{
    cin >> board_size;
    memset(board, 0, sizeof(board));
    memset(memorize, 0, sizeof(memorize));
    for (int r = 1; r <= board_size; ++r) for (int c = 1; c <= board_size; ++c) cin >> board[r][c];
    ans1 = 0, ans2 = 0;
}

void run()
{
    for (int r = 1; r <= board_size; ++r) {
        for (int c = 1; c <= board_size; ++c) {
            if (memorize[r][c] == 0) {
                memorize[r][c] = dfs(r, c);
                if (ans2 < memorize[r][c] || (ans2 == memorize[r][c] && ans1 > board[r][c])) {
                    ans2 = memorize[r][c];
                    ans1 = board[r][c];
                } 
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}
