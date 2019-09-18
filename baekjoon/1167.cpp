#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int,int> pii;

vector<vector<pii>> map;
int n, vertex[2];

pii searchVertex(int start = 0)
{
    int ans = 0;
    int maxValue = 0;

    priority_queue<pii> pq;
    pq.push({0, start});

    vector<int> dist;
    vector<bool> visit;
    dist.assign(n, INF);
    dist[start] = 0;

    while(!pq.empty())
    {
        int idxVertex = pq.top().second;
        int Src2Vertex = -pq.top().first;
        pq.pop();

        if (Src2Vertex < dist[idxVertex]) continue;

        for (auto x : map[idxVertex])
        {
            int idxDest = x.first;
            int Vertex2Dest = x.second;
            int Src2Vertex2Dest = Src2Vertex + Vertex2Dest;
            if (dist[idxDest] <= Src2Vertex2Dest) continue;
            dist[idxDest] = Src2Vertex2Dest;
            pq.push({-dist[idxDest], idxDest});
            if (maxValue < Src2Vertex2Dest)
            {
                ans = idxDest;
                maxValue = Src2Vertex2Dest;
            }
        }
    }

    return {ans, maxValue};
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    map.assign(n, vector<pii>());
    for (int i=0, vertex; i<n; i++)
    {
        scanf("%d", &vertex);
        while (1)
        {
            int endVertex; scanf("%d", &endVertex);
            if (endVertex == -1) break;
            int edge; scanf("%d", &edge);
            map[vertex-1].push_back({endVertex-1, edge});
        }
    }

    pii ret  = searchVertex();
    ret = searchVertex(ret.first);

    printf("%d\n", ret.second);

    return 0;
}
