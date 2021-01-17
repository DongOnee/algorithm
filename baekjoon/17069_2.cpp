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
int board[MAXN+1][MAXN+1];
long long dp[MAXN+1][MAXN+1][3];

void dp_func(int row, int col, int di) 
{
#ifndef ONLINE_JUDGE
    cout << "row : " << row << " col : " << col << " di : " << di << "\n";
#endif
    for (auto& chk_point : check_dirs[di]) {
        if (row - chk_point.first < 0 || col - chk_point.second < 0) return;
        if (board[row - chk_point.first][col - chk_point.second] > 0) return;
    }

    for (int d = di - 1; d < di + 2; ++d) {
        if (d < 0 || 2 < d) continue;
        if (row + dirs[d][0] < board_size && col + dirs[d][1] < board_size) 
            dp[row][col][di] += dp[row + dirs[d][0]][col + dirs[d][1]][d];
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

    if (board[board_size-1][board_size-1] == 1) {
        cout << 0 << '\n';
        return 0;
    }

    if (board[board_size - 1][board_size - 2] == 0)
        dp[board_size-1][board_size-1][0] = 1;
    if (board[board_size - 2][board_size - 1] == 0)
        dp[board_size-1][board_size-1][2] = 1;
    if (board[board_size - 1][board_size - 2] == 0 && board[board_size - 2][board_size - 1] == 0 && board[board_size - 2][board_size - 2] == 0)
        dp[board_size-1][board_size-1][1] = 1;


    for (int row = board_size - 1, col = board_size - 2; 0 <= row; --row, col = board_size -1) {
        for (; 0 <= col; --col) {
            if (board[row][col] > 0) continue;
            for (int d = 0; d < 3; ++d)
                dp_func(row, col, d);
        }
    }

    cout << dp[0][1][0] << '\n';

    return 0;
}
