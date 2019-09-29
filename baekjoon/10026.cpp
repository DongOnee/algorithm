/**
 * 2019.09.26. 15:04 ~ 16:09
 */
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> pii;

char map[100][101];
bool visited[100][100];
int n, ans1, ans2;
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

void bfs(int start_r, int start_c)
{
    char curSection = map[start_r][start_c];
    map[start_r][start_c] = '0';

    queue<pii> qu, qu2;
    qu.push({start_r, start_c});

    memset(visited, false, sizeof(visited));
    visited[start_r][start_c] = true;
    ans1++;

    while (!qu.empty())
    {
        pii f = qu.front(); qu.pop();
        for (int i=0; i<4; i++)
        {
            int next_r = f.first + dir[i][0];
            int next_c = f.second + dir[i][1];


            if (!chk(next_r, next_c)) continue;
            if (visited[next_r][next_c]) continue;
            visited[next_r][next_c] = true;
            if (map[next_r][next_c] == curSection)
            {
                map[next_r][next_c] = '0';
                qu.push({next_r, next_c});
            }
            else if ((curSection == 'R' && map[next_r][next_c] == 'G') || (curSection == 'G' && map[next_r][next_c] == 'R')) qu2.push({next_r, next_c});
        }
    }

    while (!qu2.empty())
    {
        pii f = qu2.front(); qu2.pop();
        if (map[f.first][f.second] != '0')
        {
            ans2++;
            bfs(f.first, f.second);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%s", map+i);

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) if(map[i][j] != '0') bfs(i, j);

    printf("%d %d\n", ans1, ans1-ans2);

    return 0;
}