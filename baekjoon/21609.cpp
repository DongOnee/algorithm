#include <iostream>
#include <utility>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

#define MAXN 20
#define MAXM 6

int dirs[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int board[MAXN][MAXN];
int _boardSize;     // N
int _colorCount;    // M
int score;

#define BLACK -1
#define RAINBOW 0

#define inboard(i,j) (0<=(i)&&(i)<_boardSize&&0<=(j)&&(j)<_boardSize)

void printBoard() {
    for (int i = 0; i < _boardSize; ++i) {
        for (int j = 0; j < _boardSize; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool visited[MAXN][MAXN];
int getBonus(int i, int j, int& rainbowCount)
{
    queue<pii> qu;
    vector<pii> visitedRainbow;
    visited[i][j] = true;
    qu.push({i,j});
    int color = board[i][j];
    int sz = 1;

    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for (int d = 0; d < 4; ++d) {
            int ni = f.first + dirs[d][0];
            int nj = f.second + dirs[d][1];

            if (!inboard(ni, nj)) continue;
            if (visited[ni][nj]) continue;
            if (board[ni][nj] == BLACK) continue;
            if (board[ni][nj] == color || board[ni][nj] == RAINBOW) {
                if (board[ni][nj] == RAINBOW) {
                    visitedRainbow.push_back({ni, nj});
                    ++rainbowCount;
                }
                visited[ni][nj] = true;
                qu.push({ni, nj});
                ++sz;
            }
        }
    }


    for (auto& p : visitedRainbow) visited[p.first][p.second] = false;

    return (sz==1?-1:sz*sz);
}

pii searchMaxPoint()
{
    memset(visited, 0, sizeof(visited));

    int maxBounus = 0;
    int maxRainbowCount = 0;

    pii ret = {-1, -1};
    for (int i = 0; i < _boardSize; ++i) {
        for (int j = 0; j < _boardSize; ++j) {
            if (!visited[i][j] && board[i][j] != BLACK && board[i][j] != RAINBOW && board[i][j] != MAXM) {
                int rainbowCount = 0;
                int b = getBonus(i, j, rainbowCount);
                if (maxBounus < b
                    || (maxBounus == b && maxRainbowCount <= rainbowCount)) {
                    ret = {i, j};
                    maxBounus = b;
                    maxRainbowCount = rainbowCount;
                }
            }
        }
    }

    return ret;
}

void getScore(pii p)
{
    queue<pii> qu;
    qu.push({p.first,p.second});
    int color = board[p.first][p.second];
    board[p.first][p.second] = MAXM;
    int sz = 1;

    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for (int d = 0; d < 4; ++d) {
            int ni = f.first + dirs[d][0];
            int nj = f.second + dirs[d][1];

            if (!inboard(ni, nj)) continue;
            if (board[ni][nj] == BLACK) continue;
            if (board[ni][nj] == color || board[ni][nj] == RAINBOW) {
                qu.push({ni, nj});
                board[ni][nj] = MAXM;
                ++sz;
            }
        }
    }
    
    score += sz*sz;
}

void gravity()
{
    for (int j = 0; j < _boardSize; ++j) {
        for (int i = _boardSize - 1; 0 <= i; --i) {
            if (0 <= board[i][j] && board[i][j] < MAXM) {
                int s = i + 1;
                for (; s < _boardSize; ++s) {
                    if (board[s][j] != MAXM) break;
                }

                swap(board[s-1][j], board[i][j]);
            }
        }
    }
}

void rotate()
{
    static int cp_board[MAXN][MAXN];

    memcpy(cp_board, board, sizeof(board));

    for (int i = 0; i < _boardSize; ++i) {
        for (int j = 0; j < _boardSize; ++j) {
            board[_boardSize - 1 - j][i] = cp_board[i][j];
        }
    }
}

void run()
{
    while (true) {
        pii point = searchMaxPoint();

        // printBoard(); cout << '\n';
        if (point.first == -1) break;

        getScore(point);

        gravity();
        rotate();
        gravity();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    memset(board, MAXM, sizeof(board));
    cin >> _boardSize >> _colorCount;
    for (int i = 0; i < _boardSize; ++i) {
        for (int j = 0; j < _boardSize; ++j) {
            cin >> board[i][j];
        }
    }
    
    run();

    cout << score << '\n';
}
