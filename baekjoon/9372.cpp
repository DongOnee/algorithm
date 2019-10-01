/**
 * 2019.10.1. 21:28 ~ 21:59
 * Union-Find Algorithm
 */
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

#define MAXN 1001
#define MAXM 10001

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int n, m;
pii airplanes[MAXM];
int idxRoot[MAXN];

void initFunc()
{
    memset(airplanes, 0, sizeof(airplanes));
    memset(idxRoot, 0, sizeof(idxRoot));
}

int findFunc(int idx)
{
    if (idxRoot[idx] == 0) return idx;
    return idxRoot[idx] = findFunc(idxRoot[idx]);
}

bool unionFunc(pii src2dest)
{
    int a = findFunc(src2dest.first);
    int b = findFunc(src2dest.second);

    if (a == b) return false;
    idxRoot[a] = b;
    return true;
}

int main(int argc, char const *argv[])
{
    int cntTestCase; scanf("%d", &cntTestCase);
    while (cntTestCase--)
    {
        scanf("%d%d", &n, &m);
        initFunc();
        int ans = 0;
        for (int i=0, a, b; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            if (unionFunc({a, b})) ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
