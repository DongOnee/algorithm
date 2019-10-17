#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr, vt;
vector<bool> visited;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (int idx=0; idx<n; idx++)
        {
            if (visited[idx]) continue;
            visited[idx] = true;
            vt.push_back(arr[idx]);
            dfs(cnt+1);
            vt.pop_back();
            visited[idx] = false;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);

    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        arr.push_back(a);
        visited.push_back(false);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
    
    return 0;
}
