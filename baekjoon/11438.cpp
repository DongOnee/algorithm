#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100'000
#define MAXD 17 // 2^17 = 131072 > MAXN

int n, m;
vector<int> linked[MAXN+1];
int parent_of_[MAXN+1][MAXD], depth_of_[MAXN+1];

void dfs(int idx, int depth)
{
    depth_of_[idx] = depth++;
    for (auto& nxt : linked[idx])
        if (!depth_of_[nxt])
        {
            dfs(nxt, depth);
            parent_of_[nxt][0] = idx;
        }
}

int lca(int l, int r)
{
    int diff = depth_of_[r] - depth_of_[l];
    for (int d = MAXD-1; 0<=d; --d)
    {
        if (diff >= (1<<d))
        {
            diff -= (1<<d);
            r = parent_of_[r][d];
        }
    }

    if (l == r) return l;

    for (int d = MAXD-1; 0<=d; --d)
    {
        if (parent_of_[l][d] != parent_of_[r][d])
        {
            l = parent_of_[l][d];
            r = parent_of_[r][d];
        }
    }

    return parent_of_[l][0];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=1, a, b; i<n; i++)
    {
        cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }

    dfs(1, 1);

    for (int dp=1; dp<MAXD; ++dp)
        for (int idx = 1; idx <=n; ++idx)
            parent_of_[idx][dp] = parent_of_[parent_of_[idx][dp-1]][dp-1];

    cin >> m;
    for (int i=0, a, b; i < m; i++)
    {
        cin >> a >> b;
        if (depth_of_[a] > depth_of_[b]) swap(a, b);
        cout << lca(a, b) << '\n';
    }


    return 0;
}
