#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 10
#define INF 987654321

typedef pair<int ,int> pii;
typedef pair<pii, int> ppiii;

int map[MAXN][MAXN], n;
ppiii infoExit[2];
pii ptrPerson[10];
int cntPerson, ans;
int person2exit[10][3];
int endExit[2][10];
int cntEndExit[2];

void init()
{
    cntPerson = 0, ans = INF;
    int cntExit = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0, a; j<n; j++)
    {
        scanf("%d", &a);
        map[i][j] = a;
        if (a > 1) infoExit[cntExit++] = {{i, j}, a};
        else if (a == 1) ptrPerson[cntPerson++] = {i, j};
    }
    for (int i=0; i<cntPerson; i++)
    {
        person2exit[i][0] = abs(ptrPerson[i].first-infoExit[0].first.first) + abs(ptrPerson[i].second-infoExit[0].first.second);
        person2exit[i][1] = abs(ptrPerson[i].first-infoExit[1].first.first) + abs(ptrPerson[i].second-infoExit[1].first.second);
    }

    cntEndExit[0] = 0, cntEndExit[1] = 0;
}

int cp0[10], cp1[10];
void dfs(int cnt)
{
    if (cnt == cntPerson)
    {
        int ret1 = 0, ret2 = 0;
        
        if (cntEndExit[0])
        {
            for (int i=0; i<cntEndExit[0]; i++) cp0[i] = endExit[0][i];
            sort(cp0, cp0 + cntEndExit[0]);
            for (int i=3; i<cntEndExit[0]; i++)
            {
                if (cp0[i] < cp0[i-3] + infoExit[0].second) cp0[i] = cp0[i-3] + infoExit[0].second;
            }
            ret1 = cp0[cntEndExit[0]-1];
        }
        
        if (cntEndExit[1])
        {
            for (int i=0; i<cntEndExit[1]; i++) cp1[i] = endExit[1][i];
            sort(cp1, cp1 + cntEndExit[1]);
            for (int i=3; i<cntEndExit[1]; i++)
            {
                if (cp1[i] < cp1[i-3] + infoExit[1].second) cp1[i] = cp1[i-3] + infoExit[1].second;
            }
            ret2 = cp1[cntEndExit[1]-1];
        }

        ans = min(ans, max(ret1+infoExit[0].second, ret2+infoExit[1].second));
    }
    else
    {
        endExit[0][cntEndExit[0]++] = person2exit[cnt][0];
        dfs(cnt+1);
        cntEndExit[0]--;

        endExit[1][cntEndExit[1]++] = person2exit[cnt][1];
        dfs(cnt+1);
        cntEndExit[1]--;
    }
}

int main(int argc, char const *argv[])
{
    freopen("2383_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        init();
        dfs(0);

        printf("#%d %d\n", test_case, ans+1);
    }
    return 0;
}
