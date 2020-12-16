#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAXWIDTH = 64;
const int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int board_width, step_count;
int board[MAXWIDTH][MAXWIDTH], board_cp[MAXWIDTH][MAXWIDTH];
bool visited[MAXWIDTH][MAXWIDTH];

void print_board() {
    for (int r = 0; r < board_width; ++r) {
        for (int c = 0; c < board_width; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }
}

bool chk(int r, int c) { return 0 <= r && r < board_width && 0 <= c && c < board_width; }

void turn(int r, int c, int w) {
    for (int a = 0; a < w / 2; ++a) {
        int wi = w - 2 * a;
        for (int i = 0; i < wi - 1; ++i) {
            int temp = board[r + a][c + a + i];
            board[r + a][c + a + i] = board[r + a + wi - 1 - i][c + a];
            board[r + a + wi - 1 - i][c + a] = board[r + a + wi - 1][c + a + wi - 1 - i];
            board[r + a + wi - 1][c + a + wi - 1 - i] = board[r + a + i][c + a + wi - 1];
            board[r + a + i][c + a + wi - 1] = temp;
        }
    }
}

int bfs(int r, int c) {
    int ret = 1;
    visited[r][c] = true;
    queue<pii> qu;
    qu.push({r, c});
    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = f.first + dirs[d][0];
            int nc = f.second + dirs[d][1];
            if (!chk(nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] == 0) continue;
            ++ret;
            qu.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return ret;
}

int dfs(int r, int c) {
    int ret = 1;
    visited[r][c] = true;
    for (int d = 0; d < 4; ++d) {
        int nr = r + dirs[d][0];
        int nc = c + dirs[d][1];
        if (!chk(nr, nc)) continue;
        if (visited[nr][nc]) continue;
        if (board[nr][nc] == 0) continue;
        ret += dfs(nr, nc);
    }

    return ret;
}

int dfs() {
    int ret = 0;
    for (int r = 0; r < board_width; ++r)
        for (int c = 0; c < board_width; ++c)
            if (!visited[r][c] && board[r][c] > 0)
                ret = max(ret, bfs(r,c));
    return ret;
}

void check() {
    for (int i = 0; i < board_width; ++i) {
        for (int j = 0; j < board_width; ++j) {
            int nearCount = 0;
            for (int d = 0; d < 4; ++d) {
                if (!chk(i + dirs[d][0], j + dirs[d][1])) continue;
                if (board[i + dirs[d][0]][j + dirs[d][1]] > 0) 
                    ++nearCount;
            }
            board_cp[i][j] = board[i][j] - (nearCount < 3);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a; cin >> a >> step_count;
    board_width = pow(2, a);

    for (int i = 0; i < board_width; ++i)
        for (int j = 0; j < board_width; ++j)
            cin >> board[i][j];

    while (step_count--) {
        int input_l; cin >> input_l;
        int cell_width = pow(2, input_l);

        if (input_l == 0);
        else
            for (int row = 0; row < board_width; row += cell_width)
                for (int col = 0; col < board_width; col += cell_width)
                    turn(row, col, cell_width);

        check();

        for (int row = 0; row < board_width; ++row)
            for (int col = 0; col < board_width; ++col)
                board[row][col] = (board_cp[row][col] < 0 ? 0 : board_cp[row][col]);
    }

    int ans = 0;
    
    for (int row = 0; row < board_width; ++row)
        for (int col = 0; col < board_width; ++col)
            ans += board[row][col];

    cout << ans << '\n' << dfs() << '\n';

    return 0;
}
