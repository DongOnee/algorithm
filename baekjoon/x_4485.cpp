/**
 * 19.2.11.
 * DFS를 이용해서 완전 탐색을 실시 해보았다.
 * 시간초과...
 */
#include <cstdio>

int N;
int min_luffy;
int map[125][125];
bool visited[125][125];

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<N; }

void dfs(int row, int col, int luffys)
{
    luffys += map[row][col];
    if (luffys >= min_luffy) return;

    if (row == N-1 && col == N-1)
    {
        min_luffy = (min_luffy < luffys ? min_luffy : luffys);
        return;
    }

    visited[row][col] = true;

    for (int i=0; i<4; i++)
    {
        int next_row = row+dir[i][0];
        int next_col = col+dir[i][1];
        if ( chk(next_row, next_col) )
            if (!visited[next_row][next_col])
                dfs(next_row, next_col, luffys);
    }
    visited[row][col] = false;
}


int main(int argc, char const *argv[])
{
    int i=0;
    while(++i)
    {
        scanf("%d", &N);
        if (N == 0) return 0;

        min_luffy = 1e9;
        for (int i=0; i<N; i++) for (int j=0; j<N; j++) 
        {
            scanf("%d", &map[i][j]);
            visited[i][j] = false;
        }
        dfs(0, 0, 0);

        printf("Problem %d: %d\n", i, min_luffy);
    }
    return 0;
}