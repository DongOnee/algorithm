/**
 * 2018.10.5. 07`46``
*/
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int** map; // 0 : road, 1 : wall
int** visited;
queue<pair<pair<int, int>, pair<bool, int> > > q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void bfs(pair<pair<int, int>, pair<bool, int> > p, int N, int M) {
    int x=p.first.first;
    int y=p.first.second;
    bool chance = p.second.first;
    int count = p.second.second;

    if(map[x][y] == 1)
    {
        if(!chance) return;
        chance = false;
    }

    for (int i=0; i<4; i++)
    {
        int new_x = x+dir[i][0];
        int new_y = y+dir[i][1];
        int new_count = count+1;
        if (-1<new_x && new_x<N && -1<new_y && new_y<M) // in map
        {
            if (visited[new_x][new_y] == 0)
            {
                q.push(make_pair(make_pair(new_x, new_y), make_pair(chance, new_count)));
                visited[new_x][new_y] = new_count;
            }
            else if (new_count < visited[new_x][new_y])
            {
                q.push(make_pair(make_pair(new_x, new_y), make_pair(chance, new_count)));
                if(chance) visited[new_x][new_y] = new_count;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    map = new int*[N];
    visited = new int*[N];
    for (int row=0; row < N; row++)
    {
        *(map+row) = new int[M];
        *(visited+row) = new int[M];
        int input;
        scanf("%d", &input);
        for (int col=M-1; -1<col; col--)
        {
            map[row][col] = input%10;
            visited[row][col] = 0;
            input /= 10;
        }
    }
    q.push(make_pair(make_pair(0,0), make_pair(true, 1)));
    visited[0][0] = 1;

    while(!q.empty())
    {
        pair<pair<int, int>, pair<bool, int> > front = q.front();
        q.pop();
        bfs(front, N, M);
    }

    if (visited[N-1][M-1] == 0) printf("-1\n");
    else printf("%d\n", visited[N-1][M-1]);

    return 0;
}
