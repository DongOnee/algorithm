/**
 * 19.4.9. 17:24 ~ 36 / 중단 40 ~ 43 / 중단 / 19:20 ~ 19:42
 */
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, map[9][9];
int sol;
vector<pair<int, int>> virus;
int cpmap[9][9];
bool visited[9][9];

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

void dfs2(int row, int col)
{
    visited[row][col] = true;
    for (int i=0; i<4; i++)
    {
        int rows = row+dir[i][0];
        int cols = col+dir[i][1];
        if (!chk(rows, cols)) continue;
        if (visited[rows][cols]) continue;
        if (cpmap[rows][cols] == 0)
        {
            cpmap[rows][cols] = 2;
            dfs2(rows, cols);
        }
    }
}

void dfs(int row, int col, int cnt)
{
    if (cnt == 3)
    {
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) 
        {
            cpmap[i][j] = map[i][j];
            visited[i][j] = false;
        }
        for (auto x: virus)
        {
            int rows = x.first;
            int cols = x.second;
            if (visited[rows][cols]) continue;
            dfs2(rows, cols);
        }
        int ret = 0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) ret += (cpmap[i][j]==0?1:0);
        sol = max(sol, ret);
        return;
    }
    for (int i=row, jj = col; i<n; i++, jj=0)
    {
        for (int j=jj; j<m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                dfs(row, col+1, cnt+1);
                map[i][j] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        scanf("%d", map[i]+j);
        if (map[i][j] == 2) virus.push_back({i, j});
    } 
    sol = 0;
    dfs(0, 0, 0);
    printf("%d\n", sol);
    return 0;
}
