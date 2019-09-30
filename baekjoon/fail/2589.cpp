#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m;
char map[50][51];
bool visited[50][50];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

vector<vector<pipii>> lands;
int cnt_lands;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int bfs(int start_r, int start_c, bool flag)
{
    queue<pii> qu;
    qu.push({start_r, start_c});
    visited[start_r][start_c] = flag;
    if(flag)
    {
        lands.push_back(vector<pipii>());
        lands[cnt_lands].push_back({0, {start_r, start_c}});
    }

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
                if (visited[next_r][next_c] == flag) continue;
                visited[next_r][next_c] = flag;
                
                qu.push({next_r, next_c});
                if(flag) lands[cnt_lands].push_back({times, {next_r, next_c}});
            }
        }
    }
    if(flag) cnt_lands++;
    return times -1;
}

int bfs2(pii x) { return bfs(x.first, x.second, false); }

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%s", map[i]);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (map[i][j] == 'L' && !visited[i][j]) bfs(i, j, true);

    for (int i=0; i<cnt_lands; i++) sort(lands[i].begin(), lands[i].end(), greater<pipii>());

    int ans = 0;
    for (vector<pipii> x : lands)
    {
        int maxVal = x[0].first;
        for (pipii xx : x)
        {
            if (xx.first < maxVal) break;
            ans = max(ans, bfs2(xx.second));
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
