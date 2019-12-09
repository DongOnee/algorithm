#include <cstdio>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int n, ans;
vector<int> connected[100001];
bool visited[100001];

int dfs(int curPoint)
{
    vector<bool> valNear;
    valNear.resize(n+1);
    visited[curPoint] = true;

    for (int x : connected[curPoint])
    {
        if (!visited[x]) 
        {
            int x_cost = dfs(x);
            valNear[x_cost] = true;
        }
    }
    
    for (int i=1; i<=n; i++) if (!valNear[i])
    {
        ans += i;
        return i;
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=1, a, b; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    int ret = INF;
    dfs(1);
    ret = ret<ans?ret:ans;

    for (int i=0; i<connected[1].size(); i++)
    {
        ans = 0;
        memset(visited, false, sizeof(visited));
        dfs(connected[1][i]);
        ret = ret<ans?ret:ans;
    }

    
    printf("%d\n", ans);
    return 0;
}
