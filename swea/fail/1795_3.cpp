/**
 * 19.7.3. 21:41 ~
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321

int main(int argc, char const *argv[])
{
    freopen("input_1795.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int tc=1, n, m, l; tc<=T; tc++)
    {
        scanf("%d%d%d", &n, &m, &l);
        vector<int> x_from[1001], x_to[1001];
        int ans = 0, map[1001][1001];
        for (int i=0; i<1001; i++) 
        {
            for (int j=0; j<1001; j++) map[i][j] = INF;
            map[i][i] = 0;
        }

        for (int i=0, a, b, c; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            x_from[a].push_back(b);
            x_to[b].push_back(a);
            map[a][b] = c;
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, l}); // time to l;
        while (!pq.empty())
        {// from cur to l
            pair<int, int> tp = pq.top(); pq.pop();
            int dist = -tp.first;
            int cur = tp.second;
            if (map[cur][0] <= dist) continue;
            map[cur][0] = dist;
            for (int i=0; i<x_to[cur].size(); i++)
            {
                int x = x_to[cur][i];
                if (map[x][cur] + map[cur][0] >= map[x][0]) continue;
                pq.push({-(map[x][cur] + map[cur][0]), x});
            }
        }

        // printf("=========\n");

        priority_queue<pair<int, int>> pq2;
        pq2.push({0, l}); // time from l;
        while (!pq2.empty())
        {// from l to cur
            pair<int, int> tp = pq2.top(); pq2.pop();
            int dist = -tp.first;
            int cur = tp.second;
            if (map[0][cur] <= dist) continue;
            map[0][cur] = dist;
            for (int i=0; i<x_from[cur].size(); i++)
            {
                int x = x_from[cur][i];
                if (map[0][cur] + map[cur][x] >= map[0][x]) continue;
                pq2.push({-(map[0][cur] + map[cur][x]), x});
            }
        }

        for (int i=1; i<=n; i++) ans = max(ans, map[i][0]+map[0][i]);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
