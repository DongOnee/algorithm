/**
 * 19.4.12. 22:17~23:18
 */
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int n, k, t;
bool visited[500001];
queue<int> qu;

bool chk(int point) { return 0<=point&&point<500001; }

bool bfs(int kk)
{
    for (int i=0; i<3; i++)
    {
        int next = kk;
        if (i==0) next++;
        else if (i==1) next--;
        else next *=2;
        if (next == k) return true;
        // if (next>500000)
        // {
        //     t = -1;
        //     return true;
        // }
        if (!chk(next)) continue;
        if (visited[next]) continue;
        visited[next] = true;
        qu.push(next);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &k);
    if (n==k)
    {
        printf("0\n");
        return 0;
    }
    qu.push(n);
    visited[n] = true;
    t=0;
    while (!qu.empty())
    {
        k += ++t;
        if (!chk(k))
        {
            printf("-1\n");
            return 0;
        }
        for (int i=0; i<500001; i++) visited[i] = false;
        long sz = qu.size();
        while (sz--)
        {
            int f = qu.front();
            qu.pop();
            if (bfs(f))
            {
                printf("%d\n", t);
                return 0;
            }
        }
    }
    
    printf("-1\n");

    return 0;
}
