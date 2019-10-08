#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+ b.second}; }
bool operator==(const pii& a, const pii& b) { return a.first==b.first&&a.second==b.second; }

int map[20][20], n, m;
bool visited[20][20][2];
pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }
bool chk(pii p) { return chk(p.first, p.second); }

bool vst(pii p, bool c) { return visited[p.first][p.second][c]; }
int mp(pii p) { return map[p.first][p.second]; }

bool canBuild(pii point)
{
    int sum = 0, cnt=0;
    for (int i=0; i<4; i++)
    {
        pii nxt = point+dir[i];
        if (chk(nxt)) if (mp(nxt) == 0)
        {
            cnt++;
            sum+=i;
        }
    }
    if ((sum == 1 || sum == 3 || sum == 5) && cnt == 2) return false;
    else if (cnt > 2) return false;
    return true;
}

int solution()
{
    queue<pair<bool, pii>> qu;
    visited[0][0][true] = true;
    qu.push({true, {0, 0}});

    int cnt = 1;
    while (!qu.empty())
    {
        long sz = qu.size();
        while (sz--)
        {
            bool chance = qu.front().first;
            pii cur = qu.front().second;
            qu.pop();

            bool onemore = false;
            for (int idx=0; idx<4; idx++)
            {
                pii nxt = cur + dir[idx];
                bool nxtc = chance;
                if (!chk(nxt)) continue;
                if (mp(nxt) == 1);
                else if (mp(cur) != 1) continue;
                else if (mp(nxt) == 0)
                {
                    if (nxtc)
                    {
                        if (!canBuild(nxt)) continue;
                        if (cnt % m == 0) nxtc = false;
                        else
                        {
                            onemore = true;
                            continue;
                        }
                    } 
                    else continue;
                }
                else if (mp(nxt) > 1)
                {
                    if(cnt % mp(nxt) != 0)
                    {
                        onemore = true;
                        continue;
                    }
                }
                
                if (vst(nxt, nxtc)) continue;
                visited[nxt.first][nxt.second][nxtc] = true;

                if (nxt == make_pair(n-1, n-1)) return cnt;
                qu.push({nxtc, nxt});
            }
            if (onemore && mp(cur) != 0) qu.push({chance, cur});
        }
        cnt++;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    printf("%d\n", solution());

    return 0;
}
