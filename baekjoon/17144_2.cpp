#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const pii dirs[4] {{0,1},{1,0},{-1,0},{0,-1}};
const int MAXR = 50;

int board[MAXR][MAXR];
int sub[MAXR][MAXR];
int board_row, board_col;
pii cleaner[2];
int cleaner_wind_dir[2][4] = {{0, 2, 3, 1}, {0, 1, 3, 2}};

bool chk(pii cur) { return 0<=cur.first&&cur.first<board_row&&0<=cur.second&&cur.second<board_col; }

void diffusion() 
{
    vector<pair<pii, int>> created;
    
    for (int row = 0; row < board_row; ++row) {
        for (int col = 0; col < board_col; ++col) {
            if (board[row][col] > 4) {
                int shard_value = board[row][col] / 5;
                for (int d = 0; d < 4; ++d) {
                    pii nxt = make_pair(row, col) + dirs[d];
                    if (!chk(nxt)) continue;
                    if (board[nxt.first][nxt.second] == -1 ) continue;
                    created.emplace_back(nxt, shard_value);
                    board[row][col] -= shard_value;
                }
            }
        }
    }

    for (auto& x : created)
        board[x.first.first][x.first.second] += x.second;
}

void cleaner_operation() {
    for (int cleaner_idx = 0 ; cleaner_idx < 2; ++cleaner_idx) {
        pii cur = cleaner[cleaner_idx];
        int wind_dir = 0, temp = 0;

        while (wind_dir < 4) {
            pii nxt = cur + dirs[cleaner_wind_dir[cleaner_idx][wind_dir]];
            if (!chk(nxt)) {
                ++wind_dir;
                continue;
            }

            if (board[nxt.first][nxt.second] == -1) break;
            swap(temp, board[nxt.first][nxt.second]);
            cur = nxt;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> board_row >> board_col >> t;
    for (int row = 0, idx = 0; row < board_row; ++row) {
        for (int col = 0; col < board_col; ++col) {
            cin >> board[row][col];
            if (board[row][col] == -1) cleaner[idx++] = {row, col};
        }
    }

    while (t--) {
        diffusion();
        cleaner_operation();
    }

    int ans = 2;
    for (int row = 0, idx = 0; row < board_row; ++row)
        for (int col = 0; col < board_col; ++col)
            ans += board[row][col];

    cout << ans << '\n';

    return 0;
}
