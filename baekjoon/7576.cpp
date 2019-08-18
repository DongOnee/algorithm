/**
 * BFS
*/

#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int** map;
queue<pair<int, int> > q;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}};

void bfs(pair<int, int> front, int N, int M) {
    for(int i=0; i<4; i++)
    {
        int next_f = front.first + dir[i][0];
        int next_s = front.second + dir[i][1];
        if (-1<next_f && next_f <N && -1<next_s && next_s <M) 
            if(map[next_f][next_s] == 0) {
                q.push(make_pair(next_f, next_s));
                map[next_f][next_s] = map[front.first][front.second]+1;
            }
    }
}

int main(void) {
    int N, M, count=0;
    scanf("%d %d", &M, &N);
    map = new int*[N];
    for(int row=0; row<N; row++)
    {
        *(map + row) = new int[M];
        for(int col=0; col<M; col++)
        {
            int tmp;
            scanf("%d", &tmp);
            map[row][col] = tmp;
            if (tmp == 1) q.push(make_pair(row, col));
        }
    }
    while(!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        bfs(front, N, M);
    }
    for (int row=0; row<N; row++) 
        for(int col=0; col<M; col++) {
            if (map[row][col] == 0) {
                count = 0;
                row = N;
                break;
            } if (map[row][col] > count) count = map[row][col];
        }
    printf("%d\n", count-1);
    return 0;
}