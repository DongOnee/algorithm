#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
char map[50][51];
bool visited[50][50];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int bfs(int start_r, int start_c)
{
    queue<pii> qu;
    qu.push({start_r, start_c});
    memset(visited, false, sizeof(visited));
    visited[start_r][start_c] = true;

    int times = 0;
    while (!qu.empty())
    {
        long sz = qu.size();
        times++;
        while (sz--)
        {
            pii f = qu.front(); qu.pop();
            for (int i=0; i<4; i++)
            {
                int next_r = f.first + dir[i][0];
                int next_c = f.second + dir[i][1];

                if (!chk(next_r, next_c)) continue;
                if (map[next_r][next_c] == 'W') continue; 
                if (visited[next_r][next_c]) continue;
                visited[next_r][next_c] = true;
                
                qu.push({next_r, next_c});
            }
        }
    }
    return times -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%s", map[i]);

    int ans = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (map[i][j] == 'L') ans = max(ans, bfs(i, j));

    printf("%d\n", ans);
    
    return 0;
}
