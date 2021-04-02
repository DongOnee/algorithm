#include <iostream>
#include <utility>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;
pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

enum STATE {INACTIVE = 1, ACTIVE, DEAD};
typedef struct
{
    STATE state;
    int life;
    int full;
    int st;
}cell_info;

const int MAXN = 350;
const int BORDER = 150;
const pii dirs[4] = {{0,1},{1,0},{0,-1},{-1,0}};

cell_info board[MAXN][MAXN];
int ans, board_width, board_hight, k;
queue<pii> qu;

void init()
{
    ans = 0;
    memset(board, 0, sizeof(board));
    while(!qu.empty()) qu.pop();
    int life;

    cin >> board_hight >> board_width >> k;
    for (int r = 0; r < board_hight; ++r) for (int c = 0; c < board_width; ++c) {
        cin >> life;
        if (life == 0) continue;
        qu.emplace(r + BORDER, c + BORDER);
        board[r + BORDER][c + BORDER] = {INACTIVE, life, life, k};
    }
}

void run()
{
    while (k--) {
        int sz = qu.size();
        while (sz--) {
            pii f = qu.front(); qu.pop();
            auto& b = board[f.first][f.second];

            if (b.state == ACTIVE && b.life == b.full) {
                for (int d = 0; d < 4; ++d) {
                    pii nxt = f + dirs[d];
                    auto& nxtb = board[nxt.first][nxt.second];

                    if (nxtb.full == 0) {
                        nxtb = {INACTIVE, b.full, b.full, k};
                        qu.emplace(nxt);
                    }
                    else if (nxtb.st == k && b.full > nxtb.full) {
                        nxtb.full = b.full;
                        nxtb.life = b.full;
                    }
                }
            }

            if (--b.life == 0) {
                if (b.state == ACTIVE) {
                    b.state = DEAD;
                    continue;
                }
                else if (b.state == INACTIVE) {
                    b.state = ACTIVE;
                    b.life = b.full;
                }
            }

            qu.emplace(f);
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	// freopen("/Users/macbook/Downloads/sample_input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        run();

        cout << '#' << test_case << ' ' << qu.size() << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
