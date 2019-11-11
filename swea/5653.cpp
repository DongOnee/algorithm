#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;

int visit[350][350];
int n, m, k;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

queue<ppiipii> qu;
queue<pii> qu2;
void run()
{
    while (k--)
    {
        long sz = qu.size();
        while (sz--)
        {
            int r = qu.front().first.first;
            int c = qu.front().first.second;
            int l = qu.front().second.first;
            int ll = qu.front().second.second;
            qu.pop();

            if (l == 0)
            {
                for (int i=0; i<4; i++)
                {
                    int nr = r+dir[i][0];
                    int nc = c+dir[i][1];

                    if (visit[nr][nc] == 0) qu2.push({nr, nc});
                    else if (visit[nr][nc] < 0) continue;
                    visit[nr][nc] = visit[nr][nc]>ll?visit[nr][nc]:ll;
                }
            }
            if (l-1 != -ll) qu.push({{r, c}, {l-1, ll}});
        }

        while (!qu2.empty())
        {
            pii f = qu2.front();
            qu2.pop();
            qu.push({f, {visit[f.first][f.second], visit[f.first][f.second]}});
            visit[f.first][f.second] *= -1;
        }
    }
}

void init()
{
    for (int i=0; i<350; i++) for (int j=0; j<350; j++) visit[i][j] = 0;
    while (!qu.empty()) qu.pop();

    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<n; i++) for (int j=0, a; j<m; j++)
    {
        scanf("%d", &a);
        if (a>0)
        {
            visit[i+150][j+150] = a;
            qu.push({{i+150, j+150}, {a, a}});
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("5653_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int tesc_case=1; tesc_case<=tc; tesc_case++)
    {
        init();

        run();

        printf("#%d %ld\n", tesc_case, qu.size());
    }
    return 0;
}
