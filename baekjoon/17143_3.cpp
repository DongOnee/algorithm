#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

typedef struct _shark_info
{
    int s;
    int d;
    int z;
    _shark_info(int _s, int _d, int _z) : s(_s), d(_d), z(_z) {};
    _shark_info() : s(0), d(0), z(0) {};
}shark_info;

const int MAXR = 100;
const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const int conv[5] = { 0, 2, 0, 1, 3};

shark_info board[MAXR][MAXR];
int board_row, board_col;
int ans;

void print_board()
{
    for (int r = 0; r < board_row; ++r) {
        for (int c = 0; c < board_col; ++c) {
            cout << board[r][c].z << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void shark_fishing(int col)
{
    for (int row = 0; row < board_row; ++row) {
        auto & shark = board[row][col];
        if (shark.z > 0) {
            ans += shark.z;

            shark = {0, 0, 0};
            return;
        }
    }
}

void sharks_move()
{
    vector<pair<pii, shark_info>> sharks;

    for (int r = 0; r < board_row; ++r) {
        for (int c = 0; c < board_col; ++c) {
            if (board[r][c].z > 0) {
                sharks.push_back({{r, c}, board[r][c]});
                board[r][c] = {0, 0, 0};
            }
        }
    }

    for (auto& shark : sharks) {
        int r = shark.first.first;
        int c = shark.first.second;
        shark_info shark_i = shark.second;

        r += dirs[shark_i.d][0] * shark_i.s;
        c += dirs[shark_i.d][1] * shark_i.s;
        
        if (r < 0) {
            r = -r;
            shark_i.d = (shark_i.d + 2) % 4;
        }
        if (c < 0) {
            c = -c;
            shark_i.d = (shark_i.d + 2) % 4;
        }

        r %= (2 * (board_row - 1));
        c %= (2 * (board_col - 1));

        if (board_row <= r) {
            r = 2 * (board_row - 1) - r;
            shark_i.d = (shark_i.d + 2) % 4;
        }
        if (board_col <= c) {
            c = 2 * (board_col - 1) - c;
            shark_i.d = (shark_i.d + 2) % 4;
        }

        if (board[r][c].z < shark_i.z) {
            board[r][c] = shark_i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int shark_count;
    cin >> board_row >> board_col >> shark_count;

    for (int i = 0; i < shark_count; ++i) {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        board[x-1][y-1] = {s, conv[d], z};
    }

    for (int c = 0; c < board_col; ++c) {
        shark_fishing(c);
        sharks_move();
        print_board();
    }

    cout << ans << '\n';

    return 0;
}
