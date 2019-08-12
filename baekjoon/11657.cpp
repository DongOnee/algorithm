/**
 * 2019.07.10. 07:57 ~ 09:57
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 501
#define MAXM 6001
#define INF 987654321

int n, m, dst[MAXN], visited[MAXN];
queue<int> qu;
bool inQ[MAXN];
vector<pair<int, int>> vt[501];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) dst[i] = INF, visited[i] = 0;
    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        vt[a].push_back({b, c});
    }

    qu.push({1});
    inQ[1] = true;
    visited[1]++;
    dst[1] = 0;
    bool no_ans = false;
    while (!qu.empty())
    {
        int x = qu.front(); qu.pop();
        inQ[x] = false;
        for (auto next_ : vt[x])
        {
            int y = next_.first;
            int cost = next_.second;
            if (dst[y] > dst[x] + cost)
            {
                dst[y] = dst[x] + cost;
                if (!inQ[y])
                {
                    visited[y]++;
                    inQ[y] = true;
                    qu.push(y);
                    if (visited[y] == n)
                    {
                        queue<int> empty_qu; swap(qu, empty_qu);
                        no_ans = true;
                        break;
                    }
                }
            }
        }
    }
    
    if (no_ans) printf("-1\n");
    else for (int i=2; i<=n; i++) printf("%d\n", (dst[i] == INF? -1 : dst[i]));
    return 0;
}
