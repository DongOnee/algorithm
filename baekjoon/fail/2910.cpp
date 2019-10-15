#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;

int loc[1000000001];
int cnt;
vector<pair<int, int>> vt;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second != b.second) return a.second > b.second;
    return loc[a.first] < loc[b.first];
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &c);
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        if (loc[a] == 0)
        {
            loc[a] = ++cnt;
            vt.push_back({a, 1});
        }
        else vt[loc[a]-1].second++;
    }

    sort(vt.begin(), vt.end(), comp);

    for (auto x : vt)
    {
        while (x.second--) printf("%d ", x.first);
    }
    return 0;
}
