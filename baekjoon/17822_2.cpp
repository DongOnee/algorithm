#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first, a.second+b.second); }

const int MAXN = 50;
const pii dirs[4]  = {{0,1},{1,0},{0,-1},{-1,0}};

int board[MAXN+2][MAXN];
int board_size, m;
bool visited[MAXN+2][MAXN];

void turn(int row, int cnt) {
    vector<int> tmp;
    for (int i = 0; i < m; ++i) tmp.emplace_back(board[row][i]);
    for (int i = 0; i < m; ++i) board[row][(i + cnt) % m] = tmp[i];
}

bool bfs(int r, int c) {
    bool ret = false;
    for (int i = 0; i <= board_size+1; ++i) for (int j = 0; j < m; ++j) visited[i][j] = false;

    queue<pii> qu;
    qu.push({r, c});
    visited[r][c] = true;

    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for (int d = 0; d < 4; ++d) {
            pii nxt = f + dirs[d];
            nxt.second = (nxt.second + m) % m;

            if (visited[nxt.first][nxt.second]) continue;
            visited[nxt.first][nxt.second] = true;

            if (board[r][c] == board[nxt.first][nxt.second]) {
                qu.push(nxt);
                board[nxt.first][nxt.second] = 0;
                ret = true;
            }
        }
    }

    if (ret) {
        board[r][c] = 0;
    }
    return ret;
}

void run(int x, int d, int k) {
    int xx = x;
    if (d == 1) k = m - k;
    while (xx <= board_size) {
        turn(xx, k);
        xx += x;
    }

    bool is_change = false;
    for (int i = 1; i <= board_size; ++i) for (int col = 0; col < m; ++col) if (board[i][col] != 0) is_change |= bfs(i, col);

    if (!is_change) {
        int sum = 0;
        int cnt = 0;

        for (int i = 1; i <= board_size; ++i) for (int col = 0; col < m; ++col) if (board[i][col] != 0) {
            ++cnt;
            sum += board[i][col];
        }

        for (int i = 1; i <= board_size; ++i) for (int col = 0; col < m; ++col) {
            if (board[i][col] == 0);
            else if (board[i][col]*cnt < sum) ++board[i][col];
            else if (board[i][col]*cnt > sum) --board[i][col];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cmd_count;
    cin >> board_size >> m >> cmd_count;

    for (int i = 1; i <= board_size; ++i) for (int col = 0; col < m; ++col) cin >> board[i][col];

    while (cmd_count--) {
        int x, d, k;
        cin >> x >> d >> k;
        run(x,d,k);
    }

    int ans = 0;
    for (int i = 1; i <= board_size; ++i) for (int col = 0; col < m; ++col) ans += board[i][col];
    cout << ans << '\n';

    return 0;
}
