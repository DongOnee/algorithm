#include <cstdio>
#define MAXN 20
#define MAXM 10

bool map[MAXN][MAXN]; 
int n, m, ans;

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

int calc_home(int r, int c, int k)
{
    int ret = 0, width = 1;
    for (int i=1-k; i<k; i++)
    {
        for (int j=1-width; j<width; j++)
        {
            if (!chk(r+i, c+j)) continue;
            if (map[r+i][c+j]) ret++;
        }
        if (i<0) width++;
        else width--;
    }
    return ret;
}

void init()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0, a; j<n; j++) 
    {
        scanf("%d", &a);
        if (a == 1) map[i][j] = true;
        else map[i][j] = false;
    }
    ans = 0;
}

int main(int argc, char const *argv[])
{
    freopen("2117_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        init();
        for (int k=1; k<=n+1; k++)
        {
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    int cnt = calc_home(i, j, k);
                    int profit = m*cnt - 2*k*k+2*k-1;
                    if (ans < cnt && profit >= 0) ans = cnt;
                }
            }
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
