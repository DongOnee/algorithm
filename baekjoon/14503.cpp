#include <iostream>
#include <utility>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN = 50;
const pii dirs[4] = {{-1,0},{0,1},{1,0},{0,-1}};

bool board[MAXN][MAXN];
bool visited[MAXN][MAXN];
int hi, wi;
pii robot;
int robot_dir;
bool flag = false;

int run()
{
    enum {
        STEP1,
        STEP2,
        STEP2_1
    };

    int ret = 0;
    int state = STEP1;

    for(;;) {
        if (state == STEP1) {
            ++ret;
            visited[robot.first][robot.second] = true;
            state = STEP2;
        }
        else if (state == STEP2) {
            for (int i = 0, d = robot_dir; i < 4; ++i) {
                d = (d + 3) % 4;
                pii nxt = robot + dirs[d];
                if (!board[nxt.first][nxt.second] && !visited[nxt.first][nxt.second]) {
                    robot = nxt;
                    robot_dir = d;
                    state = STEP1;
                    break;
                }
            }
            if (state == STEP2) state = STEP2_1;
        }
        else if (state == STEP2_1) {
            int d = (robot_dir + 2) % 4;
            pii nxt = robot + dirs[d];

            if (board[nxt.first][nxt.second]) return ret;
            robot = nxt;
            state = STEP2;
        }
    }

    return ret;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(board, true, sizeof(board));
    
    cin >> hi >> wi >> robot.first >> robot.second >> robot_dir;

    for (int row = 0; row < hi; ++row)
        for (int col = 0; col <wi; ++col)
            cin >> board[row][col];

    cout << run() << '\n';

    return 0;
}
