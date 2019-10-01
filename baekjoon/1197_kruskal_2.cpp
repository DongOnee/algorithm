#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXE 100001
#define MAXV 10001

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int v, e;
pipii edges[MAXE];
int roots[MAXV], sums[MAXV];

int findFunc(int idx)
{
    if (roots[idx] == 0) return idx;
    return roots[idx] = findFunc(roots[idx]);
}

bool unionFunc(pii edge2edge, int weight)
{
    int rootA = findFunc(edge2edge.first);
    int rootB = findFunc(edge2edge.second);

    if (rootA == rootB) return false;
    roots[rootA] = rootB;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &v, &e);

    for (int i=0, a, b, c; i<e; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        edges[i]={c, {a, b}};
    }

    sort(edges, edges+e);

    int sumVal = 0;
    for (auto x : edges) if (unionFunc(x.second, x.first)) sumVal += x.first;

    printf("%d\n", sumVal);

    return 0;
}
