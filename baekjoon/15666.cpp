#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr, vt;

map<int, int> mp;

void dfs(int st, int cnt)
{
    if (cnt == m)
    {
        for (int x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (map<int, int>::iterator itr = next(mp.begin(), st); itr != mp.end(); itr++, st++)
        {
            vt.push_back(itr->first);
            dfs(st, cnt+1);
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
        mp[a]++;
    }

    dfs(0, 0);
    
    return 0;
}
