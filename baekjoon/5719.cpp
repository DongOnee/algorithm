/**
 * 2019.07.08. 13:27 ~ 
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 87654321

int n, m, s, d, map[501][501], dst[501];
vector<int> nears[501];
priority_queue<pair<int ,vector<int>>> pq;
priority_queue<pair<int, int>> pq2;

void dijstra()
{
    priority_queue<pair<int ,vector<int>>> empty_pq;
    swap(pq, empty_pq);

    pq.push({0, {s}});
    dst[s] = 0;
    int ans = MAX;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        vector<int> paths(pq.top().second);
        int cur_point = paths[paths.size()-1];
        pq.pop();

        if (ans < cost) break;
        if (cur_point == d)
        {
            int st = s;
            for (auto x : paths)
            {
                map[st][x] = MAX;
                st = x;
            }
            ans = cost;
            continue;
        }

        for (auto next_point : nears[cur_point])
        {
            int next_cost = cost + map[cur_point][next_point];
            if (next_cost > dst[next_point]) continue;
            dst[next_point] = next_cost;

            vector<int> next_path(paths);
            next_path.push_back(next_point);

            pq.push({-next_cost, next_path});
        }
    }
}

int dijstra2()
{
    for (int i=0; i<n; i++) dst[i] = MAX;

    priority_queue<pair<int, int>> pq2_empty; swap(pq2, pq2_empty);
    pq2.push({0, s});
    dst[s] = 0;
    while (!pq2.empty())
    {
        int cost = -pq2.top().first;
        int cur = pq2.top().second;
        pq2.pop();

        if (cur == d) return cost;
        for (auto next_ : nears[cur])
        {
            int next_cost = cost + map[cur][next_];
            if (dst[next_] <= next_cost) continue;
            dst[next_] = next_cost;
            pq2.push({-next_cost, next_});
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    while (1)
    {
        scanf("%d%d", &n, &m);
        if (n ==0 && m==0) break;
        for (int i=0; i<n; i++) 
        {
            for (int j=0; j<n; j++) map[i][j] = MAX;
            map[i][i] = 0;
            dst[i] = MAX;
            nears[i].clear();
        }
        scanf("%d%d", &s, &d);
        for (int i=0, u, v, p; i<m; i++)
        {
            scanf("%d%d%d", &u, &v, &p);
            map[u][v] = p;
            nears[u].push_back(v);
        }

        // puts("BEFORE----------------");
        // for (int i=0; i<n ;i++)
        // {
        //     for(int j=0; j<n; j++) printf("%10d ", map[i][j]);
        //     puts("");
        // }

        dijstra();
        
        // puts("AFTER----------------");
        // for (int i=0; i<n ;i++)
        // {
        //     for(int j=0; j<n; j++) printf("%10d ", map[i][j]);
        //     puts("");
        // }

        printf("%d\n", dijstra2());
    }

    return 0;
}
