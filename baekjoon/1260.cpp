#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

void dfs(int point, int** map, int max) {
    if (map[point][0] == 1) return;
    map[point][0] = 1;
    printf("%d ", point);
    for (int i=1; i<max+1; i++)
    {
        if(map[point][i] == 1)
        {
            map[point][i] = 0;
            map[i][point] = 0;
            dfs(i, map, max);
        }
    }
}

queue<int> q;

void bfs(int point, int** map, int max) {
    if (map[point][0] == 1) return;
    for (int i=1; i<max+1; i++)
    {
        if (map[point][i] == 1) 
        {
            q.push(i);
            map[point][i] = 0;
            map[i][point] = 0;
        }
    }
    map[point][0] = 1;
    printf("%d ", point);
}

int main(int argc, char const *argv[])
{
    int N, M, V;
    cin >> N >> M >> V;
    int** map_dfs = new int*[N+1];
    int** map_bfs = new int*[N+1];
    for (int i=1; i<N+1; i++) {
        map_dfs[i] = new int[N+1];
        map_bfs[i] = new int[N+1];
    }

    for (int i=0; i<M; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int i=0; i<2; i++)
        {
            map_dfs[x][y] = 1;
            map_dfs[y][x] = 1;
            map_bfs[x][y] = 1;
            map_bfs[y][x] = 1;
        }
    }
    dfs(V, map_dfs, N);
    puts("");
    bfs(V, map_bfs, N);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        bfs(tmp, map_bfs, N);
    }

    return 0;
}
