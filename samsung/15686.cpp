#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n, m, map[51][51], memorize[101][14], sol;
vector<pair<int, int>> homes, chickens;
vector<int> alive;

void dfs(int index, int cnt)
{
    if (cnt == m)
    {
        int ret = 0;
        for (int i=0; i<homes.size(); i++)
        {
            int min_ = 987654321;
            for (auto x : alive) min_ = min(min_, memorize[i][x]);
            ret += min_;
            if (sol < ret) break;
        }
        sol = min(sol, ret);
        return;
    }
    for (int i=index; i<chickens.size(); i++)
    {
        alive.push_back(i);
        dfs(i+1, cnt+1);
        alive.pop_back();
    }
}

int go(pair<int, int> home, pair<int, int> chicken) { return abs(home.first-chicken.first) + abs(home.second-chicken.second); }

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0, tmp; j<n; j++)
    {
        scanf("%d", &tmp);
        map[i][j] = tmp;
        if (tmp == 1) homes.push_back({i, j});
        else if (tmp == 2) chickens.push_back({i, j});
    }

    for (int i=0; i<homes.size(); i++)
        for (int j=0; j<chickens.size(); j++)
            memorize[i][j] = go(homes[i], chickens[j]);

    sol = 987654321;
    dfs(0, 0);

    printf("%d\n", sol);

    return 0;
}
