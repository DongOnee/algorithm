#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN  = 64;
const pii dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int board[MAXN+2][MAXN+2];
int board_size, ans, ans2;
bool visited[MAXN+2][MAXN+2];
pii melting_list[4096];

inline void _turn(int r, int c, int d) {
    int tmp;
    for (int i = 0; i < d-1; ++i) {
        tmp = board[r][c+i];
        board[r][c+i] = board[r+d-1-i][c];
        board[r+d-1-i][c] = board[r+d-1][c+d-1-i];
        board[r+d-1][c+d-1-i] = board[r+i][c+d-1];
        board[r+i][c+d-1] = tmp;
    }
}

inline void turn(int r, int c, int dist)
{
    for (int i = 0; i < dist/2; ++i) {
        _turn(r+i, c+i, dist - 2*i);
    }
}

void run(int dist)
{
    for (int r = 1; r < board_size && 1 < dist; r += dist) {
        for (int c = 1; c < board_size; c += dist) {
            turn(r,c,dist);
        }
    }
}

void melt()
{
    int cnt = 0;
    
    for (int r = 1; r <= board_size; ++r) {
        for (int c = 1; c <= board_size; ++c) {
            if (board[r][c] == 0) continue;

            int zero_count = 0;
            for (int d = 0; d < 4; ++d) {
                pii nxt = make_pair(r, c) + dirs[d];
                if (board[nxt.first][nxt.second] == 0) ++zero_count;
            }

            if (zero_count > 1) melting_list[cnt++] = {r, c};
        }
    }

    for (int idx = 0; idx < cnt; ++idx) {
        int r = melting_list[idx].first;
        int c = melting_list[idx].second;

        --board[r][c];
    }
}

void sol()
{
    queue<pii> qu;

    for (int r = 1; r <= board_size; ++r) {
        for (int c = 1; c <= board_size; ++c) {
            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (board[r][c] == 0) continue;
            ans += board[r][c];
            qu.push({r, c});
            int cnt = 1;

            while (!qu.empty()) {
                pii f = qu.front(); qu.pop();

                for (int d = 0; d < 4; ++d) {
                    pii nxt = f + dirs[d];

                    if (visited[nxt.first][nxt.second]) continue;

                    visited[nxt.first][nxt.second] = true;
                    if (board[nxt.first][nxt.second] > 0) {
                        qu.push(nxt);
                        ++cnt;
                        ans += board[nxt.first][nxt.second];
                    }
                }
            }

            ans2 = max(ans2, cnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> board_size >> k;
    board_size = (1 << board_size);

    for (int row = 1; row <= board_size; ++row) for (int col = 1; col <= board_size; ++col) cin >> board[row][col];

    while (k--) {
        int kk; cin >> kk;
        run(1 << kk);
        melt();
    }

    sol();

    cout << ans << '\n' << ans2 << '\n';

    return 0;
}
