/**
 * 19.2.11.
 */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;

int n, m;
int src, des;
int cost[1002][1002]; // cost[A][B] : A 도시에서 B 도시로 가는 버스 요금
bool visited[1002];

void dijkstra(int cur) // cur 도시 : des 도시로 가는 길이 있다.
{
    visited[cur]=true;
    for (int i=1; i<=n; i++)
    {
        if (cost[i][cur] < 1e9) // i 번째 도시는 cur 로 가는 길이 있다.
        {
            if (cost[i][des] > cost[i][cur] + cost[cur][des])
            {
                cost[i][des] = cost[i][cur] + cost[cur][des];
                q.push(i);
            }
            // cost[i][des] = min(cost[i][des], cost[i][cur] + cost[cur][des]);
            // if (!visited[i]) q.push(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) for (int j=1; j<=n; j++) cost[i][j]=1e9;

    for (int i=1; i<=m; i++)
    {
        int tmp;
        scanf("%d %d %d", &src, &des, &tmp);
        cost[src][des] = min(cost[src][des], tmp);
    }
    scanf("%d %d", &src, &des);

    for (int i=1; i<=n; i++) if (cost[i][des] <1e9) q.push(i);
    visited[des] = true;

    while (!q.empty())
    {
        int size_ = q.size();
        while (size_--)
        {
            int f = q.front();
            q.pop();
            dijkstra(f);
        }
    }

    printf("%d\n", cost[src][des]);
    return 0;
}
