#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }
pii operator-(const pii& a, const pii& b) { return {a.first-b.first, a.second-b.second}; }

pii dir[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int n, m, map[10][10], direction[6][6];
vector<pipii> bridges;
bool mmap[10][10];
vector<vector<pii>> islands;
int cntIslands;
int pars[6], sums[6], cntConnected[6];

int findFunc(int idx)
{
    if (pars[idx] == idx) return idx;
    return pars[idx] = findFunc(pars[idx]);
}

void unionFunc(int a, int b, int l)
{
    int aa = findFunc(a);
    int bb = findFunc(b);
    if (aa == bb) return;
    if (aa > bb) swap(aa, bb);
    pars[bb] = aa;
    sums[aa] += sums[bb] + l;
    cntConnected[aa] += cntConnected[bb];
}

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<m; }

void run()
{
    for (int idxIsland = 0; idxIsland < cntIslands; idxIsland++)
    {
        queue<pipii> loc;
        for (auto x : islands[idxIsland]) for (int i=0; i<4; i++) loc.push({i, x});
        int step = 0;
        while (!loc.empty())
        {
            long sz = loc.size();
            while (sz--)
            {
                pii point = loc.front().second;
                int dirc = loc.front().first;
                loc.pop();
                point = point + dir[dirc];
                if (!chk(point.first, point.second)) continue;
                int nxt = map[point.first][point.second];
                if (nxt == idxIsland) continue;
                else if (nxt == -1) loc.push({dirc, point});
                else if (direction[nxt][idxIsland] == 0 && step > 1)
                {
                    direction[nxt][idxIsland] = step;
                    direction[idxIsland][nxt] = step;
                    bridges.push_back({step, {idxIsland, nxt}});
                }
            }
            step++;
        }
    }
}

int main(int argc, char const *argv[])
{
    memset(map, -1, sizeof(map));
    scanf("%d%d", &n, &m);
    queue<pii> land;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        scanf("%d", mmap[i] +j);
        if (mmap[i][j]) land.push({i, j});
    }

    while (!land.empty())
    {
        pii f = land.front(); land.pop();
        if (map[f.first][f.second] > -1) continue;
        queue<pii> qu;
        qu.push(f);
        map[f.first][f.second] = cntIslands;
        islands.push_back(vector<pii>());
        islands[cntIslands].push_back(f);
        while (!qu.empty())
        {
            f = qu.front(); qu.pop();
            for (int i=0; i<4; i++)
            {
                int nr = f.first + dir[i].first;
                int nc = f.second + dir[i].second;
                if (!chk(nr, nc)) continue;
                if (map[nr][nc] == cntIslands) continue;
                if (!mmap[nr][nc]) continue;
                map[nr][nc] = cntIslands;
                qu.push({nr, nc});
                islands[cntIslands].push_back({nr, nc});
            }
        }
        cntIslands++;
    }

    run();
    
    sort(bridges.begin(), bridges.end());
    for (int i=0; i<6; i++)
    {
        pars[i] = i;
        cntConnected[i] = 1;
    }

    for (auto x : bridges)
    {
        unionFunc(x.second.first, x.second.second, x.first);
    }

    printf("%d\n", (sums[0]==0 || cntConnected[0] != cntIslands?-1:sums[0]));

    return 0;
}
