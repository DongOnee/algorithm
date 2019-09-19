#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, m;
int counts[32001];
vector<int> nexts[32001];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);

    for (int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        counts[b]++;
        nexts[a].push_back(b);
    }

    queue<int> qu;
    for (int i=1; i<=n; i++) if (counts[i] == 0) qu.push(i);

    while(!qu.empty())
    {
        int f = qu.front(); qu.pop();
        printf("%d ", f);

        if (counts[f] < 1)
        {
            for (int next : nexts[f]) if (--counts[next] == 0) qu.push(next);
        }
    }

    return 0;
}
