#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

int n, minHeight = INF;
int map[100][100];
int visited[100][100];
queue<pii> tmpQu;

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void bfs(pii point, int visit, int curh)
{
    queue<pii> qu;
    qu.push(point);
    visited[point.first][point.second] = visit;
    tmpQu.push(point);
    
    while (!qu.empty())
    {
        pii f = qu.front(); qu.pop();
        minHeight = min(minHeight, map[f.first][f.second]);
        for (int i=0; i<4; i++)
        {
            pii np = {f.first+dir[i][0], f.second+dir[i][1]};
            if (!(0<=np.first&&np.first<n&&0<=np.second&&np.second<n)) continue;
            if (map[np.first][np.second] <= curh) map[np.first][np.second] = -1;
            else if (visited[np.first][np.second] == -1)
            {
                visited[np.first][np.second] = visit;
                qu.push(np);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    {
        scanf("%d", map[i] + j);
        tmpQu.push({i, j});
        minHeight = min(minHeight, map[i][j]);
    }

    int ans = 1;
    while (!tmpQu.empty())
    {
        int curHeight = minHeight;
        int curAns = 0;
        minHeight = INF;
        queue<pii> qu; qu.swap(tmpQu);
        memset(visited, -1, sizeof(visited));

        while(!qu.empty())
        {
            pii f = qu.front(); qu.pop();

            if (map[f.first][f.second] <= curHeight) map[f.first][f.second] = -1;
            else if (visited[f.first][f.second] != -1) tmpQu.push(f);
            else bfs(f, curAns++, curHeight);
        }
        ans = max(ans, curAns);
    }

    printf("%d\n", ans);

    return 0;
}
