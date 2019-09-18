#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> map;
vector<bool> visited;

int n, idxPoint, ans;

void dfs(int pNode, int src2pNode)
{
    for (auto x : map[pNode])
    {
        if (visited[x.first]) continue;
        visited[x.first] = true;
        if (ans < src2pNode + x.second)
        {
            ans = src2pNode + x.second;
            idxPoint = x.first;
        }
        dfs(x.first, src2pNode + x.second);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    map.assign(n, vector<pii>());
    for (int i=0, a, b, c; i<n-1; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        map[a-1].push_back({b-1, c});
        map[b-1].push_back({a-1, c});
    }

    visited.resize(n);
    visited[idxPoint] = true;
    dfs(idxPoint, 0);

    visited.assign(n, false);
    visited[idxPoint] = true;
    dfs(idxPoint, 0);

    printf("%d\n", ans);
    return 0;
}
