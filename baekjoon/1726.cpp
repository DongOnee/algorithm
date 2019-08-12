/**
 * 19.1.30.
 */
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

typedef struct {
    pair<int, int> point;
    int direction;
}robots;

robots end_point;

queue<robots> q;

int M, N;
int map[101][101];
bool visited[101][101][4];

int dir_index[2][4] = { {3, 4, 2, 1}, {4, 3, 1, 2} };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int row, int col) { return 0<row&&row<=M&&0<col&&col<=N; }
bool chk(pair<int, int> p) { return 0<p.first&&p.first<=M&&0<p.second&&p.second<=N; }

bool go(robots cur, int dist)
{
    pair<int, int> new_point = {cur.point.first+dist*dir[cur.direction-1][0], cur.point.second+dist*dir[cur.direction-1][1]};
    if (!chk(new_point)) return false;
    if (map[new_point.first][new_point.second] == 1) return false;
    if (visited[new_point.first][new_point.second][cur.direction-1]) return true;
    cur.point = new_point;
    visited[cur.point.first][cur.point.second][cur.direction-1] = true;
    q.push(cur);
    return true;
}

void turn(robots cur, int t) // 0: right, 1: left
{
    int cur_dir = cur.direction;
    int new_dir = dir_index[t][cur_dir-1];
    if (visited[cur.point.first][cur.point.second][new_dir-1] || map[cur.point.first][cur.point.second] == 1) return;
    cur.direction = new_dir;
    visited[cur.point.first][cur.point.second][cur.direction-1] = true;
    q.push(cur);
}

int main(void)
{
    scanf("%d %d", &M, &N);
    for (int i=1; i<=M; i++) for (int j=1; j<=N; j++) scanf("%d", &map[i][j]);
    robots robot;
    scanf("%d %d %d", &robot.point.first, &robot.point.second, &robot.direction);
    scanf("%d %d %d", &end_point.point.first, &end_point.point.second, &end_point.direction);

    q.push(robot);
    int ret =0;
    bool ans_point = false;
    while(!q.empty())
    {
        long size = q.size();
        while(size--)
        {
            robots front = q.front();
            q.pop();
            if (front.point == end_point.point)
            {
                if (front.direction == end_point.direction)
                {
                    printf("%d\n", ret);
                    return 0;
                }
            }
            else  for (int i=1; i<4; i++) if(!go(front, i)) break;
            turn(front, 0);
            turn(front, 1);
        }
        ret++;
    }

    return 0;
}