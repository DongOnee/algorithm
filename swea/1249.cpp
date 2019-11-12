#include <cstdio>
#include <queue>
using namespace std;
#define INF 987654321

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int map[100][100], n;
int visit[100][100];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int ans;

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void init()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    {
        scanf("%1d", map[i]+j);
        visit[i][j] = INF;
    }
    ans = INF;
}

void run()
{
    priority_queue<pipii> pq;
    pq.push({0, {0, 0}});
    // visit[0][0] = 0;
    while (!pq.empty())
    {
        int val = -pq.top().first;
        pii ptr = pq.top().second;
        pq.pop();
        if (ptr == make_pair(n-1, n-1))
        {
            ans = ans<val?ans:val;
            break;
        }
        if (visit[ptr.first][ptr.second] <= val) continue;
        visit[ptr.first][ptr.second] = val;
        for (int i=0; i<4; i++)
        {
            int nr = ptr.first + dir[i][0];
            int nc = ptr.second + dir[i][1];
            if (!chk(nr, nc)) continue;
            if (visit[nr][nc] <= val + map[nr][nc]) continue;
            pq.push({-val-map[nr][nc], {nr, nc}});
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("1249_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        init();

        run();

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
