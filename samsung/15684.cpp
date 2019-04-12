#include <cstdio>
#include <stack>
using namespace std;

int n, m, h, map[32][12], sol;

bool search(int i)
{
    int curRow = 0;
    int curCol = i;
    for (; curRow<n; curRow++)
    {
        if (map[curRow][curCol] == 1) curCol++;
        else if (map[curRow][curCol-1] == 1) curCol--;
    }
    return i == curCol;
}

void dfs(int row, int col, int cnt, int cnt2)
{
    if (cnt == 0)
    {
        bool ret = true;
        for (int i=1; i<=m; i++) if (!search(i)) 
        {
            ret = false;
            break;
        }
        if (ret) sol = cnt2;
        return;
    }
    for (int i=row, jj=col; i<n; i++, jj=1) for (int j=jj; j<m; j++)
    {
        if (map[i][j] == 1 || map[i][j-1] == 1 || map[i][j+1] == 1) continue;
        map[i][j] = 1;
        dfs(i, j+1, cnt-1, cnt2+1);
        map[i][j] = 0;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &m, &h, &n);

    for (int i=0, a, b; i<h; i++)
    {
        scanf("%d %d", &a, &b);
        map[a-1][b] = 1;
    }
    sol = -1;

    for (int i=0; i<4; i++) 
    {
        dfs (0, 1, i, 0);
        if (sol != -1) break;
    }

    printf("%d\n", sol);

    return 0;
}
