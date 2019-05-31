/**
 * 19.4.13. 13:46~16:14
 */
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int t, sol, rock;
int n, m, maxChance;
int map[16][13];
bool visited[16][13];
int sibal[3] ={6, 2, 2};

queue<pair<int, int>> qu;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

void update()
{
    for (int j=0; j<m; j++)
    {
        for (int i=n-1, k=-1; 0<=i; i--)
        {
            visited[i][j] = false;
            if (map[i][j] != 0)
            {
                if (k == -1) continue;
                map[k][j] = map[i][j];
                map[i][j] = 0;
                k--;
            }
            else if (k == -1) k = i;
        }
    }
}

void dfs(int row, int col)
{
    for (int i=0; i<4; i++)
    {
        for (int remain=1; remain<map[row][col]; remain++)
        {
            int nextRow = row + remain*dir[i][0];
            int nextCol = col + remain*dir[i][1];
            if (!chk(nextRow, nextCol)) continue;
            if (map[nextRow][nextCol]==0) continue;
            if (visited[nextRow][nextCol]) continue;

            visited[nextRow][nextCol] = true;
            qu.push({nextRow, nextCol});
            if (map[nextRow][nextCol]>1) dfs(nextRow, nextCol);
        }
    }
}

void shoot(int target, int chance, int remain)
{
    if (chance == 0 || remain == 0)
    {
        sol = min(sol, remain);
        return;
    }

    int ccpmap[n][m];
    bool ccpvisit[n][m];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) ccpmap[i][j] = map[i][j];

    for (int i=0; i<n; i++)
        if (map[i][target] != 0)
        {
            qu.push({i, target});
            visited[i][target] = true;
            dfs(i, target);
            remain -= qu.size();
            while (!qu.empty())
            {
                pair<int, int> f = qu.front(); qu.pop();
                map[f.first][f.second] = 0;
            }
            break;
        }

    update();

    for (int j=0; j<m; j++) shoot(j, chance-1, remain);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) map[i][j] = ccpmap[i][j];
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int tc=1; tc<=t; tc++)
    {
        sol = 987654321, rock=0;
        scanf("%d %d %d", &maxChance, &m, &n);
        
        for (int i=0; i<n; i++)
        {
            for (int j=0, tmp; j<m; j++)
            {
                scanf("%d", &tmp);
                map[i][j] = tmp;
                if (tmp != 0) rock++;
            }
        }

        for (int j=0; j<m; j++) shoot(j, maxChance, rock);
        printf("#%d %d\n", tc, sol);
    }
    return 0;
}
