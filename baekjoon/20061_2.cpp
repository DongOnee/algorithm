#include <iostream>

using namespace std;

const int MAXN = 8;

bool board_green[MAXN][4];
bool board_blue[4][MAXN];

int ans;

typedef bool (*chk_valid_func)(int, int, bool);

bool check_valid_type1(int row, int col, bool is_green)
{
    return is_green?!board_green[row][col]:!board_blue[row][col];
}
bool check_valid_type2(int row, int col, bool is_green)
{
    return check_valid_type1(row, col, is_green) && check_valid_type1(row, col+1, is_green);
}
bool check_valid_type3(int row, int col, bool is_green)
{
    return check_valid_type1(row, col, is_green) && check_valid_type1(row+1, col, is_green);
}

void print_blue()
{
    for (int row = 0; row < 4; ++row) {
        for (int col = 5; 0 <= col; --col) cout << board_blue[row][col] << ' ';
        cout << '\n';
    }
        cout << '\n';
}

void print_green()
{
    for (int row = 5; 0<= row; --row) {
        for (int col = 0; col < 4; ++col) cout << board_green[row][col] << ' ';
        cout << '\n';
    }
        cout << '\n';
}

chk_valid_func chk_valid[4] = {
    nullptr,
    check_valid_type1,
    check_valid_type2,
    check_valid_type3
};

void remove_line(int start, int cnt, bool is_green)
{
    if (is_green) {
        for (int row = start; row < 6; ++row) {
            board_green[row][0] = board_green[row+cnt][0];
            board_green[row][1] = board_green[row+cnt][1];
            board_green[row][2] = board_green[row+cnt][2];
            board_green[row][3] = board_green[row+cnt][3];
        }
    }
    else {
        for (int col = start; col < 6; ++col) {
            board_blue[0][col] = board_blue[0][col+cnt];
            board_blue[1][col] = board_blue[1][col+cnt];
            board_blue[2][col] = board_blue[2][col+cnt];
            board_blue[3][col] = board_blue[3][col+cnt];
        }
    }
}

void line_remove(bool is_green)
{
    if (is_green) {
        int end_row = 0, cnt = 0;
        for (int row = 0; row < 4; ++row) {
            if (board_green[row][0] && board_green[row][1] && board_green[row][2] && board_green[row][3]) {
                ++cnt;
                end_row = row;
            }
        }

        if (cnt > 0) {
            ans += cnt;
            remove_line(end_row - cnt + 1, cnt, is_green);
        }

        cnt = 0;
        for (int row = 4; row < 6; ++row)
            if (board_green[row][0] || board_green[row][1] || board_green[row][2] || board_green[row][3]) ++cnt;
        if (cnt > 0) remove_line(0, cnt, is_green);
    }
    else {
        int end_col = 0, cnt = 0;
        for (int col = 0; col < 4; ++col) {
            if (board_blue[0][col] && board_blue[1][col] && board_blue[2][col] && board_blue[3][col]) {
                ++cnt;
                end_col = col;
            }
        }

        if (cnt > 0) {
            ans += cnt;
            remove_line(end_col - cnt + 1, cnt, is_green);
        }
        
        cnt = 0;
        for (int col = 4; col < 6; ++col)
            if (board_blue[0][col] || board_blue[1][col] || board_blue[2][col] || board_blue[3][col]) ++cnt;
        if (cnt > 0) remove_line(0, cnt, is_green);
    }
}

void push_block(int type, int st, bool is_green)
{
    int row, col;

    if (is_green) {
        row = 4, col = st;
        while (row > 0 && chk_valid[type](row-1, col, is_green)) {
            --row;
        }
        board_green[row][col] = true;
        if (type == 2) board_green[row][col+1] = true;
        else if (type == 3) board_green[row+1][col] = true;
    }
    else {
        row = st, col = 4;
        while (col > 0 && chk_valid[type](row, col-1, is_green)) {
            --col;
        }
        board_blue[row][col] = true;
        if (type == 2) board_blue[row][col+1] = true;
        else if (type == 3) board_blue[row+1][col] = true;
    }
}

void run()
{
    int cnt; cin >> cnt;

    while (cnt--) {
        int t, r, c; cin >> t >> r >> c;
        push_block(t, c, true);
        push_block(t, r, false);

        line_remove(true);
        line_remove(false);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    run();

    int ans2= 0;
    for (int row = 0; row < 4; ++row) for (int col = 0; col < 4; ++col) {
        if (board_green[row][col]) ++ans2;
        if (board_blue[row][col]) ++ans2;
    }

    // print_green();
    // print_blue();
    cout << ans << '\n' << ans2 << '\n';
    
    return 0;
}
