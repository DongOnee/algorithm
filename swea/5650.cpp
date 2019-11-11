#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int n, map[102][102], ans;
int wormholeMove[11], cntWormhole;
pii wormholes[11];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void print_map()
{
    for (int i=0; i<=n+1; i++)
    {
        for (int j=0; j<=n+1; j++) printf("%2d ", map[i][j]);
        printf("\n");
    }
    for (int i=0; i<cntWormhole; i++) printf("%d ", wormholeMove[i]);
    printf("\n");
}

void init()
{
    scanf("%d", &n);
    int tmpWormhole[11];
    for (int i=0; i<11; i++) tmpWormhole[i] = -1;
    cntWormhole = 0, ans = 0;
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) 
    {
        scanf("%d", map[i]+j);
        if (map[i][j] > 5)
        {
            wormholes[cntWormhole] = {i, j};

            if (tmpWormhole[map[i][j]] == -1) tmpWormhole[map[i][j]] = cntWormhole;
            else
            {
                int anotherWormhole = tmpWormhole[map[i][j]];
                wormholeMove[anotherWormhole] = cntWormhole;
                wormholeMove[cntWormhole] = anotherWormhole;
            }

            map[i][j] = cntWormhole + 10;
            cntWormhole++;
        }
    }
    for (int i=1; i<=n+1; i++)
    {
        map[i][n+1] = 5;
        map[n+1][i] = 5;
    }
}

pii go(pii cur, const int di, const pii st)
{
    while(true)
    {
        cur.first += dir[di][0];
        cur.second += dir[di][1];

        if (0 < map[cur.first][cur.second] && map[cur.first][cur.second] < 6) return cur;
        else if (map[cur.first][cur.second] == -1) return cur;
        else if (cur == st) return cur;
        else if (9 < map[cur.first][cur.second])
        {
            cur = wormholes[wormholeMove[map[cur.first][cur.second]-10]];
        }
    }
}

int turn(int di, int wall)
{
    switch (wall)
    {
    case 5:
        return (di + 2) % 4;
        break;

    case 4:
        if (di == 2 || di == 3) return (di+2) % 4;
        else if (di == 0) return 3;
        else return 2;

    case 3:
        if (di == 1 || di == 2) return (di+2) % 4;
        else if (di == 0) return 1;
        else return 2;

    case 2:
        if (di == 0 || di == 1) return (di+2) % 4;
        else if (di == 2) return 1;
        else return 0;

    case 1:
        if (di == 3 || di == 0) return (di+2) % 4;
        else if (di == 2) return 3;
        else return 0;

    default:
        break;
    }
    return -1;
}

void run2(const pii st, int d)
{
    int ret = 0;
    pii ptr = st;
    while (true)
    {
        ptr = go(ptr, d, st);
        // printf("%d %d\n", ptr.first, ptr.second);
        if (ptr == st || map[ptr.first][ptr.second] == -1) break;
        d = turn(d, map[ptr.first][ptr.second]);
        ret++;
    }
    ans = ans>ret?ans:ret;
}

void run()
{
    // run2({3, 4}, 0);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int di=0; di<4; di++) if (map[i][j] == 0) run2({i, j}, di);
}

int main(int argc, char const *argv[])
{
    // freopen("5650_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int i=0; i<102; i++) map[i][0] = map[0][i] = 5;

    for (int test_case = 1; test_case<=tc; test_case++)
    {
        init();
        // print_map();
        run();

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
