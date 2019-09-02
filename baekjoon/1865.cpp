#include <cstdio>
#include <vector>
using namespace std;
#define INF 987654321

typedef pair<int, int> pii;

int n, m, w;
vector<vector<pii>> load_worm;
vector<int> dist;

bool cycle;

int main(int argc, char const *argv[])
{
    int tc; scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d%d%d", &n, &m, &w);
        load_worm.clear(), dist.clear();
        load_worm.resize(n), dist.resize(n);

        for (int i=0; i<n; i++) dist[i] = INF;
        for (int i=0, a, b, c; i<m; i++) 
        {
            scanf("%d%d%d", &a, &b, &c);
            load_worm[a-1].push_back({b-1, c});
            load_worm[b-1].push_back({a-1, c});
        }
        for (int i=0, a, b, c; i<w; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            load_worm[a-1].push_back({b-1, -c});
        }

        dist[0] = 0;
        cycle = false;
        for (int loop_cnt=0; loop_cnt<n; loop_cnt++)
        {
            for (int src=0; src<n; src++)
            {
                for (auto x : load_worm[src])
                {
                    int dest = x.first;
                    int time = x.second;
                    if (dist[src] != INF && dist[dest] > dist[src] + time)
                    {
                        dist[dest] = dist[src] + time;
                        if (loop_cnt == n-1) cycle = true;
                    }
                }
            }
        }

        printf("%s\n", cycle?"YES":"NO");
    }

    return 0;
}
