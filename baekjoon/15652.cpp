#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> vt;

void dfs(int st, int cnt)
{
    if (cnt == m)
    {
        for (int x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (int i=st; i<=n; i++)
        {
            vt.push_back(i);
            dfs(i, cnt+1);
            vt.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);

    dfs(1, 0);
    
    return 0;
}
