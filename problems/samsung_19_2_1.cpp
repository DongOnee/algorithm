#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 50
#define MAX_M 50

int n, m, k;
int map[MAX_N][MAX_M];
int tu[MAX_N];

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

// row 값이 map 배열을 초과하는지 안하는지
bool chk(int r) { return 0<=r&&r<n; }

// map 에서 get/set 하는 함수
int getmp(int i, int j) { return map[i][(j+tu[i]+m)%m]; }
void setmp(int i, int j, int v) { map[i][(j+tu[i]+m)%m] = v; }

void printmp()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            printf("%2d ", getmp(i, j));    
        }
        printf("\n");
    }
    printf("\n");
}

// 평균보다 작은건 +1, 큰건 -1 하는 작업
void update()
{
    // 평균 구하기 위해
    int sum = 0, cnt = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (getmp(i, j) == -1) continue;
            sum += getmp(i, j);
            cnt++;
        }
    }

    // 업데이트
    if (cnt > 0)
    {
        int avg = sum  / cnt;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++)
        {
            int tmp  = getmp(i, j);
            if (tmp != -1) 
            {
                if (tmp < avg) setmp(i, j, tmp +1);
                if (tmp > avg) setmp(i, j, tmp -1);
            }
        } 
    }
}

// (r, c) 위치에서 BFS 를 통해서 같은것들을 삭제(-1로 변환)
void bfs(int r, int c)
{
    queue<pair<int, int>> qu;
    qu.push({r, c});
    int tmp = getmp(r, c);
    setmp(r, c, -1);

    while (!qu.empty())
    {
        pair<int, int> f = qu.front(); qu.pop();
        for (int di = 0; di<4; di++)
        {
            int nr = f.first + dir[di][0];
            if (!chk(nr)) continue;
            int nc = f.second + dir[di][1];
            if (getmp(nr, nc) != tmp) continue;
            setmp(nr, nc, -1);
            qu.push({nr, nc});
        }
    }
}

// 완전탐색 한번으로 //  삭제할 것이 있다 --> 삭제(bfs 함수 이용), 삭제할것이 없다 --> 업데이트
void dfs()
{
    bool can_update = true;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (getmp(i, j) == -1) continue;
            bool can_bfs = false;
            // (i, j) 에서 상하좌우 만 보고 같은게 있으면 bfs(i, j) 실행해서 삭제해준다.
            for (int di = 0; di<4; di++)
            {
                int nr = i + dir[di][0];
                if (!chk(nr)) continue;
                int nc = j + dir[di][1];
                if (getmp(i, j) == getmp(nr, nc))
                {
                    can_bfs = true;
                    can_update = false; // 삭제 오퍼레이션이 일어나서 업데이트는 안한다.
                    break;
                }
            }

            if (can_bfs) bfs(i, j);
        }
    }

    // update
    if (can_update) update();
}

// tu 배열은 회전을 몇번 했는지 저장하기 위해.
void turn(int idx, bool c, int cnt)
{
    if (c) tu[idx] = (tu[idx] + c) % m;
    else tu[idx] = (tu[idx] + m -c) % m;
}

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i=0; i<n; i++) 
        {
            for (int j=0; j<m; j++) scanf("%d", map[i]+j);
            tu[i] = 0;
        }

        while (k--)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            int aa = a;
            while (a <= n)
            {
                turn(a-1, b, c);
                a += aa;
            }

            dfs();
            printmp();
        }

        int ans = 0;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (getmp(i, j) != -1) ans += getmp(i, j);
        printf("%d\n", ans);
    }
    return 0;
}
