#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct _shark_info
{
    int r, c;
    int s;
    int d;
    int z;
    _shark_info(int _r, int _c, int _s, int _d, int _z) : r(_r), c(_c), s(_s), d(_d), z(_z) {};
}shark_info;

const int MAXR = 100;
const int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
const int conv[5] = { 0, 2, 0, 1, 3};

vector<shark_info> sharks;
int board[MAXR][MAXR];
int board_row, board_col;
int ans;

void shark_to_board()
{
    for (int r = 0; r < board_row; ++r)
        for (int c = 0; c < board_col; ++c)
            board[r][c] = -1;

    int idx = 0;
    for (auto& shark : sharks) {
        board[shark.r][shark.c] = idx++;
    }
}

void shark_fishing(int col)
{
    for (int row = 0; row < board_row; ++row) {
        int idx = board[row][col];
        if (idx != -1) {
            ans += sharks[idx].z;
            sharks[idx].r = -1;
            sharks[idx].c = -1;
            sharks[idx].z = 0;

            return;
        }
    }
}

void sharks_move()
{
    for (int row = 0; row < board_row; ++row)
        for (int col = 0; col < board_col; ++col)
            board[row][col] = -1;

    for (int idx = 0; idx < sharks.size(); ++idx) {
        auto& shark = sharks[idx];
        if (shark.r == -1) continue;
        int move_count = shark.s;
        int& move_d = shark.d;

        move_count %= ( (move_d % 2 == 0? board_row : board_col) -1) * 2;
        
        while (move_count > 0) {
            int nr = shark.r + dirs[move_d][0];
            int nc = shark.c + dirs[move_d][1];
            if (nr < 0 || board_row <= nr || nc < 0 || board_col <= nc) {
                move_d = (move_d + 2) % 4;
                continue;
            }

            --move_count;
            shark.r = nr, shark.c = nc;
        }

        if (board[shark.r][shark.c] == -1)
            board[shark.r][shark.c] = idx;
        else if (sharks[board[shark.r][shark.c]].z < shark.z)
            board[shark.r][shark.c] = idx;
    }

    vector<shark_info> cp_sharks;
    for (int row = 0; row < board_row; ++row)
        for (int col = 0; col < board_col; ++col)
            if (board[row][col] > -1)
                cp_sharks.emplace_back(sharks[board[row][col]]);

    sharks.clear();
    for (auto& shark : cp_sharks)
        sharks.emplace_back(shark);
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
        sharks.emplace_back(x-1, y-1, s, conv[d], z);
    }

    for (int c = 0; c < board_col; ++c) {
        shark_to_board();
        shark_fishing(c);
        sharks_move();
    }

    cout << ans << '\n';

    return 0;
}
