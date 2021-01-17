#include <iostream>
#include <utility>

#define board(PII) board[PII.first][PII.second]

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }
int turncode[4][6] = { 
    {3, 1, 0, 5, 4, 2}, // 오른쪽
    {2, 1, 5, 0, 4, 3}, // 왼쪽 
    {1, 5, 2, 3, 0, 4}, // 위쪽 
    {4, 0, 2, 3, 5, 1}  // 아래쪽 
};

const int MAXN = 20;
const pii dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};

int board[MAXN+2][MAXN+2];
int hi, wid;
pii cur;
int curDice[6], copyDice[6];

void turn(int dir) {
    for (int i = 0; i < 6; ++i) copyDice[i] = curDice[i];
    for (int i = 0; i < 6; ++i) curDice[i] = copyDice[turncode[dir][i]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, d;
    cin >> hi >> wid >> cur.first >> cur.second >> k;
    ++cur.first, ++cur.second;

    for (int row = 1; row <= hi; ++row)
    {
        board[row][0] = -1;
        board[row][wid+1] = -1;
        for (int col = 1; col <= wid; ++col)
            cin >> board[row][col];
    }
    for (int col = 1; col <= wid; ++col)
    {
        board[0][col] = -1;
        board[hi+1][col] = -1;
    }

    while (k--)
    {
        cin >> d; --d;

        pii nxt = cur+dirs[d];
        
        if (board(nxt) == -1);
        else
        {
            cur = nxt;
            turn(d);
            if (board(cur) == 0)
            {
                // 주사위바닥면이 복사됨
                board(cur) = curDice[5];
            }
            else
            {
                // 주사위로 복사
                curDice[5] = board(cur);
                board(cur) = 0;
            }
            cout << curDice[0] <<'\n';
        }
    }

    return 0;
}
