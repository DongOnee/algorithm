#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int dirs[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
const int rat[6] = {1,5,1,7,10,2};
const int MAXN = 499;

#define POINTS(r,c,d) { \
    {{r+dirs[d][0],c+dirs[d][1]}} \
    , {{r+2*dirs[d][0],c+2*dirs[d][1]}} \
    , {{r-dirs[d][0]+dirs[d][1], c-dirs[d][1]+dirs[d][0]}, \
       {r-dirs[d][0]-dirs[d][1], c-dirs[d][1]-dirs[d][0]}} \
    , {{r+dirs[d][1], c+dirs[d][0]}, {r-dirs[d][1],c-dirs[d][0]}} \
    , {{r+dirs[d][0]+dirs[d][1], c+dirs[d][1]+dirs[d][0]}, \
       {r+dirs[d][0]-dirs[d][1], c+dirs[d][1]-dirs[d][0]}} \
    , {{r+2*dirs[d][1], c+2*dirs[d][0]}, {r-2*dirs[d][1],c-2*dirs[d][0]}} \
}

int board[MAXN][MAXN];
int board_size, ans;

void get_sand_value(int val, int ret[]) 
{
    ret[0] = val;
    for (int i = 1; i < 6; ++i) {
        ret[i] = (val * rat[i]) / 100;
        ret[0] -= ret[i] * 2;
    }
    ret[0] += ret[1];
}

void sand_move(int r, int c, int d) 
{
    vector<vector<pii>> points = POINTS(r,c,d);
    int val = board[r][c];
    int sand_values[6];
    get_sand_value(val, sand_values);
    board[r][c] = 0;

    for (int idx = 0; idx < 6; ++idx) {
        int v = sand_values[idx];
        for (auto & p : points[idx]) {
            if (p.first < 0 || p.first >= board_size || p.second < 0 || p.second >= board_size)
                ans += v;
            else 
                board[p.first][p.second] += v;
        }
    }
}

void run() 
{
    int cur[2] = {board_size/2, board_size/2};

    int d = 0;
    for (int i = 1; i < board_size; ++i) {
        for (int j = 0; j < i; ++j) {
            cur[0] += dirs[d][0];
            cur[1] += dirs[d][1];
            sand_move(cur[0], cur[1], d);
        }
        d = (d+1) % 4;

        for (int j = 0; j < i; ++j) {
            cur[0] += dirs[d][0];
            cur[1] += dirs[d][1];
            sand_move(cur[0], cur[1], d);
        }
        d = (d+1) % 4;
    }

    for (int j = 0; j < board_size-1; ++j) {
        cur[0] += dirs[d][0];
        cur[1] += dirs[d][1];
        sand_move(cur[0], cur[1], d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size; 
    for (int row = 0; row < board_size; ++row) for (int col = 0; col < board_size; ++col) cin >> board[row][col];

    run();

    cout << ans << '\n';

    return 0;
}
