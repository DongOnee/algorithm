#include <iostream>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int,int> pii;

#define MAXN 50

int board[MAXN+2][MAXN+2];
int _boardSize;

#define inBoard(i,j) (0<(i)&&(i)<=_boardSize&&0<(j)&&(j)<=_boardSize)

int dirs[9][2] = { {0,0}, {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

vector<pii> _clouds;

int score;

void run()
{
    int d, c; cin >> d >> c;

    static bool isCloud[MAXN + 2][MAXN + 2];
    memset(isCloud, 0, sizeof(isCloud));
    for (auto & cloud : _clouds) {  // Cloud Move
        cloud.first  = (cloud.first - 1  + _boardSize * MAXN + dirs[d][0] * c) % _boardSize + 1;
        cloud.second = (cloud.second - 1 + _boardSize * MAXN + dirs[d][1] * c) % _boardSize + 1;

#ifndef ONLINE_JUDGE
        cout << cloud.first << ' ' << cloud.second << '\n';
#endif

        isCloud[cloud.first][cloud.second] = true;
    }

    for (auto & cloud : _clouds) {
        int i = cloud.first;
        int j = cloud.second;
        ++board[i][j];
    }

    vector<pair<pii, int>> candidates;
    for (auto & cloud : _clouds) {
        int i = cloud.first;
        int j = cloud.second;
        int gain = 0;
        for (int d = 2; d < 9; d += 2) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];

            if (!inBoard(ni,nj)) continue;
            if (board[ni][nj] > 0) ++gain;
        }

        candidates.push_back({cloud, gain});
    }

    for (auto & candidate : candidates) {
        board[candidate.first.first][candidate.first.second] += candidate.second;
    }

    _clouds.clear();

    for (int i = 1; i <= _boardSize; ++i) {
        for (int j = 1; j <= _boardSize; ++j) {
            if (board[i][j] >= 2 && !isCloud[i][j]) {
                board[i][j] -= 2;
                _clouds.push_back({i,j});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int turnCount;
    cin >> _boardSize >> turnCount;

    for (int i = 1; i <= _boardSize; ++i) {
        for (int j = 1; j <= _boardSize; ++j) {
            cin >> board[i][j];
        }
    }

    _clouds.push_back({_boardSize-1,1});
    _clouds.push_back({_boardSize-1,2});
    _clouds.push_back({_boardSize,1});
    _clouds.push_back({_boardSize,2});

    while (turnCount--) {
        run();

        
#ifndef ONLINE_JUDGE
        cout << '\n';
        for (int i = 1; i <= _boardSize; ++i) {
            for (int j = 1; j <= _boardSize; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
#endif
    }

    int ret = 0;
    for (int i = 1; i <= _boardSize; ++i) {
        for (int j = 1; j <= _boardSize; ++j) {
            ret += board[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}
