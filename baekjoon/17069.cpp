#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 32;
const int dirs[3][2] = { {0, 1}, {1, 1}, {1, 0} };
const vector<pii> check_dirs[3] = { 
    {{0, 1}}, 
    {{0, 1}, {1, 0}, {1, 1}},
    {{1, 0}}
};

int board_size;
int board[MAXN][MAXN];
int ans;

void dfs(int r, int c, int d)
{
    if (r == board_size - 1 && c == board_size - 1) {
        ++ans;
        return;
    }

    for (int i = 0; i < 3; ++i) {
        int nd = d - 1 + i;

        if (nd < 0 || 2 < nd)
            continue;

        int nr = r + dirs[nd][0];
        int nc = c + dirs[nd][1];

        if (board_size <= nr || board_size <= nc)
            continue;

        bool chk_flag = false;

        for (auto& s : check_dirs[nd]) {
            if (board[r + s.first][c + s.second] != 0)
                chk_flag = true;
        }

        if (chk_flag) 
            continue;

        for (auto& s : check_dirs[nd]) {
            board[r + s.first][c + s.second] = 2;
        }

        dfs(nr, nc, nd);

        for (auto& s : check_dirs[nd]) {
            board[r + s.first][c + s.second] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size;
    for (int i = 0; i < board_size; ++i)
        for (int j = 0; j < board_size; ++j)
            cin >> board[i][j];

    board[0][0] = board[0][1] = 2;
    dfs(0, 1, 0);

    cout << ans << '\n';

    return 0;
}
