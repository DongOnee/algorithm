/**
 * 2019.08.05. 22:40 ~
 */
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 1000

typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;

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
    ppiipii mmap[n][n]; // first : 2 가 더 많은경우, second : 5 가 더 많은 경우?
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) mmap[i][j] = {{0, 0}, {0, 0}};
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
