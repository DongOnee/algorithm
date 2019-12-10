#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 13
#define MAXW 20

int n, m, k, answer;
bool map[MAXN][MAXW], mmap[MAXN][MAXW];

bool chk_col(const int col)
{
    int cnt = 1;
    bool cell = mmap[0][col];
    for (int row=1; row<n && k-cnt<=n-row; row++)
    {
        if (cell == mmap[row][col])
        {
            if (++cnt == k) return true;
        }
        else 
        {
            cnt = 1;
            cell = mmap[row][col];
        }
    }
    return false;
}

bool chkmap()
{
    for (int col=0; col<m; col++) if (!chk_col(col)) return false;
    return true;
}

void init()
{
    memset(map, false, sizeof(map));
    answer = MAXN;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) 
    {
        cin >> map[i][j];
        mmap[i][j] = map[i][j];
    }
}

void swapcells(int row, bool val)
{
    for (int col=0; col<m; col++) mmap[row][col] = val;
}

void swapcells(int row)
{
    for (int col=0; col<m; col++) mmap[row][col] = map[row][col];
}

void dfs(int idx, int cnt)
{
    if (chkmap()) answer = cnt;
    if (answer <= cnt || k < cnt) return;
    for (int row=idx; row<n; row++)
    {
        swapcells(row, false);
        dfs(row+1, cnt+1);
        swapcells(row, true);
        dfs(row+1, cnt+1);
        swapcells(row);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("2112_input.txt", "r", stdin);
    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        if (k == 1) answer = 0;
        else dfs(0, 0);
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}

