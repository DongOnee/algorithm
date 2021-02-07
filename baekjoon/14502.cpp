#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first, a.second+b.second); }

const int MAXN = 8;
const pii dirs[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int hi, wi, ans;
int board[MAXN+2][MAXN+2];
int board_init[MAXN+2][MAXN+2];
bool visited[MAXN+2][MAXN+2];
pii wall[3];

void bfs() 
{
    int safe_zone_count = -3;
    queue<pii> qu;

    for (int row = 0; row <= hi + 1; ++row)
        for (int col = 0; col <= wi + 1; ++col) {
            board[row][col] = board_init[row][col];
            visited[row][col] = false;

            if (board[row][col] == 2) {
                qu.push({row, col});
                visited[row][col] = true;
            }
            if (board[row][col] == 0)
                ++safe_zone_count;
        }

    for (int i = 0; i < 3; ++i)
        board[wall[i].first][wall[i].second] = 1;

    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for (int d = 0; d < 4; ++d) {
            pii nxt = f + dirs[d];

            if (board[nxt.first][nxt.second] == 0 && !visited[nxt.first][nxt.second]) {
                visited[nxt.first][nxt.second] = true;
                qu.push(nxt);
                --safe_zone_count;
            }

            if (safe_zone_count <= ans) return;
        }
    }

    ans = max(ans, safe_zone_count);
}

void dfs(int r, int c, int cnt) 
{
    if (cnt == 3) bfs();
    else {
        for (int row = r, col = c; row <= hi; ++row, col = 1) {
            for (; col <= wi; ++col) {
                if (board_init[row][col] == 0) {
                    wall[cnt] = {row, col};
                    dfs(row, col+1, cnt+1);
                }
            }
        }

    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> hi >> wi;
    for (int row = 1; row <= hi; ++row)
        for (int col = 1; col <= wi; ++col)
            cin >> board_init[row][col];

    for (int row = 0; row <= hi + 1; ++row) {
        board_init[row][0] = board_init[row][wi+1] = 1;
    }

    for (int col = 0; col <= wi + 1; ++col) {
        board_init[0][col] = board_init[hi+1][col] = 1;
    }

    dfs(1, 1, 0);

    cout << ans << '\n';

    return 0;
}
