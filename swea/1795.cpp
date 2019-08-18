/**
 * 19.7.3. 21:41 ~ 09 : 32
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
#define MAX 1001

int ans, map[MAX][MAX];
vector<int> x_from[MAX], x_to[MAX];

void init()
{
    ans = 0;
    for (int i=0; i<MAX; i++)
    {
        for (int j=0; j<MAX; j++) map[i][j] = INF;
        map[i][i] = 0;
        vector<int> tmp[2];
        swap(tmp[0], x_from[i]);
        swap(tmp[1], x_to[i]);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input_1795.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int tc=1, n, m, l; tc<=T; tc++)
    {
        scanf("%d%d%d", &n, &m, &l);
        init();

        for (int i=0, a, b, c; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            x_from[a].push_back(b);
            x_to[b].push_back(a);
            map[a][b] = c;
        }

        priority_queue<pair<int, int>> pq;
        pq.push({0, l}); // time to l;
        int cnt = n;
        while (!pq.empty() && cnt != 0)
        {// from cur to l
            pair<int, int> tp = pq.top(); pq.pop();
            int dist = -tp.first;
            int cur = tp.second;
            if (map[cur][0] < dist) continue;
            map[cur][0] = dist;
            cnt--;
            for (int i=0; i<x_to[cur].size(); i++)
            {
                int prev_ = x_to[cur][i];
                if (map[prev_][cur] + map[cur][0] >= map[prev_][0]) continue;
                map[prev_][0] = map[prev_][cur] + map[cur][0];
                pq.push({-(map[prev_][cur] + map[cur][0]), prev_});
            }
        }

        priority_queue<pair<int, int>> pq2;
        pq2.push({0, l}); // time from l;
        cnt = n;
        while (!pq2.empty() && cnt != 0)
        {// from l to cur
            pair<int, int> tp = pq2.top(); pq2.pop();
            int dist = -tp.first;
            int cur = tp.second;
            if (map[0][cur] < dist) continue;
            map[0][cur] = dist;
            cnt--;
            for (int i=0; i<x_from[cur].size(); i++)
            {
                int next_ = x_from[cur][i];
                if (map[0][cur] + map[cur][next_] >= map[0][next_]) continue;
                map[0][next_] = map[0][cur] + map[cur][next_];
                pq2.push({-(map[0][cur] + map[cur][next_]), next_});
            }
        }

        for (int i=1; i<=n; i++) ans = max(ans, map[i][0] + map[0][i]);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
