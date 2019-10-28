#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100
#define MAXMICROBE 1000
#define MAXTIME 1000

typedef pair<int, int> pii;

typedef struct 
{
    pii point;
    int scale;
    int dir;
}microbe_info;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }

int n, tmLimit, cntCmd, map[MAXN][MAXN][2], answer;
microbe_info microbe[MAXMICROBE];
queue<int> alive;
pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool toggle;

bool isSide(pii pt) { return pt.first == 0 || pt.first == n-1 || pt.second == 0 || pt.second == n-1; }
int getmap(pii pt, bool flag) { return map[pt.first][pt.second][flag]; }
void setmap(pii pt, bool flag, int val) { map[pt.first][pt.second][flag] = val; }

void init()
{
    memset(map, -1, sizeof(map));
    toggle = false;
    answer = 0;
    queue<int> empty_qu;
    swap(alive, empty_qu);
    scanf("%d%d%d", &n, &tmLimit, &cntCmd);
    for (int i=0, a, b, c, d; i<cntCmd; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        alive.push(i);
        if (d == 1) d = 3;
        else if (d == 2) d = 1;
        else if (d == 3) d = 2;
        else d = 0;
        microbe[i] = {{a, b}, c, d};
    }
}

void move()
{
    vector<pii> fusion;
    long sz = alive.size();
    while (sz--)
    {
        int idx = alive.front(); alive.pop();
        microbe[idx].point = microbe[idx].point + dir[microbe[idx].dir];
        setmap(microbe[idx].point, toggle, -1);
        if (isSide(microbe[idx].point))
        {
            microbe[idx].dir = (microbe[idx].dir + 2) % 4;
            microbe[idx].scale /= 2;
            if (microbe[idx].scale == 0) continue; 
        }
        if (getmap(microbe[idx].point, !toggle) != -1) fusion.push_back({getmap(microbe[idx].point, !toggle), idx});
        else
        {
            setmap(microbe[idx].point, !toggle, idx);
            alive.push(idx);
        }
    }
    toggle ^= true;

    for (auto x : fusion)
    {
        if (microbe[x.first].scale < microbe[x.second].scale) microbe[x.first].dir = microbe[x.second].dir;
        microbe[x.first].scale += microbe[x.second].scale;
    }
}

int main(int argc, char const *argv[])
{
    freopen("2382_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();

        while (tmLimit--)
        {
            move();
        }

        while (!alive.empty())
        {
            int idx = alive.front(); alive.pop();
            answer += microbe[idx].scale;
        }

        printf("#%d %d\n", test_case, answer);
    }
    return 0;
}
