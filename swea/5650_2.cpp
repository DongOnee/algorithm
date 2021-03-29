#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 100;
const int MAXM = 5;
const int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int conv[4][6] = {
    {0, 2, 1, 3, 2, 2},
    {1, 3, 3, 2, 0, 3},
    {2, 1, 0, 0, 3, 0},
    {3, 0, 2, 1, 1, 1}
};

int board[MAXN+2][MAXN+2];
int board_size;
int wormhole[MAXM*2][2];
bool wh_visited[MAXM];

void init() 
{
    for (int i = 0; i < MAXM; ++i) {
        wormhole[i][0] = wormhole[i][1] = 0;
        wh_visited[i] = false;
    }

    cin >> board_size;
    for (int r = 1; r <= board_size; ++r) for (int c = 1; c <= board_size; ++c) {
        cin >> board[r][c];
        if (board[r][c] > 5) { // worm hole
            int wi = board[r][c] - 6;
            int nxt_wi = wi + 5;

            if (wh_visited[wi]) {
                wormhole[nxt_wi][0] = r;
                wormhole[nxt_wi][1] = c;
            }
            else {
                wh_visited[wi] = true;
                wormhole[wi][0] = r;
                wormhole[wi][1] = c;
                board[r][c] += 5;
            }
        }
    }
    for (int i = 0; i <= board_size+1; ++i) board[0][i] = board[i][0] = board[board_size+1][i] = board[i][board_size+1] = 5;
}

int run(int r, int c, int d) 
{
    int cr = r, cc = c;
    int ret = 0;

    board[r][c] = -1;
    while (true) {
        int nr = r + dirs[d][0];
        int nc = c + dirs[d][1];

        if (board[nr][nc] == -1) break;
        if (board[nr][nc] < 6) { // block
            if (board[nr][nc] > 0) ++ret;
            d = conv[d][board[nr][nc]];
        }
        else { // worm hole
            int wh_index = board[nr][nc] - 6;
            nr = wormhole[wh_index][0];
            nc = wormhole[wh_index][1];
        }

        r = nr, c = nc;
    }
    
    board[cr][cc] = 0;

    return ret;
}

int run()
{
    int ret = 0;
    for (int r = 1; r <= board_size; ++r) for (int c = 1; c <= board_size; ++c) 
        if (board[r][c] == 0) 
            for (int d = 0; d < 4; ++d) {
                ret = max(ret, run(r, c, d));
            }

    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("/Users/macbook/Downloads/sample.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        cout << '#' << test_case << ' ' << run() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
