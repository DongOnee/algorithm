#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, ans;
int map[10][10];
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

void init()
{
    scanf("%d", &n);
    ans=0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i][j] = false;
}

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

int update(const int r, const int c, int p)
{
    int ret = 0;
    for (int di=0; di<8; di++)
    {
        int nr=r+dir[di][0], nc=c+dir[di][1];
        while (chk(nr, nc))
        {
            map[nr][nc] += p;
            nr += dir[di][0];
            nc += dir[di][1];
        }
    }

    return ret;
}

void dfs(int row)
{
    if (row == n) ans++;
    else
    {
        for (int col=0; col<n; col++)
        {
            if (map[row][col] != 0) continue;
            map[row][col] = 1;
            update(row, col, 1);
            dfs(row+1);
            update(row, col, -1);
            map[row][col] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("2806_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        init();

        dfs(0);

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
