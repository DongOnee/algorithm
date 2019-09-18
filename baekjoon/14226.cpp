#include <cstdio>
#include <queue>
using namespace std;

bool visited[1001][1001];
int s;
queue<pair<int, int>> qu;

int main(int argc, char const *argv[])
{
    scanf("%d", &s);
    qu.push({1, 1});

    int ans = 1;
    bool runFlag = true;
    while(runFlag)
    {
        long sz = qu.size();
        while(sz--)
        {
            pair<int, int> f = qu.front(); qu.pop();
            if (f.first + f.second == s || f.first-1 == s) 
            {
                runFlag = false;
                sz=0;
                break;
            }
            else
            {
                if (f.first+f.second < 1001)
                    if (!visited[f.first+f.second][f.second]) 
                    {
                        qu.push({f.first+f.second, f.second});
                        visited[f.first+f.second][f.second] = true;
                    }
                if (f.first-1 > 0)
                    if (!visited[f.first-1][f.second]) 
                    {
                        qu.push({f.first-1, f.second});
                        visited[f.first-1][f.second] = true;
                    }
                if (!visited[f.first][f.first]) 
                {
                    qu.push({f.first, f.first});
                    visited[f.first][f.first] = true;
                }
            }
            
        }
        ans ++;
    }

    printf("%d\n", ans);
    return 0;
}
