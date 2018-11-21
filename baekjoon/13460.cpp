/**
 * 18.11.21. ~ 18.11.22.
 * Red ball 이 Goal 에 도달하는 최단 거리를 구하는 문제로 BFS 를 이용하여 최단거리를 구할 수 있다.
 * 1시간 내에 풀지 못하여 블로그를 참고 하였다.
 */
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N, M;
char map[11][11];
bool chk[11][11][11][11];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> red, blu;
int cnt;

struct data {
    pair<int, int> r;
    pair<int, int> b;
    int count;
};

int bfs() {
    queue<struct data> q;
    q.push({red, blu, 0});
    while(!q.empty())
    {
        pair<int, int> now_red = q.front().r;
        pair<int, int> now_blu = q.front().b;
        int now_cnt = q.front().count;
        q.pop();
        for (int i=0; i<4; i++)
        {
            pair<int, int> next_red = now_red;
            pair<int, int> next_blu = now_blu;
            int cnt_red=0, cnt_blu=0, next_cnt = now_cnt+1;

            while (map[next_red.first+dir[i][0]][next_red.second+dir[i][1]] != '#' && map[next_red.first+dir[i][0]][next_red.second+dir[i][1]] != 'O')
            {
                cnt_red++;
                next_red.first+=dir[i][0];
                next_red.second+=dir[i][1];
            }
            while (map[next_blu.first+dir[i][0]][next_blu.second+dir[i][1]] != '#' && map[next_blu.first+dir[i][0]][next_blu.second+dir[i][1]] != 'O')
            {
                cnt_blu++;
                next_blu.first+=dir[i][0];
                next_blu.second+=dir[i][1];
            }
            
            if (map[next_blu.first+dir[i][0]][next_blu.second+dir[i][1]] == 'O') continue;
            if (map[next_red.first+dir[i][0]][next_red.second+dir[i][1]] == 'O') return next_cnt;
            if (next_cnt == 10) continue;
            if (next_red == next_blu)
            {
                if (cnt_red < cnt_blu)
                {
                    cnt_blu--;
                    next_blu.first-=dir[i][0];
                    next_blu.second-=dir[i][1];
                }
                else
                {
                    cnt_red--;
                    next_red.first-=dir[i][0];
                    next_red.second-=dir[i][1];
                }
            }
            if (chk[next_red.first][next_red.second][next_blu.first][next_blu.second]) continue;
            q.push({next_red, next_blu, next_cnt});
            chk[next_red.first][next_red.second][next_blu.first][next_blu.second] = true;
        }
    }
    return -1;
}

int main(void) {
    scanf("%d %d", &N, &M);
    for (int row=0; row<N; row++) 
    {
        scanf("%s", map[row]);
        for (int col=0; col<M; col++)
        {
            if (map[row][col] == 'R') {red=make_pair(row, col);}
            else if (map[row][col] == 'B') {blu=make_pair(row, col);}
        }
    }
    printf("%d\n", bfs());
    return 0;
}