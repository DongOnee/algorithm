/**
 * 2019.06.27. 17:17 ~ 18:43
 */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[101][102];
int cnt[101][101];
priority_queue<pair<int, pair<int, int>>> pq;

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<row&&row<=n&&0<col&&col<=m; }

int main(int argc, char const *argv[])
{
    scanf("%d%d", &m, &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%s", map[i]+1);
        for (int j=1; j<=m; j++) cnt[i][j] = 100001;
    }

    pq.push({0, {1, 1}});
    cnt[1][1] = 0;
    while (!pq.empty())
    {
        long sz = pq.size();
        while (sz--)
        {
            int wall_broken = -pq.top().first;
            int cur_row = pq.top().second.first;
            int cur_col = pq.top().second.second;
            pq.pop();
            for (int i=0; i<4; i++)
            {
                int next_row = cur_row + dir[i][0];
                int next_col = cur_col + dir[i][1];
                if (!chk(next_row, next_col)) continue;
                int next_broken = wall_broken;
                if (map[next_row][next_col] == '1') next_broken++;
                if (cnt[next_row][next_col] <= next_broken) continue;
                cnt[next_row][next_col] = next_broken;
                if (next_row == n && next_col == m)
                {
                    priority_queue<pair<int, pair<int, int>>> empty_pq;
                    swap(pq, empty_pq);
                    sz = 0;
                    break;
                }
                pq.push({-next_broken, {next_row, next_col}});
            }
        }
    }

    printf("%d\n", cnt[n][m]);

    return 0;
}
