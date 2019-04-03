/**
 * 19.3.14.
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int t, n, m, map[50][50], visited[50][50], sol;
queue<pair<int, int>> q;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

void dfs(pair<int, int> point)
{
    int row = point.first;
    int col = point.second;
    for (int i=0; i<4; i++)
    {
        int _row = row+dir[i][0];
        int _col = col+dir[i][1];
        if (!chk(_row, _col)) continue;
        if (!map[_row][_col]) continue;
        if (visited[_row][_col]) continue;
        visited[_row][_col] = 1;
        dfs(make_pair(_row, _col));
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case=0, k; test_case<t; test_case++)
    {
        scanf("%d%d%d", &m, &n, &k);
        sol = 0;
        for (int row=0; row<n; row++) for (int col=0; col<m; col++) {map[row][col] = 0;visited[row][col] = 0;}
        for (int i=0, row, col; i<k; i++)
        {
            scanf("%d%d", &col, &row);
            map[row][col] = 1;
            q.push(make_pair(row, col));
        }

        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            if (visited[f.first][f.second]) continue;
            visited[f.first][f.second] = 1;
            dfs(f);
            sol++;
            // printf("sol++\t%d\t%d\n", f.first, f.second);
        }
        printf("%d\n", sol);
    }
    return 0;
}
