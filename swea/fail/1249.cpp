#include <cstdio>
#include <cstring>
#define INF 987654321

int map[100][100], n;
bool visit[100][100];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int ans;

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void dfs(int r, int c, int sum)
{
    if (r == n-1 && c == n-1)
    {
        ans = ans<sum?ans:sum;
        return;
    }
    for (int i=0; i<4; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (!chk(nr, nc)) continue;
        if (visit[nr][nc]) continue;
        visit[nr][nc] = true;
        if (ans > sum+map[r][c]) dfs(nr, nc, sum+map[r][c]);
        visit[nr][nc] = false;
    }
}

int main(int argc, char const *argv[])
{
    freopen("1249_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        scanf("%d", &n);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++)
        {
            scanf("%1d", map[i]+j);
            visit[i][j] = false;
        }
        ans = INF;

        dfs(0, 0, 0);

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
