#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int v, e;
vector<pipii> edges;
vector<int> roots, sums;

int findFunc(int idx)
{
    if (roots[idx] == idx) return idx;
    return roots[idx] = findFunc(roots[idx]);
}

void unionFunc(pii edge2edge, int weight)
{
    int rootA = findFunc(edge2edge.first);
    int rootB = findFunc(edge2edge.second);

    if (rootA != rootB)
    {
        roots[rootA] = rootB;
        sums[rootB] += sums[rootA];
        sums[rootB] += weight;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &v, &e);

    for (int i=0; i<=v; i++) roots.push_back(i);
    sums.assign(v+1, 0);
    for (int i=0, a, b, c; i<e; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    for (auto x : edges) unionFunc(x.second, x.first);

    printf("%d\n", sums[findFunc(edges[0].second.first)]);

    return 0;
}
