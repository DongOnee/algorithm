#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int par[200010];
int t, n;
int num[200010];
char a[21], b[21];

int find(int x)
{
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

int merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        par[x] = y;
        num[y] += num[x];
        num[x] = 1;
    }
    return num[y];
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int ct = 1;
        map<string, int> mp;

        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++)
        {
            par[i] = i;
            num[i] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            scanf("%s %s", a+0, b+0);
            if (mp.count(a) == 0) mp[a] = ct++;
            if (mp.count(b) == 0) mp[b] = ct++;
            printf("%d\n", merge(mp[a], mp[b]));
        }
    }
    return 0;
}

// 출처: https://jason9319.tistory.com/41 [ACM-ICPC 상 탈 사람]