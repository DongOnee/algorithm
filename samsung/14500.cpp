/**
 * 19.4.9. 13:41~14:09
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, map[501][501], sol;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int calc(int row, int col)
{
    int ret = sol;
    if (chk(row, col+3)) ret = max(ret, map[row][col] + map[row][col+1] + map[row][col+2] + map[row][col+3]);
    if (chk(row+3, col)) ret = max(ret, map[row][col] + map[row+1][col] + map[row+2][col] + map[row+3][col]);
    if (chk(row+1, col+1)) ret = max(ret, map[row][col] + map[row+1][col] + map[row+1][col+1] + map[row][col+1]);
    if (chk(row+2, col+1))
    {
        ret = max(ret, map[row][col] + map[row+1][col] + map[row+2][col] + map[row+2][col+1]);
        ret = max(ret, map[row][col] + map[row+1][col] + map[row+2][col] + map[row][col+1]);
        ret = max(ret, map[row][col] + map[row][col+1] + map[row+1][col+1] + map[row+2][col+1]);
        ret = max(ret, map[row][col+1] + map[row+1][col+1] + map[row+2][col+1] + map[row+2][col]);
     
        ret = max(ret, map[row][col] + map[row+1][col] + map[row+1][col+1] + map[row+2][col+1]);
        ret = max(ret, map[row][col+1] + map[row+1][col] + map[row+1][col+1] + map[row+2][col]);
        
        ret = max(ret, map[row][col] + map[row+1][col] + map[row+2][col] + map[row+1][col+1]);
        ret = max(ret, map[row][col+1] + map[row+1][col+1] + map[row+2][col+1] + map[row+1][col]);
    }
    if (chk(row+1, col+2))
    {
        ret = max(ret, map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col+2]);
        ret = max(ret, map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col]);
        ret = max(ret, map[row+1][col] + map[row+1][col+1] + map[row+1][col+2] + map[row][col]);
        ret = max(ret, map[row+1][col] + map[row+1][col+1] + map[row+1][col+2] + map[row][col+2]);
     
        ret = max(ret, map[row][col+1] + map[row+1][col+1] + map[row][col] + map[row+1][col+2]);
        ret = max(ret, map[row][col+1] + map[row+1][col+1] + map[row+1][col] + map[row][col+2]);
        
        ret = max(ret, map[row][col] + map[row][col+1] + map[row][col+2] + map[row+1][col+1]);
        ret = max(ret, map[row+1][col] + map[row+1][col+1] + map[row+1][col+2] + map[row][col+1]);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int row=0; row<n; row++) for (int col=0; col<m; col++) scanf("%d", map[row]+col);

    sol = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) sol = calc(i, j);
    printf("%d\n", sol);
    return 0;
}
