#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAXN 100
#define MAXM 1000
#define MAXK 1000

typedef pair<int, int> pii;

// 미생물 군집에 대한 정보 구조체
typedef struct
{
    pii ptr;
    int scale;
    int dir;
}microbe_info;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }

int n, m, k, ans;
int mmap[MAXN][MAXN][2];
bool toggle;
microbe_info microbe[MAXK]; // 미생물들~
queue<int> alives; // 살아 있는 미생물 index 를 담은 큐
pii dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 이동~

// Get / Set 을 이용해서 mmap 간단하게 다루기 위해 만듦
int getmap(pii ptr, bool flag) { return mmap[ptr.first][ptr.second][flag]; }
void setmap(pii ptr, bool flag, int val) { mmap[ptr.first][ptr.second][flag] = val; }

// side 에 도착했음을 판별하기 위한 함수
bool isSide(pii ptr) { return ptr.first == 0 || ptr.first == n-1 || ptr.second == 0 || ptr.second == n-1; }

// move operation
void move()
{
    vector<vector<int>> samePoint; // 같은 위치에 도착한 군집을 처리하기 위해 담을 곳
    int cnt = 0; // 군집들의 수?
    long sz = alives.size();
    while (sz--)
    {
        int idx = alives.front(); alives.pop();
        setmap(microbe[idx].ptr, toggle, -1); // 이전 mmap 에선 지워줘야지~ -> 간단하게 초기화
        microbe[idx].ptr = microbe[idx].ptr + dir[microbe[idx].dir];
        if (isSide(microbe[idx].ptr)) // 사이드에 도착하면...
        {
            microbe[idx].dir = (microbe[idx].dir + 2) % 4;
            microbe[idx].scale /= 2;
            if (microbe[idx].scale == 0) continue;
        }
        
        // 도착한 곳이 이미 다른 군집이 도착해 있다면?
        if (getmap(microbe[idx].ptr, !toggle) != -1) samePoint[getmap(microbe[idx].ptr, !toggle)].push_back(idx);
        else // 아니라면?
        {
            setmap(microbe[idx].ptr, !toggle, cnt);
            samePoint.push_back(vector<int>(1, idx));
            alives.push(idx);
            cnt++;
        }
    }

    // 같은곳 도착한 군집들을 처리
    for (auto vt : samePoint)
    {
        sz = vt.size();
        if (sz == 1) continue; // 한 미생물 군집밖에 도착하지 않음

        // 기준이 되는 군집들에 대한 index 와 방향을 고려하기 위한 scale 을 저장
        int standIdx = vt[0], standScale = microbe[standIdx].scale;

        for (int idx = 1; idx < sz; idx++) 
        {
            // 방향 정하기
            if (standScale < microbe[vt[idx]].scale) 
            {
                microbe[standIdx].dir = microbe[vt[idx]].dir;
                standScale = microbe[vt[idx]].scale;
            }
            microbe[standIdx].scale += microbe[vt[idx]].scale;
        }

        // 항상 standIdx 에 업데이트 된다. 
    }
    toggle ^= true;
}

int main(int argc, char const *argv[])
{
    // freopen("2382_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        ans = 0, toggle = false;
        queue<int> empty_qu; swap(alives, empty_qu);
        memset(mmap, -1, sizeof(mmap));

        scanf("%d%d%d", &n, &m, &k);
        for (int i=0, a, b, c, d; i<k; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (d == 1) d = 3;
            else if (d == 2) d = 1;
            else if (d == 3) d = 2;
            else d = 0;
            microbe[i] = {{a, b}, c, d};
            alives.push(i);
        }
        while (m--) move();

        while (!alives.empty())
        {
            int idx = alives.front(); alives.pop();
            ans += microbe[idx].scale;
        }

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
