#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 40'000
#define MAXM 10'000
#define MAXD 16

typedef pair<int, int> pii;

int n, m;
vector<pii> linked[MAXN+1];
int depth[MAXN+1], parent[MAXN+1][MAXD], dist[MAXN+1];

void dfs(int _idx, int _depth, int _dist)
{
    depth[_idx] = _depth++;
    dist[_idx] = _dist;
    for (auto& nxt : linked[_idx])
    {
        if (!depth[nxt.first])
        {
            dfs(nxt.first, _depth, _dist + nxt.second);
            parent[nxt.first][0] = _idx;
        }
    }
}

int lca(int l, int r)
{
    if (depth[l] > depth[r]) swap(l, r);
    for (int d = MAXD-1; 0<=d; --d)
        if (depth[r] - depth[l] >= (1 << d))
            r = parent[r][d];

    if (l == r) return dist[l];

    for (int d = MAXD-1; 0<=d; --d)
        if (parent[l][d] != parent[r][d])
            l = parent[l][d], r = parent[r][d];

    return dist[parent[l][0]];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=1, a, b, c; i<n; ++i)
    {
        cin >> a >> b >> c;
        linked[a].push_back({b, c});
        linked[b].push_back({a, c});
    }

    dfs(1, 1, 0);

    for (int d=1; d<MAXD; ++d)
        for (int i=1; i<=n; i++)
            parent[i][d] = parent[ parent[i][d-1] ][d-1];

    cin >> m;
    for (int i=0, a, b; i<m; i++)
    {
        cin >> a >> b;
        int dist_p = lca(a, b);
        cout << dist[a] + dist[b] - 2 * dist_p << '\n';
    }

    return 0;
}



/*
7
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
3
1 6
1 4
2 6
*/