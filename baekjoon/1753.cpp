/**
 * 19.2.27.
 */
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <string>
using namespace std;

int V, E;
int start_point;
int dist[20001];

vector<pair<int, int>> loads[20001]; // load[a] = {b, t} : a 에서 b 까지 t 시간
priority_queue<pair<int, int>> pq; // firts 시간에 걸처서 second 에 도착

void dijkstra(int src) // src 는 start_point 에서 가장 빨리 갈수 있는 곳
{
    for (auto a : loads[src]) // src 에서 dest 까지 도달하는데 tm 시간?
    {
        int dest = a.first;
        int tm = a.second;
        if (dist[dest] > tm+dist[src])
        {
            dist[dest] = tm + dist[src];
            pq.push(make_pair(-dist[dest], dest));
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &V, &E, &start_point);

    for (int i=0, a, b, c; i<E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        loads[a].push_back(make_pair(b, c));
    }

    for (int i=1; i<=V; i++) dist[i] = 1e9;

    dist[start_point] = 0;
    pq.push(make_pair(0, start_point));

    while(!pq.empty())
    {
        pair<int, int> tp = pq.top();
        pq.pop();
        int time_ = -tp.first;
        int dest_ = tp.second;
        // printf("dest : %d\ttime : %d\n", dest_, time_);
        if (dist[dest_] < time_) continue;
        dijkstra(dest_);
    }

    for (int i=1; i<=V; i++)
        if (dist[i] == 1e9) printf("INF\n");
        else printf("%d\n", dist[i]);

    return 0;
}
