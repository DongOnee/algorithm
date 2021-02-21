#include <iostream>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first, a.second+b.second); }

typedef struct
{
    pii point;
    int dir;
}chess_info;

const int MAXN = 14;
const int MAXK = 10;

const int WHITE = 0;
const int RED   = 1;
const int BLUE  = 2;

const pii dirs[4] = {{0,1},{-1,0},{0,-1},{1,0}};
int conv[5] = {0, 0, 2, 1, 3};

int board[MAXN][MAXN], board_size;
int cnts[MAXN][MAXN];
int arr_board[MAXN][MAXN][5];

chess_info ch[MAXK]; 
int k;

int run()
{
    int t = 0;
    while (true) {
        if (++t > 1000) break;
        bool flag = false;

        for (int idx = 0; idx < k; ++idx) {
            pii cur = ch[idx].point;
            int arr_index = 0;
            while (arr_board[cur.first][cur.second][arr_index] != idx)  ++arr_index;

            pii nxt = cur + dirs[ch[idx].dir];
            if (board[nxt.first][nxt.second] == BLUE) {
                if (!flag) {
                    ch[idx].dir = (ch[idx].dir + 2) % 4;
                    flag = true;
                    --idx;
                    continue;
                }
            }
            else if (board[nxt.first][nxt.second] == WHITE) {
                for (int i = arr_index; i < cnts[cur.first][cur.second]; ++i) {
                    int& nxt_cnt = cnts[nxt.first][nxt.second];
                    if (nxt_cnt == 3) return t;
                    arr_board[nxt.first][nxt.second][nxt_cnt++] = arr_board[cur.first][cur.second][i];
                    ch[arr_board[cur.first][cur.second][i]].point = nxt;
                }
                cnts[cur.first][cur.second] = arr_index;
            }
            else if (board[nxt.first][nxt.second] == RED) {
                for (int i = cnts[cur.first][cur.second] -1; arr_index <= i; --i) {
                    int& nxt_cnt = cnts[nxt.first][nxt.second];
                    if (nxt_cnt == 3) return t;
                    arr_board[nxt.first][nxt.second][nxt_cnt++] = arr_board[cur.first][cur.second][i];
                    ch[arr_board[cur.first][cur.second][i]].point = nxt;
                }
                cnts[cur.first][cur.second] = arr_index;
            }
            flag = false;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size >> k;
    for (int row = 1; row <= board_size; ++row) {
        for (int col = 1; col <= board_size; ++col)
            cin >> board[row][col];
        board[row][0] = BLUE;
        board[0][row] = BLUE;
        board[row][board_size+1] = BLUE;
        board[board_size+1][row] = BLUE;
    }

    for (int i = 0; i < k; ++i) {
        int r, c, d; cin >> r >> c >> d;
        ch[i] = {{r, c}, conv[d]};
        arr_board[r][c][cnts[r][c]++] = i;
    }

    cout << run() << '\n';

    return 0;
}
