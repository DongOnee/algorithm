#include <cstdio>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppiii; // {{time, cost}, dest}

vector<vector<ppiii>> map;
vector<vector<int>> times; // times[i][cost] : i 에 도착 하였을때 cost 의 비용을 지불하였을때의 걸린시간
int n, m, k, u, v, c, d;

int main(int argc, char const *argv[])
{
    int tc; scanf("%d", &tc);
    while (tc--)
    {
        map.clear(), times.clear();
        scanf("%d%d%d", &n, &m, &k);
        map.resize(n), times.assign(n, vector<int>(10001, INF));
        while (k--)
        {
            scanf("%d%d%d%d", &u, &v, &c, &d);
            map[u-1].push_back({{-d, -c}, v-1});
        }

        priority_queue<ppiii> pq2;

        pq2.push({{0, 0}, 0});
        times[0][0] = 0;
        int ans = 0;
        while (!pq2.empty())
        {
            int curTime = -pq2.top().first.first;
            int curCost = -pq2.top().first.second;
            int curIdx = pq2.top().second;
            pq2.pop(); // {{time, cost}, dest}
            if (curIdx == n-1)
            {
                ans = curTime;
                break;
            }
            if (times[curIdx][curCost] < curTime) continue; // 1

            for (auto x : map[curIdx])
            {
                int newTime = curTime - x.first.first;
                int newCost = curCost - x.first.second;
                int newDest = x.second;
                if (newCost <= m && times[newDest][newCost] > newTime)
                {
                    times[newDest][newCost] = newTime;
                    pq2.push({{-newTime, -newCost}, newDest});
                }
            }
        }

        if (ans != 0) printf("%d\n", ans);
        else printf("Poor KCM\n");
    }
    return 0;
}

// 1. 5836 -> 4424
// 2. 4424 -> 2844 : struct -> ppiii
// 