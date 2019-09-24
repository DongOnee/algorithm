#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int par[200010];
int t, n;
int num[200010];
vector<string> vn;
vector<pair<string, string>> vt;

int find(int x)
{
    if (x == par[x]) return x;
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
        vt.clear();
        vn.clear();

        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
        {
            par[i] = i;
            num[i] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            char a[21], b[21];
            scanf("%s %s", a+0, b+0);
            vt.push_back({ a,b });
            vn.push_back(a);
            vn.push_back(b);
        }

        sort(vn.begin(), vn.end());
        vn.erase(unique(vn.begin(), vn.end()), vn.end());
        
        for (int i = 0; i < n; i++)
        {
            int x = lower_bound(vn.begin(), vn.end(), vt[i].first) - vn.begin();
            int y = lower_bound(vn.begin(), vn.end(), vt[i].second) - vn.begin();
            printf("%d\n", merge(x, y));
        }
    }
    return 0;
}

// 출처: https://jason9319.tistory.com/41 [ACM-ICPC 상 탈 사람]