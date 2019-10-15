#include <cstdio>
#include <queue>
using namespace std;

int n, m, ans, ans2;
bool map[500][500];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<m; }

void bfs(int r, int c)
{
    queue<pair<int, int>> qu;
    qu.push({r, c});
    map[r][c] = false;
    int cnt =1;
    while (!qu.empty())
    {
        // printf("bfs func\n");
        pair<int, int> f = qu.front();
        qu.pop();
        for (int i=0; i<4; i++)
        {
            int nr = f.first + dir[i][0];
            int nc = f.second + dir[i][1];
            if (!chk(nr, nc)) continue;
            if (!map[nr][nc]) continue;
            map[nr][nc] = false;
            qu.push({nr, nc});
            cnt++;
        }
    }
    ans = ans>cnt?ans:cnt;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (map[i][j]) 
    {
        ans2++;
        bfs(i, j);
    }

    printf("%d\n%d\n", ans2, ans);

    return 0;
}
