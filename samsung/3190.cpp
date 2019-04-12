/**
 * 19.4.8.21:02~21:50
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int n, k, l, map[101][101];
queue<pair<int, int>> cmd;
queue<pair<int, int>> snake;
int snakeHead;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool chk(int row, int col) { return 0<row&&row<=n&&0<col&&col<=n; }

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i=0, a, b; i<k; i++)
    {
        scanf("%d %d", &a, &b);
        map[a][b] = 2;
    }
    scanf("%d", &l);
    for (int i=0, a; i<l; i++)
    {
        char b;
        scanf("%d %c", &a, &b);
        cmd.push(make_pair(a, b));
    }

    bool alive = true;
    int turn = 0;
    map[1][1] = 1;
    snake.push(make_pair(1, 1));
    snakeHead = 0;

    while (alive)
    {
        turn++;
        int nextRow = snake.back().first+dir[snakeHead][0];
        int nextCol = snake.back().second+dir[snakeHead][1];
        
        if (!chk(nextRow, nextCol)) break;
        if (map[nextRow][nextCol] == 1) break;

        snake.push({nextRow, nextCol});
        if (map[nextRow][nextCol] == 0)
        {
            pair<int, int> tail = snake.front();
            map[tail.first][tail.second] = 0;
            snake.pop();
        }
        map[nextRow][nextCol] = 1;
        
        if (!cmd.empty())
        {
            if (cmd.front().first == turn)
            {
                char turn_dir = cmd.front().second;
                if (turn_dir == 'L') snakeHead +=3;
                else snakeHead += 1;
                snakeHead %= 4;
                cmd.pop();
            }
        }

    }

    printf("%d\n", turn);

    return 0;
}
