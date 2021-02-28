#include <iostream>

using namespace std;

typedef struct board_st board;

typedef bool (*chk_valid_func)(int, int);

struct board_st
{
    bool _board[8][4];
    int ans;
    void remove_line(int start, int cnt)
    {
        for (int row = start; row < 6; ++row) {
            _board[row][0] = _board[row+cnt][0];
            _board[row][1] = _board[row+cnt][1];
            _board[row][2] = _board[row+cnt][2];
            _board[row][3] = _board[row+cnt][3];
        }
    }
    void line_remove()
    {
        int end_row = 0, cnt = 0;
        for (int row = 0; row < 4; ++row) {
            if (_board[row][0] && _board[row][1] && _board[row][2] && _board[row][3]) {
                ++cnt;
                end_row = row;
            }
        }
    
        if (cnt > 0) {
            ans += cnt;
            remove_line(end_row - cnt + 1, cnt);
        }
    
        cnt = 0;
        for (int row = 4; row < 6; ++row)
            if (_board[row][0] || _board[row][1] || _board[row][2] || _board[row][3]) ++cnt;
        if (cnt > 0) remove_line(0, cnt);
    }
    void push_block(int type, int st)
    {
        int row, col;
    
        row = 4, col = st;
        while (row > 0) {
            if (type == 1) { if (_board[row-1][col]) break; }
            else if (type == 2) { if (_board[row-1][col] || _board[row-1][col+1]) break; }
            else if (type == 3) { if (_board[row-1][col] || _board[row][col]) break; }
            --row;
        }

        _board[row][col] = true;
        if (type == 2) _board[row][col+1] = true;
        else if (type == 3) _board[row+1][col] = true;
    }
};

board green, blue;

void run()
{
    int cnt; cin >> cnt;

    while (cnt--) {
        int t, r, c; cin >> t >> r >> c;
        green.push_block(t, c);
        blue.push_block((t==1?1:5-t), r);

        green.line_remove();
        blue.line_remove();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run();

    int ans2= 0;
    for (int row = 0; row < 4; ++row) for (int col = 0; col < 4; ++col) {
        if (green._board[row][col]) ++ans2;
        if (blue._board[row][col]) ++ans2;
    }

    cout << blue.ans + green.ans << '\n' << ans2 << '\n';

    return 0;
}
