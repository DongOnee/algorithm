/**
 * 19.06.27. 08:06 ~
 */
#include <cstdio>
#include <vector>
using namespace std;

int m, n;
char map[102][102];
int cnt[101][101];
int dir[4][2] = { { 0, 1 }, { 0 , -1 }, { 1, 0 }, { -1, 0 } };
vector<pair<int, int>>dir2 = { { 0, 1 }, { 1, 0 }, { 0 , -1 }, { -1, 0 } };

bool chk(int row, int col) { return 0<row&&row<=n&&0<col&&col<=m; }

void dfs(int row, int col)
{
    if (row == n && col == m) return;
    for ( pair<int, int> x : dir2)
    {
        int next_row = row + x.first;
        int next_col = col + x.second;
        if (!chk(next_row, next_col)) continue;
        if (cnt[next_row][next_col] <= cnt[row][col]) continue;

        bool is_wall = false;
        if (map[next_row][next_col] == '0') cnt[next_row][next_col] = cnt[row][col];
        else
        {
            cnt[next_row][next_col] = cnt[row][col] +1;
            is_wall = true;
            map[next_row][next_col] = '0';
        }
        // printf("dfs[%d][%d]:%d\t", next_row, next_col, cnt[next_row][next_col]);
        dfs(next_row, next_col);
        if (is_wall) map[next_row][next_col] = '1';
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &m, &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", map[i]);
        for (int j=1; j<=m; j++) cnt[i][j] = 100001;
    } 

    cnt[1][1] = 0;
    dfs(1, 1);
    
    printf("%d\n", cnt[n][m]);

    return 0;
}
