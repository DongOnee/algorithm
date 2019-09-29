/**
 * 2019.09.29. 16:17 ~ 16:53
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, target[2];
vector<vector<int>> connected;
vector<bool> visited;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &n, target+0, target+1, &m);
    connected.resize(n);
    visited.resize(n);

    for (int i=0, p, c; i<m; i++)
    {
        scanf("%d%d", &p, &c);
        connected[p-1].push_back(c-1);
        connected[c-1].push_back(p-1);
    }

    queue<int> qu;
    qu.push(target[0]-1);
    visited[target[0]-1] = true;
    int ans = 0;
    bool flag = false;
    while (!qu.empty())
    {
        long sz = qu.size();
        while (sz--)
        {
            int f = qu.front(); qu.pop();
            for (int x : connected[f])
            {
                if (x == target[1]-1)
                {
                    queue<int> emptyqu; qu.swap(emptyqu);
                    flag = true;
                    sz = 0;
                    break;
                }
                if (visited[x]) continue;
                visited[x] = true;
                qu.push(x);
            }
        }

        ans ++;
    }

    printf("%d\n", flag?ans:-1);
    return 0;
}
