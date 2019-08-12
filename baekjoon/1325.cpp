/**
 * 19.4.8.
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> map[10001];

int trav(int computer, bool* visited)
{
    visited[computer] = true;
    int sol =1;
    for (auto x: map[computer])
    {
        if (visited[x]) continue;
        sol += trav(x, visited);
    }
    return sol;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        map[b].push_back(a);
    }

    vector<int> vt;
    int sol = -1;

    for (int i=1; i<=n; i++)
    {
        bool chk[10001] = {false, };
        int tmp = trav(i, chk);
        if (sol < tmp)
        {
            sol = tmp;
            vector<int> emptys;
            swap(vt, emptys);
            vt.push_back(i);
        }
        else if (sol == tmp) vt.push_back(i);
    }
    sort(vt.begin(), vt.end());
    for (auto x : vt) printf("%d ", x);
    return 0;
}
