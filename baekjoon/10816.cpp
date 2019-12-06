#include <cstdio>
#include <map>
using namespace std;

map<int, int> mp;

int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        if (mp.count(a) == 0) mp[a] = 1;
        else mp[a]++;
    }
    
    int m; scanf("%d", &m);
    for (int i=0, a; i<m; i++)
    {
        scanf("%d", &a);
        printf("%d ", mp.count(a)==0?0:mp[a]);
    }
    return 0;
}
