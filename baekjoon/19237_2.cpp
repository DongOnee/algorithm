#include <iostream>

using namespace std;

const int MAXN = 20;
const int MAXM = 400;
const int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int board[MAXN][MAXN];
int smell[MAXN][MAXN][2];
int board_size, k, ans = -1;

typedef
struct
{
    int r, c;
    int d;
    int priority_dir[4][4];
}shark_info;

shark_info sharks[MAXM+1];
int shark_nxt_dir[MAXM+1];
int shark_count;

void smell_func()
{
    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        int row = sharks[shark_index].r;
        int col = sharks[shark_index].c;

        if (row == -1) continue;
        
        smell[row][col][0] = shark_index;
        smell[row][col][1] = k;
    }
}

void smell_delete()
{
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            if (smell[row][col][0] > 0) {
                if (0 == --smell[row][col][1]) {
                    smell[row][col][0] = 0;
                }
            }
        }
    }
}

void sharks_move() 
{
    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        int row = sharks[shark_index].r;
        int col = sharks[shark_index].c;
        int dir = sharks[shark_index].d;

        if (row == -1) continue;
        int nxt_dir = -1, nxt_smell_dir = -1;
        for (int i = 0; i < 4; ++i) {
            int nd = sharks[shark_index].priority_dir[dir][i];

            int nr = row + dirs[nd][0];
            int nc = col + dirs[nd][1];

            if (nr < 0 || nc < 0 || board_size <= nr || board_size <= nc) continue;
            if (smell[nr][nc][0] == 0) {
                nxt_dir = nd;
                break;
            }
            if (smell[nr][nc][0] == shark_index && nxt_smell_dir == -1) {
                nxt_smell_dir = nd;
            } 
        }

        if (nxt_dir != -1) {
            shark_nxt_dir[shark_index] = nxt_dir;
        }
        else {
            shark_nxt_dir[shark_index] = nxt_smell_dir;
        }
    }
    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        int row = sharks[shark_index].r;
        int col = sharks[shark_index].c;
        if (row == -1) continue;
        board[row][col] = 0;
    }
    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        int row = sharks[shark_index].r;
        int col = sharks[shark_index].c;
        if (row == -1) continue;
        int nr = row + dirs[shark_nxt_dir[shark_index]][0];
        int nc = col + dirs[shark_nxt_dir[shark_index]][1];
        int nd = shark_nxt_dir[shark_index];

        sharks[shark_index].r = nr;
        sharks[shark_index].c = nc;
        sharks[shark_index].d = nd;
        
        if (board[nr][nc] > shark_index || board[nr][nc] == 0) {
            sharks[board[nr][nc]].r = -1;
            board[nr][nc] = shark_index;
        }
        else // if (board[nr][nc] > 0)
            sharks[shark_index].r = -1;
    }
}

void run()
{
    smell_func();

    int t = 0, remain;
    while (t < 1000) {

        sharks_move();
        ++t;
        smell_delete();
        smell_func();

        remain = 0;
        for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
            if (sharks[shark_index].r > -1) ++remain;
        }
        if (remain == 1) break;
    }

    if (remain == 1) ans = t;
    else ans = -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size >> shark_count >> k;

    for (int row = 0, shark_index; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cin >> board[row][col];
            if (board[row][col] > 0) {
                sharks[board[row][col]].r = row;
                sharks[board[row][col]].c = col;
            }
        }
    }

    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        cin >> sharks[shark_index].d;
        --sharks[shark_index].d;
    }

    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        for (int d = 0; d < 4; ++d) {
            cin >> sharks[shark_index].priority_dir[d][0] 
                >> sharks[shark_index].priority_dir[d][1] 
                >> sharks[shark_index].priority_dir[d][2]
                >> sharks[shark_index].priority_dir[d][3];
            for (int i = 0; i < 4; ++i) --sharks[shark_index].priority_dir[d][i];
        }
    }

    run();

    cout << ans << '\n';

    return 0;
}
