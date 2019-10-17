#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr, vt;

map<int, int> mp;

void dfs(int cnt)
{
    if (cnt == m)
    {
        for (int x : vt) printf("%d ", x);
        printf("\n");
    }
    else
    {
        for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++)
        {
            if ( itr->second == 0) continue;
            itr->second--;
            vt.push_back(itr->first);
            dfs(cnt+1);
            vt.pop_back();
            itr->second++;
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

    dfs(0);
    
    return 0;
}
