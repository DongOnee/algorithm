#include <iostream>
#include <iomanip>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 499;
const pii dirs[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int board_width, sand_board[MAXN + 4][MAXN + 4];
int r, c;

void run_tornado(int dir) {
    int nextr = r + dirs[dir].first;
    int nextc = c + dirs[dir].second;
    int all = sand_board[nextr][nextc];
    int per1 = sand_board[nextr][nextc] / 100;
    int per2 = sand_board[nextr][nextc] / 50;
    int per5 = sand_board[nextr][nextc] / 20;
    int per7 = sand_board[nextr][nextc] * 7 / 100;
    int per10 = sand_board[nextr][nextc] / 10;

    // per 1
    sand_board[r + dirs[dir].second][c + dirs[dir].first] += per1;
    sand_board[r - dirs[dir].second][c - dirs[dir].first] += per1;

    // per 7
    sand_board[nextr + dirs[dir].second][nextc + dirs[dir].first] += per7;
    sand_board[nextr - dirs[dir].second][nextc - dirs[dir].first] += per7;

    // per 2
    sand_board[nextr + 2 * dirs[dir].second][nextc + 2 * dirs[dir].first] += per2;
    sand_board[nextr - 2 * dirs[dir].second][nextc - 2 * dirs[dir].first] += per2;

    // per 10
    sand_board[nextr + dirs[dir].first + dirs[dir].second][nextc + dirs[dir].second + dirs[dir].first] += per10;
    sand_board[nextr + dirs[dir].first - dirs[dir].second][nextc + dirs[dir].second - dirs[dir].first] += per10;

    // per 5
    sand_board[nextr + 2 * dirs[dir].first][nextc + 2 * dirs[dir].second] += per5;

    r = nextr;
    c = nextc;

    sand_board[r][c] = 0;
    sand_board[r + dirs[dir].first][c + dirs[dir].second] += all - 2 * per1 - 2 * per2 - 2 * per7 - 2 * per10 - per5;
}

void run() {
    for (int move_width = 1, move_dir = 0; move_width < board_width; ++move_width) {
        for (int i = 0; i < move_width; ++i) 
            run_tornado(move_dir);
        for (int i = 0; i < move_width; ++i) 
            run_tornado(move_dir + 1);

        move_dir = (move_dir + 2) % 4;

#if 0
        cout << move_width << '\n';
        for (int i=0; i < board_width + 4; ++i) {
            for (int j = 0; j < board_width + 4; ++j) {
                cout << setw(3) << sand_board[i][j] << ' ';
            }
            cout << '\n';
        }
#endif
    }
    for (int i = 0; i < board_width - 1; ++i) 
        run_tornado(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_width;
    for (int row = 0; row < board_width; ++row) {
        for (int col = 0; col < board_width; ++col) {
            cin >> sand_board[row + 2][col + 2];
        }
    }

    r = (board_width + 4) / 2;
    c = (board_width + 4) / 2;

    run();

    int ans = 0;
    for (int i = 0; i < board_width + 2; ++i) {
        ans += sand_board[0][i];
        ans += sand_board[1][i];
        ans += sand_board[i][board_width + 2];
        ans += sand_board[i][board_width + 3];
        ans += sand_board[board_width + 2][i + 2];
        ans += sand_board[board_width + 3][i + 2];
        ans += sand_board[i + 2][0];
        ans += sand_board[i + 2][1];
    }

    cout << ans << '\n';

    return 0;
}
