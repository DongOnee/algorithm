#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int dirs[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
const int rat[10] = {0,5,1,1,7,7,10,10,2,2};
const int MAXN = 499;

#define POINTS(r,c,d) { \
    {r+dirs[d][0],c+dirs[d][1]}, \
    {r+2*dirs[d][0],c+2*dirs[d][1]}, \
    {r-dirs[d][0]+dirs[d][1], c-dirs[d][1]+dirs[d][0]}, \
    {r-dirs[d][0]-dirs[d][1], c-dirs[d][1]-dirs[d][0]}, \
    {r+dirs[d][1], c+dirs[d][0]}, \
    {r-dirs[d][1], c-dirs[d][0]}, \
    {r+dirs[d][0]+dirs[d][1], c+dirs[d][1]+dirs[d][0]}, \
    {r+dirs[d][0]-dirs[d][1], c+dirs[d][1]-dirs[d][0]}, \
    {r+2*dirs[d][1], c+2*dirs[d][0]}, \
    {r-2*dirs[d][1], c-2*dirs[d][0]} \
}

int board[MAXN+4][MAXN+4];
int board_size, ans;

void sand_move(int r, int c, int d) 
{
    pii points[10] = POINTS(r,c,d);
    int val = board[r][c];
    int sum = val;

    board[r][c] = 0;

    for (int idx = 1; idx < 10; ++idx) {
        int v = val * rat[idx] / 100;
        pii p = points[idx];
        board[p.first][p.second] += v;
        sum -= v;
    }
    board[points[0].first][points[0].second] += sum;
}

void run() 
{
    int r = board_size / 2 + 2;
    int c = board_size / 2 + 2;
    int d = 0;

    for (int i = 2, dist = 1; i < 2 * board_size; ++i, dist = i / 2) {
        while (dist--) {
            r += dirs[d][0];
            c += dirs[d][1];

            sand_move(r, c, d);
        }

        d = (d+1) % 4;
    }

    int dist = board_size -1;
    while (dist--) {
        r += dirs[d][0];
        c += dirs[d][1];

        sand_move(r, c, d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size; 
    for (int row = 2; row < board_size+2; ++row) for (int col = 2; col < board_size+2; ++col) cin >> board[row][col];

    run();

    for (int i = 0; i < board_size + 2; ++i) {
        ans += board[0][i];
        ans += board[1][i];
        ans += board[i][board_size + 2];
        ans += board[i][board_size + 3];

        ans += board[board_size + 2][i + 2];
        ans += board[board_size + 3][i + 2];
        ans += board[i+2][0];
        ans += board[i+2][1];
    }
    cout << ans << '\n';

    return 0;
}
