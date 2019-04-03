/**
 *
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, char> command;

int t;
int map[101][101];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<command> q;
queue<pair<int, int>> snake;
int snakeDir;

bool chk(int row, int col, int n) { return 0<row&&row<=n&&0<col&&col<=n; }
bool chk(pair<int, int> pt, int n) { return 0<pt.first&&pt.first<=n&&0<pt.second&&pt.second<=n; }
int getMap(pair<int, int> pt) { return map[pt.first][pt.second]; }
void setMap(pair<int, int> pt, int val) { map[pt.first][pt.second]=val; }

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int tc=1, n, m, k; tc<=t; tc++)
    {
        queue<command> emptyQ;
        swap(q, emptyQ);

        scanf("%d %d %d", &n, &m, &k);
        for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) map[i][j] = 0;
        for (int i=0, row, col; i<m; i++)
        {
            scanf("%d %d", &row, &col);
            map[row][col] = 1;
        }
        for (int i=0; i<k; i++)
        {
            int sec;
            char turnCmd;
            scanf("%d %c", &sec, &turnCmd);
            q.push(make_pair(sec, turnCmd));
        }
        q.push(make_pair(0, '0'));

        queue<pair<int, int>> emptyQ2;
        emptyQ2.push({1, 1});
        map[1][1] = -1;
        swap(emptyQ2, snake);
        snakeDir = 0;
        
        bool flag = true;
        command nextCmd = q.front();
        q.pop();
        int sol=0;
        while(flag)
        {
            pair<int, int> snakeHead = snake.back();
            pair<int, int> nextHead = make_pair(snakeHead.first+dir[snakeDir][0], snakeHead.second+dir[snakeDir][1]);
            if (!chk(nextHead, n))
            {
                flag = false;
                continue;
            }

            int nextHeadValue = getMap(nextHead);
            if (nextHeadValue == -1)
            {
                flag = false;
                continue;
            }
            else 
            {
                setMap(nextHead, -1);
                snake.push(nextHead);
                if (nextHeadValue == 0)
                {
                    setMap(snake.front(), 0);
                    snake.pop();
                }
            }
            if (nextCmd.second != '0')
            {
                if (--nextCmd.first == 0)
                {
                    if (nextCmd.second == 'D') snakeDir += 1;
                    else snakeDir += 3;
                    snakeDir %= 4;
                    nextCmd = q.front();
                    q.pop();
                }
            }
            sol++;
        }
        printf("#%d %d\n", tc, sol+1);
    }
    return 0;
}


/*
4
5 0 5
4 D
4 D
4 D
3 D
5 L
8 3 6
5 4
5 8
2 5
7 D
4 D
4 D
3 D
1 D
1 D
8 5 12
6 1
7 3
3 5
5 7
5 6
2 D
6 D
2 D
2 D
6 L
2 L
2 L
2 L
1 L
3 L
4 D
1 L
20 13 19
6 15
7 18
20 14
14 13
11 9
7 10
3 18
10 10
13 13
13 5
6 9
10 4
4 3
17 D
19 D
5 D
13 D
2 L
1 L
6 L
5 L
4 L
1 L
3 D
3 D
3 D
3 D
2 D
6 L
12 D
5 D
4 D
*/