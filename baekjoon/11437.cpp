/**
 * LCA 문제 입문
 * LCA 문제의 native 한 풀이 방법
 */
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 50'000

vector<int> linked[MAXN+1];
int parent_of_[MAXN+1], depth_of_[MAXN+1];

void dfs(int idx, int depth)
{
    depth_of_[idx] = depth++;
    for (auto& nxt : linked[idx])
    {
        if (!depth_of_[nxt])
        {
            dfs(nxt, depth);
            parent_of_[nxt] = idx;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    for (int i=1, a, b; i<n; i++)
    {
        cin >> a >> b;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }
    dfs(1, 1);
    int m; cin >> m;
    for (int i=0, a, b; i<m; i++)
    {
        cin >> a >> b;
        if (depth_of_[a] > depth_of_[b]) swap(a, b);
        while (depth_of_[a] != depth_of_[b]) b = parent_of_[b];
        while (a != b) a = parent_of_[a], b = parent_of_[b];
        cout << a << '\n';
    }
    return 0;
}
