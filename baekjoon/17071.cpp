/**
 * 19.4.12. 23:19~23:53
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int n, k, t;
int visited[2][500001];
queue<int> qu;

bool chk(int point) { return 0<=point&&point<500001; }

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &k);
    if (n==k)
    {
        printf("0\n");
        return 0;
    }
    fill(visited[0], visited[0]+500001, -1);
    fill(visited[1], visited[1]+500001, -1);
    qu.push(n);
    t=0;
    visited[1-t%2][n] = t;

    while (!qu.empty())
    {
        k += ++t;
        if (!chk(k))
        {
            printf("-1\n");
            return 0;
        }
        long sz = qu.size();
        while (sz--)
        {
            int f = qu.front(); qu.pop();
            for (auto x : {f-1, f+1, f*2})
            {
                if (!chk(x)) continue;
                if (visited[1-t%2][x] != -1) continue;
                visited[1-t%2][x] = t;
                qu.push(x);
            }
        }
        if (visited[1-t%2][k] != -1 && visited[1-t%2][k] <=t)
        {
            printf("%d\n", t);
            return 0;
        } 
    }
    printf("-1\n");
    return 0;
}