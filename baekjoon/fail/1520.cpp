#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 502
#define INF 10001

int n, m, map[MAXN][MAXN], ans;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int dp[2][MAXN];
bool toggle;

void run()
{
    for (int row = n-1; 0<row; row--)
    {
        // for (int c = 1; c <= m; c++) printf("%d ", dp[toggle][c]);
        // printf("\n");
        for (int stCol = 1; stCol<=m; stCol++)
        {
            for (int edCol = stCol; 0 < edCol; edCol--)
            {
                if (map[row][edCol] > map[row+1][edCol]) dp[!toggle][stCol] += dp[toggle][edCol];
                if (map[row][edCol-1] >= map[row][edCol]) break;
            }
            for (int edCol = stCol+1; edCol <= m; edCol++)
            {
                if (map[row][edCol-1] <= map[row][edCol]) break;
                if (map[row][edCol] > map[row+1][edCol]) dp[!toggle][stCol] += dp[toggle][edCol];
            }
        }
        for (int j = 1; j<=m; j++) dp[toggle][j] = 0;
        toggle ^= true;
    }
}

void init()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=m; j++) scanf("%d", map[i]+j);
        map[i][0] = INF;
        map[i][m+1] = INF;
    }
    for (int j=1; j<=m; j++)
    {
        map[0][j] = INF;
        map[n+1][j] = INF;
    }
    for (int j=m; 0<j; j--)
    {
        dp[toggle][j] = 1;
        if (map[n][j-1] <= map[n][j]) break;
    }
}

int main(int argc, char const *argv[])
{
    init();
    run();

    printf("%d\n", dp[toggle][1]);

    return 0;
}


/*
50 45 37 32 30  1 1 1 1 1
35 50 40 20 25  1 0 0 2 1
30 30 25 17 28  1 0 0 2 0
27 24 22 15 10  1 1 1 3 3
*/