#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vt, arr;

void dfs(int st, int cnt)
{
    if (cnt == m)
    {
        for (int x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (int idx=st; idx<n; idx++)
        {
            vt.push_back(arr[idx]);
            dfs(idx+1, cnt+1);
            vt.pop_back();
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
    }
    sort(arr.begin(), arr.end());
    dfs(0, 0);
    
    return 0;
}
