#include <cstdio>
#include <vector>
using namespace std;

int n, m;
vector<int> vt;
bool picked[10];

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (auto x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (!picked[i])
            {
                picked[i] = true;
                vt.push_back(i);
                dfs(cnt+1);
                vt.pop_back();
                picked[i] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    dfs(0);
    return 0;
}
