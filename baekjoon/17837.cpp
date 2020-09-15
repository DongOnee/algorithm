/**
 * 2020.09.15 
 */
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 12;

enum PHASE { INIT, TOUCH, DONE};
enum COLOR { WHITE, RED, BLUE };


pii dirs[5] = { {0,0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

typedef struct _piece {
    int x;
    int y;
    int dir;
    _piece(int _x, int _y, int _dir) : x(_x), y(_y), dir(_dir) {}
    void turn() {
        if (dir == 1) dir = 2;
        else if (dir == 2) dir = 1;
        else if (dir == 3) dir = 4;
        else if (dir == 4) dir = 3;
    }
    void go(int _dir = 0) { if (_dir == 0)  _dir =  dir;
        x += dirs[_dir].first;
        y += dirs[_dir].second;
    }
    pii nxt() { return {x + dirs[dir].first, y + dirs[dir].second }; }
} piece;

int n, k, board[MAXN+2][MAXN+2];
vector<piece> pieces;
vector<int> boardIndex[MAXN+2][MAXN+2];

bool chk(int row, int col) { return 0<row&&row<=n&&0<col&&col<=n; }
bool chk(pii xy)  { return chk(xy.first, xy.second); }

void extractBoardIdx(int x, int y, int searchIndex, deque<int>& lists) {
    vector<int>& goal = boardIndex[x][y];
    
    while (!goal.empty()) {
        int tp = goal.back();
        goal.pop_back();

        lists.push_back(tp);
        if (tp == searchIndex) break;
    }
}

void insertBoardIdx(int x, int y, deque<int>& lists, bool isFront) {
    vector<int>& goal = boardIndex[x][y];

    if (isFront) {
        while (!lists.empty()) {
            int f = lists.front();
            lists.pop_front();

            goal.push_back(f);
        }
    }
    else {
        while (!lists.empty()) {
            int b = lists.back();
            lists.pop_back();

            goal.push_back(b);
        }
    }
}

bool subRoutine(int idx) {
    piece& p = pieces[idx];
    // vector<int>& st = boardIndex[p.x][p.y];

    int stat = INIT;
    while (stat != DONE) {
        pii nextp = p.nxt();
        switch(stat) {
            case INIT:
                if (board[nextp.first][nextp.second] == BLUE || !chk(nextp) ) {
                    p.turn();
                }
                stat = TOUCH;
                break;
            case TOUCH:
                if (board[nextp.first][nextp.second] == BLUE || !chk(nextp) ) ;
                else {
                    deque<int> dq;

                    extractBoardIdx(p.x, p.y, idx, dq);
                    int p_dir = p.dir;
                    for (auto itr = dq.begin(); itr != dq.end(); ++itr) {
                        // cout << *itr << " th x : " << pieces[*itr].x << " y : " << pieces[*itr].y;
                        pieces[*itr].go(p_dir);
                        // cout << " ----> x : " << pieces[*itr].x << " y : " << pieces[*itr].y << endl;
                    }

                    if (board[nextp.first][nextp.second] == RED) {
                        insertBoardIdx(nextp.first, nextp.second, dq, true);
                    }
                    else {
                        insertBoardIdx(nextp.first, nextp.second, dq, false);
                    }
                }
                stat = DONE;
                break;
            default :
                stat = DONE;
                break;
        }
    }

    if (boardIndex[p.x][p.y].size() > 3) return false;
    
    return true;
}

int run() {
    int turn = 1;

    for (; turn < 1001; ++turn) {
        for (int idx = 0; idx < k; ++idx) {
            if (false == subRoutine(idx)) {
                return turn;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            cin >> board[row][col];
        }
    }

    for (int i=0; i<=n+1;  i++) {
        board[i][0] = board[i][n+1] = board[0][i] = board[n+1][i] = -1;
    }

    for (int i=0, x, y, d; i<k; i++) {
        cin >> x >> y >> d;
        pieces.emplace_back(x, y, d);
        boardIndex[x][y].push_back(i);
    }

    cout << run() << "\n";

    return 0;
}
