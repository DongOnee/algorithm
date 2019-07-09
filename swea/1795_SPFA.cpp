/**
 * 19.7.9. 12:01 ~
 */
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 1002
#define MAXM 10002
#define INF 987654321

typedef struct edge
{
    int x, y, w;
    int prev;
}edge;

queue<int> qu;
bool inQu[MAXN];
int ends[2][MAXN], dst[2][MAXN];
edge edges[2][MAXM];

void spfa(int start_, int category_) // SPFA(Shortest Path Faster Algorithm)
{
    qu.push(start_);
    inQu[start_] = true;
    dst[category_][start_] = 0;
    while (!qu.empty())
    {
        int current_point = qu.front(); qu.pop();
        inQu[current_point] = false;
        for (int next_point = ends[category_][current_point]; next_point; next_point = edges[category_][next_point].prev)
        {
            int end_point = edges[category_][next_point].y;
            int cost = edges[category_][next_point].w;
            if (dst[category_][end_point] > cost + dst[category_][current_point])
            {
                dst[category_][end_point] = cost + dst[category_][current_point];
                if (!inQu[end_point]) 
                {
                    inQu[end_point] = true;
                    qu.push(end_point);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("input_1795.txt", "r", stdin);
    int w; scanf("%d", &w);
    for(int tc=1, n, m, x; tc<=w; tc++)
    {
        int ans = 0;
        scanf("%d%d%d", &n, &m, &x);
        for (int i=1; i<=n; i++)
        {
            for (int j=0; j<2; j++)
            {
                ends[j][i] = 0;
                dst[j][i] = INF;
            }
            inQu[i] = false;
        }
        for (int i=1, a, b, c; i<=m; i++)
        {
            scanf("%d%d%d", &edges[0][i].x, &edges[0][i].y, &edges[0][i].w);
            edges[0][i].prev = ends[0][edges[0][i].x];
            ends[0][edges[0][i].x] = i;
            edges[1][i].x = edges[0][i].y, edges[1][i].y = edges[0][i].x, edges[1][i].w = edges[0][i].w;
            edges[1][i].prev = ends[1][edges[1][i].x];
            ends[1][edges[1][i].x] = i;
        }


        spfa(x, 0);
        spfa(x, 1);

        for (int i=1; i<=n; i++) ans = max(ans, dst[0][i] + dst[1][i]);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
