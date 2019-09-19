#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, weights[10001];
vector<int> nears[10001];
vector<int> paths[10001][2];
int ans[100001][2];
bool visited[10001];

pii dfs(int curPoint)
{
    visited[curPoint] = true;

    pii ret = {0, 0};
    for (int next : nears[curPoint]) if (!visited[next])
    {
        pii dfsRet = dfs(next);
        for (int x : paths[next][0]) paths[curPoint][1].push_back(x);
        ret.second += dfsRet.first;

        if (dfsRet.first < dfsRet.second)
        {
            for (int x : paths[next][1]) paths[curPoint][0].push_back(x);
            ret.first += dfsRet.second;
        }
        else
        {
            for (int x : paths[next][0]) paths[curPoint][0].push_back(x);
            ret.first += dfsRet.first;
        }
    }
    
    paths[curPoint][1].push_back(curPoint);

    // printf("cur : %d %d %d\n", curPoint, ret.first, ret.second);
    return {ret.first, ret.second + weights[curPoint]};
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", weights+i);

    while(true)
    {
        int a, b;
        if (scanf("%d", &a) == EOF) break;
        scanf("%d", &b);
        nears[a].push_back(b);
        nears[b].push_back(a);
    }

    pii sol = dfs(1);
    if (sol.first < sol.second)
    {
        printf("%d\n", sol.second);
        sort(paths[1][1].begin(), paths[1][1].end());
        for (int x : paths[1][1]) printf("%d ", x);
    }
    else
    {
        printf("%d\n", sol.first);
        sort(paths[1][0].begin(), paths[1][0].end());
        for (int x : paths[1][0]) printf("%d ", x);
    }
    

    return 0;
}
