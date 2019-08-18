/**
 * 2019.08.05. 21:48 ~ 22:36
 */
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 50

typedef pair<int, int> pii;

int n, m;
char map[MAXN+1][MAXN+1];
bool visited[MAXN][MAXN];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
queue<pii> devils, cur;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int bfs()
{
    int ret = 1, cursz;
    while ((cursz = cur.size()) != 0)
    {
        long devilsz = devils.size();
        while (devilsz--)
        {
            pii f = devils.front(); devils.pop();
            for (int i=0; i<4; i++)
            {
                int nextr = f.first + dir[i][0];
                int nextc = f.second + dir[i][1];
                if (!chk(nextr, nextc)) continue;
                if (map[nextr][nextc] != '.') continue;
                map[nextr][nextc] = '*';
                devils.push({nextr, nextc});
            }
        }
        while (cursz--)
        {
            pii f = cur.front(); cur.pop();
            for (int i=0; i<4; i++)
            {
                int nextr = f.first + dir[i][0];
                int nextc = f.second + dir[i][1];
                if (!chk(nextr, nextc)) continue;
                if (map[nextr][nextc] == 'D') return ret;
                if (map[nextr][nextc] != '.') continue;
                if (visited[nextr][nextc]) continue;
                visited[nextr][nextc] = true;
                cur.push({nextr, nextc});
            }
        }
        ret++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    for (int tc=1, ans; tc<=t; tc++)
    {
        scanf("%d%d", &n, &m);
        queue<pii> tmpq, tmpq2;
        swap(tmpq, devils); swap(tmpq2, cur);
        for (int i=0; i<n; i++)
        {
            scanf("%s", map[i]);
            for (int j=0; j<m; j++)
            {
                visited[i][j] = false;
                if (map[i][j] == '*') devils.push({i, j});
                else if (map[i][j] == 'S')
                {
                    cur.push({i, j});
                    map[i][j] = '.';
                    visited[i][j] = true;
                }
            }
        }
        for (int j=0; j<=m; j++) map[n][j] = NULL;

        if ( (ans = bfs() ) == -1) printf("#%d GAME OVER\n", tc);
        else printf("#%d %d\n", tc, ans); 
    }

    return 0;
}
