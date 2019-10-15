#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, cnt;
map<int, int> mp;
vector<pair<int, int>> vt;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second != b.second) return a.second > b.second;
    return mp[a.first] < mp[b.first];
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        if (mp.count(a) == 0)
        {
            mp[a] = cnt;
            vt.push_back({a, 1});
            cnt++;
        }
        else vt[mp[a]].second++;
    }

    sort(vt.begin(), vt.end(), comp);

    for (auto x : vt) while (x.second--) printf("%d ", x.first);

    return 0;
}
