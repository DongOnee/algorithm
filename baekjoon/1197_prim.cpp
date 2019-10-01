#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int v, e;
vector<vector<pii>> map;
vector<bool> visited;
vector<int> connected;
priority_queue<pii> pq;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &v, &e);
    map.resize(v);
    visited.assign(v, false);
    pair<int, pair<int, int>> start_edge = {1000001, {0, 0}};
    for (int i=0, a, b, c; i<e; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if (c < start_edge.first) start_edge = {c, {a-1, b-1}};
        map[a-1].push_back({b-1, c});
        map[b-1].push_back({a-1, c});
    }

    int ans = start_edge.first, cntVisited = 2;
    visited[start_edge.second.first] = true;
    visited[start_edge.second.second] = true;
    for (auto x : map[start_edge.second.first]) if (!visited[x.first]) pq.push({-x.second, x.first});
    for (auto x : map[start_edge.second.second]) if (!visited[x.first]) pq.push({-x.second, x.first});

    while (cntVisited < v)
    {
        pii tp = pq.top(); pq.pop();
        if (visited[tp.second]) continue;
        visited[tp.second] = true;
        ans -= tp.first;
        cntVisited++;
        for (auto x : map[tp.second]) if (!visited[x.first]) pq.push({-x.second, x.first});
    }

    // 시간초과
    // connected.push_back(start_edge.second.first);
    // connected.push_back(start_edge.second.second);

    // while (connected.size() < v)
    // {
    //     start_edge.first = 1000001;
    //     for (int startV : connected)
    //     {
    //         for (pii edge : map[startV])
    //         {
    //             int endV = edge.first;
    //             int weight = edge.second;
    //             if (visited[endV]) continue;
    //             if (weight < start_edge.first)
    //             {
    //                 start_edge.first = weight;
    //                 start_edge.second.first = startV;
    //                 start_edge.second.second = endV;
    //             }
    //         }
    //     }
    //     ans += start_edge.first;
    //     connected.push_back(start_edge.second.second);
    //     visited[start_edge.second.second] = true;
    // }

    printf("%d\n", ans);

    return 0;
}
