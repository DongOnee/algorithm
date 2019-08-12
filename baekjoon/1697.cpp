#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, k;
bool visited[100001];

queue<pair<int, int>> qu;

void bfs(pair<int, int> cur)
{
    // +1
    int tmp = cur.first+1;
    for (int i=0, tmp; i<3; i++)
    {
        if (i == 0) tmp = cur.first+1;
        else if (i == 1) tmp = cur.first -1;
        else tmp = cur.first*2;
        if (!(0<=tmp&&tmp<100001)) continue;
        if (visited[tmp]) continue;
        if (tmp == k)
        {
            printf("%d\n", cur.second+1);
            queue<pair<int, int>> emptyQ;
            swap(emptyQ, qu);
            break;
        }
        qu.push({tmp, cur.second+1});
        visited[tmp] = true;
    }
    
}

int main(int argc, char* argv[])
{
    scanf("%d %d", &n, &k);
    if (n == k)
    {
        printf("0\n");
        return 0;
    }

    visited[n] = true;
    qu.push({n, 0});
    while(!qu.empty())
    {
        long sz = qu.size();
        pair<int, int> f = qu.front(); qu.pop();
        bfs(f);
    }
}