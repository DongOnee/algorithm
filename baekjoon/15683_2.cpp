#include <iostream>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN = 8;
const pii dirs[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int WALL = 6;
const int EMPTY = 0;
const int INF = 987654321;

const vector<vector<int>> cctv_info[6] =
{
    {{}},
    { {0}, {1}, {2}, {3} },
    { {0, 2}, {1, 3} },
    { {0, 1}, {1, 2}, {2, 3}, {3, 0} },
    { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} },
    { {0, 1, 2, 3} }
};

int board[MAXN+2][MAXN+2];
int hi, wi, ans = INF;

vector<pii> cctvs;
int cctv_count;

void dfs(int idx) 
{
    if (idx == cctv_count) {
        int empty_count = 0;
        for (int row = 1; row <= hi; ++row)
            for (int col = 1; col <= wi; ++col)
                if (board[row][col] == EMPTY)
                    ++empty_count;

        ans = min(ans, empty_count);

        return;
    }

    // int board_cp[hi+2][wi+2];
    int board_cp[MAXN+2][MAXN+2];
    for (int row = 0; row <= hi + 1; ++row)
        for (int col = 0; col <= wi + 1; ++col)
            board_cp[row][col] = board[row][col];

    pii cur_cctv = cctvs[idx];
    int cctv_type = board[cur_cctv.first][cur_cctv.second];
    for (auto& cctv_case : cctv_info[cctv_type]) {
        for (int d : cctv_case) {
            pii search_cur = cur_cctv;
            for (;;) {
                pii nxt = search_cur + dirs[d];
                if (board[nxt.first][nxt.second] == WALL) break;
                if (board[nxt.first][nxt.second] == EMPTY) board[nxt.first][nxt.second] = -1;
                search_cur = nxt;
            }
        }
        dfs(idx+1);
        for (int i = 0; i <= hi + 1; ++i)
            for (int j = 0; j <= wi + 1; ++j)
                board[i][j] = board_cp[i][j];
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // memset(board, WALL, sizeof(board));

    cin >> hi >> wi;
    for (int row = 0; row < hi + 2; ++row) {
        board[row][0] = WALL;
        board[row][wi+1] = WALL;
    }
    for (int col = 0; col < wi + 2; ++col) {
        board[0][col] = WALL;
        board[hi+1][col] = WALL;
    }

    for (int i = 1; i <= hi; ++i) {
        for (int j = 1; j <= wi; ++j) {
            cin >> board[i][j];
            if (EMPTY < board[i][j] && board[i][j] < WALL) {
                cctvs.emplace_back(i, j);
                ++cctv_count;
            }
        }
    }

    dfs(0);

    cout << ans << "\n";

    return 0;
}
