/**
 * 19.2.15.
 */
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int v;
vector<pair<int, int>> vt[100001];
bool visited[100001];
int max_;

void dfs(int input, int count)
{
    max_ = max(max_, count);
    for (auto val : vt[input])
    {
        if (visited[val.first]) continue;
        int new_count = count + val.second;
        // if (new_count < max_) continue;
        visited[val.first] = true;
        dfs(val.first, new_count);
        visited[val.first] = false;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &v);
    
    for (int i=0, index, a, b; i<v; i++)
    {
        scanf("%d", &index);
        while(true)
        {
            scanf("%d", &a);
            if (a==-1) break;
            scanf("%d", &b);
            vt[index].push_back(make_pair(a, b));
        }
    }

    max_=0;
    for (int i=1; i<=v; i++)
    {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    printf("%d\n", max_);
    return 0;
}
