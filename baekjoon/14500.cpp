/**
 * 18.12.3. 월요일 ~ 18.12.4. 화요일
 * 와진짜 완전 DFS + 브루트 포스 인데 ... 이거좀 이상하다.
 */
#include <cstdio>

int N, M;
int map[500][500];
bool visited[500][500];
int max_ret;

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<M; }

void dfs(int row, int col, int cnt, int val) {
    visited[row][col] = true;
    for (int i=0; i<4; i++)
    {
        int _row = row + dir[i][0];
        int _col = col + dir[i][1];
        if (!chk(_row, _col)) continue;
        if (visited[_row][_col]) continue;
        if (cnt==3)
        {
            if (max_ret < val + map[_row][_col]) max_ret = val + map[_row][_col];
            continue;
        }
        dfs(_row, _col, cnt+1, val+map[_row][_col]);
    }
    visited[row][col] = false;
}

void ex(int row, int col) {
    if (chk(row+1, col+2))
        if (max_ret < map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col+1]) max_ret = map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col+1];
    if (chk(row+1, col-2))
        if (max_ret < map[row][col] + map[row][col-1] + map[row][col-2] + map[row+1][col-1]) max_ret = map[row][col] + map[row][col-1] + map[row][col-2] + map[row+1][col-1];
    if (chk(row-1, col+2))
        if (max_ret < map[row][col] + map[row][col+1] + map[row][col+2] + map[row-1][col+1]) max_ret = map[row][col] + map[row][col+1] + map[row][col+2] + map[row-1][col+1];
    if (chk(row-1, col-2))
        if (max_ret < map[row][col] + map[row][col-1] + map[row][col-2] + map[row-1][col-1]) max_ret = map[row][col] + map[row][col-1] + map[row][col-2] + map[row-1][col-1];
    if (chk(row+2, col+1))
        if (max_ret < map[row][col] + map[row+1][col+1] + map[row+1][col] + map[row+2][col]) max_ret = map[row][col] + map[row+1][col+1] + map[row+1][col] + map[row+2][col];
    if (chk(row+2, col-1))
        if (max_ret < map[row][col] + map[row+1][col-1] + map[row+1][col] + map[row+2][col]) max_ret = map[row][col] + map[row+1][col-1] + map[row+1][col] + map[row+2][col];
    if (chk(row-2, col+1))
        if (max_ret < map[row][col] + map[row-1][col+1] + map[row-1][col] + map[row-2][col]) max_ret = map[row][col] + map[row-1][col+1] + map[row-1][col] + map[row-2][col];
    if (chk(row-2, col-1))
        if (max_ret < map[row][col] + map[row-1][col-1] + map[row-1][col] + map[row-2][col]) max_ret = map[row][col] + map[row-1][col-1] + map[row-1][col] + map[row-2][col];
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int row=0; row<N; row++) for (int col=0; col<M; col++) {scanf("%d", &map[row][col]); visited[row][col]=false;}

    max_ret = 0;
    for (int i=0; i<N; i++) for(int j=0; j<M; j++) {
        dfs(i, j, 1, map[i][j]);
        ex(i, j);
    }
    printf("%d\n", max_ret);

    return 0;
}
