/**
 * 2019.08.05. 22:40 ~
 */
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 1000

typedef pair<int, int> pii;

int n;
pii map[MAXN][MAXN];
int dir[2][2] = {{1, 0}, {0, 1}};

#define chk(row, col) 0<=row&&row<n&&0<=col&&col<n

pii calc_2_5(int input)
{
    pii ans={0, 0};
    while (input%2==0)
    {
        ans.first++;
        input /= 2;
    }
    while (input%5==0)
    {
        ans.second++;
        input /= 5;
    }
    return ans;
}

int bfs()
{
    pii mmap[n][n];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) mmap[i][j] = {0, 0};
    queue<pii> qu;
    qu.push({0, 0});
    mmap[0][0] = { min(map[0][0].first, map[0][0].second), map[0][0].first-map[0][0].second };
    while (!qu.empty())
    {
        pii f = qu.front(); qu.pop();
        for (int i=0; i<2; i++)
        {
            int newr = f.first + dir[i][0];
            int newc = f.second + dir[i][1];
            if (!chk(newr, newc)) continue;
            if (map[newr][newc].first == -1) continue;
        }
    }
    return mmap[n-1][n-1].first;
}

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    for (int tc=1; tc<=t; tc++)
    {
        scanf("%d", &n);
        for (int i=0; i<n; i++) for (int j=0, tmp; j<n; j++)
        {
            scanf("%d", tmp);
            if (tmp == 0) map[i][j] = {-1, 0};
            else map[i][j] = calc_2_5(tmp);
        }
        printf("#%d %d\n", tc, bfs());
    }
    return 0;
}
