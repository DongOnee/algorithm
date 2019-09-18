#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int map[52][52];
bool visit[52][52];
int n, m;
int dirs[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
vector<pair<int, int>> vt;

void bfs(pair<int, int> start)
{
    visit[start.first][start.second] = true;
    queue<pair<int, int>> qu; qu.push(start);

    while(!qu.empty())
    {
        pair<int, int> f = qu.front(); qu.pop();
        for (int i=0; i<8; i++)
        {
            pair<int, int> nxt = {f.first+dirs[i][0], f.second+dirs[i][1]};
            if (visit[nxt.first][nxt.second]) continue;
            if (map[nxt.first][nxt.second] == 0) continue;
            visit[nxt.first][nxt.second] = true;
            qu.push(nxt);
        }
    }
}

int main(int argc, char const *argv[])
{
    while(true)
    {
        scanf("%d%d", &m, &n);
        if (n==0 && m==0) break;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        vt.clear();
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
        {
            scanf("%d", map[i]+j);
            if (map[i][j] ==  1) vt.push_back({i, j}); 
        }

        int ans = 0;
        while (!vt.empty())
        {
            pair<int, int> b= vt.back(); vt.pop_back();
            if (visit[b.first][b.second]) continue;
            
            bfs(b);
            ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
