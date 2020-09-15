#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 12;

const pii dirs[5] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

enum COLOR {
    WHITE,
    RED,
    BLUE
};

typedef struct {
    int x;
    int y;
    int dir;
    void turn() {
        if (dir == 1) dir = 2;
        else if (dir == 2) dir = 1;
        else if (dir == 3) dir = 4;
        else if (dir == 4) dir = 3;
    };
    pii nxt() {
        return { x + dirs[dir].first, y + dirs[dir].second };
    };
    void go(int d = 0) {
        if (d == 0) d = dir;
        x += dirs[d].first;
        y += dirs[d].second;
    };
} piece;


int n, k, board[MAXN + 2][MAXN + 2];
vector<piece> pieces;
stack<int> boardIDX[MAXN + 2][MAXN + 2];

bool inline chk(int x, int y) { return 0 < x && x <= n && 0 < y && y <= n; }
bool inline chk(pii xy) { return chk(xy.first, xy.second); }

bool inqueue(const int idx, deque<int>& dq) {
    int x = pieces[idx].x;
    int y = pieces[idx].y;
    stack<int>& st = boardIDX[x][y];

    while (!st.empty()) {
        int tp = st.top();
        st.pop();
        dq.push_front(tp);

        if (tp == idx) return true;
    }

    return false;
}


void subRoutine(const int index) {
    piece& p = pieces[index];

    int nextX = p.nxt().first;
    int nextY = p.nxt().second;

    if (!chk(nextX, nextY) || ( BLUE == board[nextX][nextY]) ) {
        p.turn();
        nextX = p.nxt().first;
        nextY = p.nxt().second;

        if (BLUE == board[nextX][nextY]) {
            return;
        } 
    }

    if (!chk(nextX, nextY)) {
        p.turn();
        nextX = p.nxt().first;
        nextY = p.nxt().second;
        if (BLUE == board[nextX][nextY]) {
            return;
        }
    } 

    deque<int> upperList;
    inqueue(index, upperList);
    
    int pdir = p.dir;
    if (WHITE == board[nextX][nextY]) {
        p.go();
        boardIDX[nextX][nextY].push(index);

        while (!upperList.empty()) {
            int upperIndex = upperList.front();
            upperList.pop_front();

            pieces[upperIndex].go(pdir);
            boardIDX[nextX][nextY].push(upperIndex);
        }
    } else if (RED == board[nextX][nextY]) {
        while (!upperList.empty()) {
            int upperIndex = upperList.back();
            upperList.pop_back();

            pieces[upperIndex].go(pdir);
            boardIDX[nextX][nextY].push(upperIndex);
        }

        p.go();
        boardIDX[nextX][nextY].push(index);
    }
}

int run() {
    int ret = 1;
    for (int idx = 0; ret < 1001; ret++, idx++) {
        idx %= n;
        subRoutine(idx);
        if (3 < boardIDX[pieces[idx].x][pieces[idx].y].size()) return ret;
    }
    
    return (ret == 1001?-1:ret);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            cin >> board[row][col];
        }
    }

    for (int i = 0; i <= n+1; i++) {
        board[i][0] = board[i][n+1] = board[0][i] = board[n+1][i] = -1;
    }

    for (int i = 0, a, b, c; i < k; i++) {
        cin >> a >> b >> c;
        pieces.push_back({a, b, c});
        boardIDX[a][b].push(i);
    }

    cout << run() << '\n';

    return 0;
}
