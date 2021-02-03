#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN = 101;
const int ANS = 2;
const pii dirs[4] = { {0,1},{-1,0},{0,-1},{1,0}};

bool board[MAXN][MAXN][3];
bool board_flag;

int gen;
pii start_point;
pii edge_point;

int sol() {
    int ret = 0;
    for (int row = 0; row < MAXN-1; ++row) {
        for (int col = 0; col < MAXN-1; ++col) {
            if (board[row][col][ANS] && board[row+1][col][ANS] && board[row][col+1][ANS] && board[row+1][col+1][ANS])
                ++ret;
        }
    }

    return ret;
}

void init() 
{
    for (int row = 0; row < MAXN; ++row) for (int col = 0; col < MAXN; ++col) board[row][col][0] = board[row][col][1] = false;
    gen = board_flag = 0;
}

pii turn(const pii& st, const pii& m) { return make_pair(st.first+m.second-st.second,st.second-m.first+st.first); }

void run()
{
    while (gen--) {
        for (int row = 0; row < MAXN; ++row)
            for (int col = 0; col < MAXN; ++col)
                board[row][col][!board_flag] = false;

        for (int row = 0; row < MAXN; ++row) {
            for (int col = 0; col < MAXN; ++col) {
                if (board[row][col][board_flag]) {
                    board[row][col][!board_flag] = true;
                    pii nxt = turn(edge_point, {row, col});
                    // cout << "start_point : " << edge_point.first << ", " << edge_point.second << "\t";
                    // cout << "prev_point : " << row << ", " << col << "\t";
                    // cout << "next_point : " << nxt.first << ", " << nxt.second << "\n";
                    board[nxt.first][nxt.second][!board_flag] = true;
                }
            }
        }
        board_flag ^= true;
        edge_point = turn(edge_point, start_point);
    }

    for (int row = 0; row < MAXN; ++row)
        for (int col = 0; col < MAXN; ++col)
            board[row][col][ANS] |= board[row][col][board_flag];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, d; cin >> t;
    while (t--) {
        init();
        cin >> start_point.second >> start_point.first >> d >> gen;
        edge_point = start_point + dirs[d];
        board[start_point.first][start_point.second][0] = board[edge_point.first][edge_point.second][0] = true;
        run();
        // cout << '\n';
    }

    cout << sol() << '\n';

    return 0;
}
