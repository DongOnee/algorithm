#include <iostream>
#include <queue>

using namespace std;

typedef struct _info
{
    int r, c;
    bool magic;
    _info(int _r, int _c, bool m) : r(_r), c(_c), magic(m) {};
}info;

const int MAXN = 1000;
const int dirs[4][2] = {{0, 1},{0,-1},{1,0},{-1,0}};

bool board[MAXN][MAXN];
bool visited[MAXN][MAXN][2];
int board_width, board_hight;
int st_r, st_c, ed_r, ed_c;


bool chk(int r, int c) { return 0<=r&&r<board_hight&&0<=c&&c<board_width; }

int run()
{
    int ret = 0;
    queue<info> qu;
    qu.emplace(st_r, st_c, false);
    visited[st_r][st_c][false] = true;

    while (!qu.empty()) {
        ++ret;
        int sz = qu.size();
        while (sz--) {
            info f = qu.front(); qu.pop();
            
            for (int d = 0; d < 4; ++d) {
                int nr = f.r + dirs[d][0];
                int nc = f.c + dirs[d][1];
                bool m = f.magic;

                if (!chk(nr,nc)) continue;

                if (nr == ed_r && nc == ed_c) return ret;


                if (board[nr][nc]) {
                    if(m) continue;
                    m = true;
                    if (visited[nr][nc][m]) continue;
                    visited[nr][nc][m] = true;
                    qu.emplace(nr,nc,m);
                }
                else {
                    if (visited[nr][nc][m]) continue;
                    if (m == true && visited[nr][nc][false]) continue;
                    visited[nr][nc][m] = true;
                    qu.emplace(nr,nc,m);
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_hight >> board_width;
    cin >> st_r >> st_c >> ed_r >> ed_c;
    --st_r, --st_c, --ed_r, --ed_c;

    for (int r = 0; r < board_hight; ++r) for (int c = 0; c < board_width; ++c) cin >> board[r][c];

    cout << run() << endl;

    return 0;
}
