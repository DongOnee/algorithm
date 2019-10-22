#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 8

struct pp
{
    pair<int, int> pt;
    int val;
    bool chance;
    pp(pair<int, int> p, int v, bool c) : pt(p), val(v), chance(c) {};
};


int n, k, map[MAXN][MAXN], answer, max_height;
bool visited[MAXN][MAXN][2];
int dp[MAXN][MAXN][2];
int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

vector<pair<int, int>> points[21];

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void bfs()
{
    for (auto hi_points : points[max_height])
    {
        memset(visited, false, sizeof(visited));
        // if (dp[hi_points.first][hi_points.second][true] > 0) continue;
        // dp[hi_points.first][hi_points.second][true] = 1;
        visited[hi_points.first][hi_points.second][true] = true;
        queue<struct pp> qu;
        struct pp f(hi_points, map[hi_points.first][hi_points.second], true);
        qu.push(f);
        int step = 0;
        while (!qu.empty())
        {
            long sz = qu.size();
            step++;
            printf("\nstep : %d\n", step);
            while (sz--)
            {
                struct pp f = qu.front(); qu.pop();
                printf("%d ", f.val); 
                if (f.pt.first == 4 && f.pt.second == 2) printf("here ");
                for (int di = 0; di<4; di++)
                {
                    int nr = f.pt.first + dir[di][0];
                    int nc = f.pt.second + dir[di][1];
                    if (!chk(nr, nc)) continue;
                    // if (dp[nr][nc][f.chance] >= step) continue;
                    if (visited[nr][nc][f.chance]) continue;
                    if (map[nr][nc] >= f.val) 
                    {
                        if (f.chance && f.val > map[nr][nc] - k)
                        {
                            qu.push({{nr, nc}, f.val-1, false});
                            visited[nr][nc][false] = true;
                            // dp[nr][nc][false] = step;
                        }
                        else continue;
                    }
                    else
                    {
                        qu.push({{nr, nc}, map[nr][nc], f.chance});
                        visited[nr][nc][f.chance] = true;
                        // dp[nr][nc][f.chance] = step;
                    }
                }
            }
        }
        answer = max(answer, step);
    }
}

int main(int argc, char const *argv[])
{
    freopen("1949_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        answer = 0, max_height = 0;
        scanf("%d%d", &n, &k);
        for (int i=1; i<21; i++) points[i].clear();
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) 
        {
            scanf("%d", map[i]+j);
            max_height = max(max_height, map[i][j]);
            points[map[i][j]].push_back({i, j});
        }
        bfs();

        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}
