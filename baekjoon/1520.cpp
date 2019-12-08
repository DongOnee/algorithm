#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 502
#define INF 10001

int n, m, map[MAXN][MAXN], ans, dp[MAXN][MAXN];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<m; }

// (0, 0) 에서 (r, c) 까지 가는 경로의 수
int dfs(int r, int c)
{
    if (r == 0 && c == 0) return 1;
    if (dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 0;
    for (int i=0; i<4; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (!chk(nr, nc)) continue;
        if (map[nr][nc] > map[r][c]) dp[r][c] += dfs(nr, nc);
    }
    return dp[r][c];
}

void init()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++) 
        {
            scanf("%d", map[i]+j);
            dp[i][j] = -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    init();

    printf("%d\n", dfs(n-1, m-1));

    return 0;
}


/*
50 45 37 32 30  1 1 1 1 1
35 50 40 20 25  1 0 0 2 1
30 30 25 17 28  1 0 0 2 0
27 24 22 15 10  1 1 1 3 3
*/