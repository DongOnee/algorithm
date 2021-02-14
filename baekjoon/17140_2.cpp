#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 100;

int board[MAXN][MAXN];
int max_row_cnt = 3, max_col_cnt = 3;

void operatorR(int row_count)
{
    int prev_max_col = max_col_cnt;
    max_col_cnt = 0;
    for (int row = 0; row < row_count; ++row) {
        map<int, int> mp;
        vector<pii> vt;
        int col = 0;

        for (; col < prev_max_col; ++col) {
            if (board[row][col] == 0) continue;
            mp[board[row][col]]++;
        }

        for (auto& kv : mp) {
            vt.emplace_back(kv.second, kv.first);
        }

        sort(vt.begin(), vt.end());

        col = 0;
        for (auto& vk : vt) {
            board[row][col++] = vk.second;
            board[row][col++] = vk.first;
        }
        max_col_cnt = max(max_col_cnt, col);

        while (col < prev_max_col) {
            board[row][col++] = 0;
        }
    }
}

void operatorC(int col_count)
{
    int prev_max_row = max_row_cnt;
    max_row_cnt = 0;
    for (int col = 0; col < col_count; ++col) {
        map<int, int> mp;
        vector<pii> vt;
        int row = 0;

        for (; row < prev_max_row; ++row) {
            if (board[row][col] == 0) continue;
            mp[board[row][col]]++;
        }

        for (auto& kv : mp) {
            vt.emplace_back(kv.second, kv.first);
        }

        sort(vt.begin(), vt.end());

        row = 0;
        for (auto& vk : vt) {
            board[row++][col] = vk.second;
            board[row++][col] = vk.first;
        }
        max_row_cnt = max(max_row_cnt, row);

        while (row < prev_max_row) {
            board[row++][col] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, k, t = 0;
    cin >> r >> c >> k;

    int& ans = board[r-1][c-1];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];

    while (t < 101) {
        if (ans == k) break;
        
        if (max_row_cnt < max_col_cnt) operatorC(max_col_cnt);
        else operatorR(max_row_cnt);

        int cntr, cntc;
        ++t;
    }

    cout << (t == 101?-1:t) << '\n';

    return 0;
}
