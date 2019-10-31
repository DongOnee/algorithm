#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int map[50][50];
int n, m, t;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void update(int sum, int cnt)
{
    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        if (map[i][j] == -1) continue;
        if (map[i][j]*cnt < sum) map[i][j]++;
        else if (sum < map[i][j]*cnt) map[i][j]--;
    }
}

queue<pii> qu;
void search()
{
    int sum = 0, cnt = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) 
    {
        if (map[i][j] == -1) continue;
        sum += map[i][j];
        cnt++;
        for (int k=0; k<4; k++)
        {
            int nr = i+dir[k][0];
            int nc = (j+dir[k][1]+m)%m;
            if (nr < 0 || n <= nr) continue;
            if (map[nr][nc] == map[i][j])
            {
                qu.push({i, j});
                continue;
            }
        }
    }

    if (qu.empty()) update(sum, cnt);
    else
    {
        while (!qu.empty())
        {
            pii f = qu.front(); qu.pop();
            map[f.first][f.second] = -1;
        }
    }
}

int tmp[50];
void turn(int idx, int d, int k)
{
    for (int j=0; j<m; j++) tmp[j] = map[idx][j];
    for (int j=0; j<m; j++) map[idx][j] = tmp[(j + m + (d?1:-1)*k)%m];
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);
    for (int i=0, x, d, k; i<t; i++)
    {
        scanf("%d%d%d", &x, &d, &k);
        int xx = x-1;
        while (xx < n)
        {
            turn(xx, d, k);
            xx += x;
        }
        search();
    }

    int ans = 0;
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++) 
        {
            // printf("%2d ", map[i][j]);
            ans+=(map[i][j]==-1?0:map[i][j]);
        }
        // printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}
