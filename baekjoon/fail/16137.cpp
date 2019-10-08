/**
 * 2019.10.04. 19:43 ~
 */
#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 10
#define MAXM 20
#define INF 987654321

typedef pair<int, int> pii;

pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int map[MAXN][MAXN], n, m;
int visited[MAXN][MAXN][2];

#define vst(x, b) visited[x.first][x.second][b]
#define mp(x) map[x.first][x.second]

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }
bool operator==(const pii& a, const pii& b) { return a.first==b.first && a.second==b.second; }

bool canMove(pii point, int remain, int curCnt, const pii& goal)
{
    if (remain == 0) return point == goal;
    bool ret = false;
    for (int idxDir = 0; idxDir <4; idxDir++)
    {
        pii nxtPoint = point + dir[idxDir];
        if (mp(nxtPoint) == 0) continue;
        if (mp(nxtPoint) == 1 || (curCnt+1)%mp(nxtPoint) == 0) ret = ret & canMove(nxtPoint, remain-1, curCnt+1, goal);
    }
    return ret;
}

bool chk(pii x) { return 0<=x.first&&x.first<n&&0<=x.second&&x.second<n; }

bool canBuild(pii point)
{
    int sum = 0, cnt=0;
    for (int i=0; i<4; i++) if (chk(point+dir[i])) if (mp((point + dir[i])) == 0)
    {
        cnt++;
        sum+=i;
    }
    if ((sum == 1 || sum == 3 || sum == 5) && cnt == 2) return false;
    else if (cnt > 2) return false;
    return true;
}

int solution()
{
    priority_queue<pair<int, pair<pii, bool>>> pq;
    visited[0][0][true] = 0;
    pq.push({0, {{0, 0}, true}});

    while (!pq.empty())
    {
        int curTime = -pq.top().first;
        pii curPoint = pq.top().second.first;
        bool curBuildChance = pq.top().second.second;
        pq.pop();

        printf("%d\t%d %d\n", curTime, curPoint.first, curPoint.second);

        if (vst(curPoint, curBuildChance) < curTime) continue;
        if (curPoint == make_pair(n-1, n-1)) return curTime;

        for (int idxDir=0; idxDir<4; idxDir++)
        {
            int nxtTime = curTime + 1;
            pii nxtPoint = curPoint + dir[idxDir];
            bool nxtBuildChance = curBuildChance;

            if (!chk(nxtPoint)) continue;
            if (mp(nxtPoint) == 1)
            {
                if (vst(nxtPoint, nxtBuildChance) <= nxtTime) continue;
                vst(nxtPoint, nxtBuildChance) = nxtTime;
                pq.push({-nxtTime, {nxtPoint, nxtBuildChance}});
            }
            else if (mp(nxtPoint) == 0)
            {
                if (curBuildChance && canBuild(nxtPoint))
                {
                    nxtBuildChance = false;
                    mp(nxtPoint) = m;
                }
            }
            
            if (mp(nxtPoint) > 1 /*&& nxtTime > 2*/)
            {
                int tmp = mp(nxtPoint);
                if (curBuildChance && !nxtBuildChance) mp(nxtPoint) = 0;
                int remain = (tmp - nxtTime%tmp) % tmp;
                if (!(remain %2 == 1 && tmp %2 == 0))
                {
                    if (remain %2 == 1) remain += tmp;
                    nxtTime += remain;
                    if (vst(nxtPoint, nxtBuildChance) > nxtTime && canMove(nxtPoint, remain, nxtTime, nxtPoint))
                    {
                        vst(nxtPoint, nxtBuildChance) = nxtTime;
                        pq.push({-nxtTime, {nxtPoint, nxtBuildChance}});
                        // if (nxtPoint == make_pair(1, 4)) printf("here %d\n", nxtTime);
                    }
                }

            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) 
    {
        scanf("%d", map[i]+j);
        visited[i][j][0] = INF;
        visited[i][j][1] = INF;
    }

    printf("%d\n", solution());

    return 0;
}
