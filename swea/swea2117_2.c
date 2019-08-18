#include <stdio.h>
#include <stdbool.h>
 
#define N 20
#define MAX(a,b) ((a>b)?(a):(b))
 
int n, m;
int map[N][N];
int price[N + 2];
 
bool is_range(int x, int y) { return (0 <= x && x < n) && (0 <= y && y < n); }
 
int check(int x, int y, int k)
{
    int cnt = 0;
    int nexty;
    int endp;
 
    for (int i = 1; i <= k - 1; i++)
    {
        int up_nextx = x - k + i;
        int down_nextx = x + k - i;
 
        endp = i * 2 - 1;
        nexty = y - endp / 2;
 
        for(int j = 0; j < endp; j++)
        {
            if (is_range(up_nextx, nexty + j) && map[up_nextx][nexty + j] == 1)
                cnt++;
            if (is_range(down_nextx, nexty + j) && map[down_nextx][nexty + j] == 1)
                cnt++;
 
        }
    }
    endp = k * 2 - 1;
    nexty = y- endp / 2;
    for (int i = 0; i < endp; i++)
        if (is_range(x, nexty + i) && map[x][nexty + i] == 1)
            cnt++;
    if (m*cnt - price[k] >= 0)
        return cnt;
    return 0;
 
}
 
 
int main()
{
    int T;
    scanf("%d", &T);
 
    price[1] = 1;
    for (int i = 1; i < N + 1; i++)
    {
        price[i + 1] = (price[i + 1] == 0) ? price[i] + 4 * i : price[i + 1];
    }
    for (int tc = 1; tc <= T; tc++)
    {
        int ans = 0;
        scanf("%d %d", &n,&m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k <= n + 1; k++)
                {
                    ans = MAX(ans, check(i, j, k));
                }
            }
        }
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}