#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX_BOARD = 10;
const pii dirs[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int hi, wi;
char board[MAX_BOARD][MAX_BOARD];
bool visited[MAX_BOARD][MAX_BOARD][MAX_BOARD][MAX_BOARD];
pii red_ball, blue_ball;
pii cur_red, cur_blue;

pii operator+(const pii& a, const pii& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

pii operator-(const pii& a, const pii& b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

enum SLIDE_RET
{
    GOAL, 
    SUCCESS,
    FAIL
};

SLIDE_RET slide(int dir, pii& next_red, pii& next_blue) {
    SLIDE_RET ret = SUCCESS;

    pii red, blue, temp;

    temp = cur_blue;
    while (true)
    {
        blue = temp;
        
        temp = temp + dirs[dir];
        if ('#' == board[temp.first][temp.second])
            break;
        else if ('O' == board[temp.first][temp.second])
            return FAIL;
    }
    next_blue = blue;

    temp = cur_red;
    while (true)
    {
        red = temp;

        temp = temp + dirs[dir];
        if ('#' == board[temp.first][temp.second])
            break;
        else if ('O' == board[temp.first][temp.second])
            return GOAL;
    }
    next_red = red;

    if (next_red == next_blue)
    {
        pii diff = cur_red - cur_blue;
        int d = diff.first + diff.second;
        if (d < 0)  // Blue 의 인덱스가 더 높음
        {
            if (dir == 0 || dir == 1) next_red = next_red - dirs[dir];
            else if (dir == 2 || dir == 3) next_blue = next_blue - dirs[dir];
        }
        else        // Red 의 인덱스가 더 높음
        {
            if (dir == 2 || dir == 3) next_red = next_red - dirs[dir];
            else if (dir == 0 || dir == 1) next_blue = next_blue - dirs[dir];
        }
    }

    return ret;
}

int run() {
    int ret = 0;

    queue<pair<pii, pii>> qu;
    qu.push({red_ball, blue_ball});
    visited[red_ball.first][red_ball.second][blue_ball.first][blue_ball.second] = true;
    while (!qu.empty() && ret < 10)
    {
        ret++;
        long sz = qu.size();

        while (sz--)
        {
            cur_red = qu.front().first;
            cur_blue = qu.front().second;
            qu.pop();

            // 기울이기
            for (int dir = 0; dir < 4; ++dir)
            {
                pii next_red, next_blue;
                auto r = slide(dir, next_red, next_blue);
                if (GOAL == r) return ret;
                else if (FAIL == r) continue;
                else if (visited[next_red.first][next_red.second][next_blue.first][next_blue.second]) continue;

                qu.push({next_red, next_blue});
                visited[next_red.first][next_red.second][next_blue.first][next_blue.second] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> hi >> wi;
    for (int row = 0;  row < hi;  ++row)
        for (int col = 0;  col < wi; ++col)
        {
            cin >> board[row][col];
            if (board[row][col] == 'B')
            {
                blue_ball = {row, col};
                board[row][col] = '.';
            }

            if (board[row][col] == 'R')
            {
                red_ball = {row, col};
                board[row][col] = '.';
            }
        }

    cout << run() << '\n';

    return 0;
}
