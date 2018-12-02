#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int map[20][20];
int N, M;
pair<int, int> cur;
int dice[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<M; }

int get_top() { return dice[0][1]; }
int get_bottom() { return dice[2][1]; }

void dice_e() {
    int tmp = dice[0][1];
    dice[0][1] = dice[0][0];
    dice[0][0] = dice[2][1];
    dice[2][1] = dice[0][2];
    dice[0][2] = tmp;
}

void dice_w() {
    int tmp = dice[0][1];
    dice[0][1] = dice[0][2];
    dice[0][2] = dice[2][1];
    dice[2][1] = dice[0][0];
    dice[0][0] = tmp;
}

void dice_n() {
    int tmp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = tmp;
}

void dice_s() {
    int tmp = dice[0][1];
    dice[0][1] = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = tmp;
}

int main(int argc, char const *argv[])
{
    int x, y, K;
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
    cur = {x, y};

    for (int row=0; row<N; row++) for (int col=0; col<M; col++) scanf("%d", &map[row][col]);

    for (int cmd_cnt=0; cmd_cnt<K; cmd_cnt++)
    {
        int cmd;
        scanf("%d", &cmd);
        int next_row = cur.first+dir[cmd-1][0];
        int next_col = cur.second+dir[cmd-1][1];
        if (!chk(next_row, next_col)) continue;
        cur = {next_row, next_col};
        if (cmd == 1 ) dice_e();
        else if (cmd == 2 ) dice_w();
        else if (cmd == 3 ) dice_n();
        else dice_s();
        printf("%d\n", get_top());
        if (map[cur.first][cur.second] == 0) map[cur.first][cur.second]=get_bottom();
        else
        {
            dice[2][1] = map[cur.first][cur.second];
            map[cur.first][cur.second] = 0;
        }
    }

    return 0;
}
