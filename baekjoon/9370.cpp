/**
 * 2020.05.31. 19:35 ~ 06.01. 02:05
 * 다익스트라를 이용해서 풀 수 있었던 문제이다.
 * 하지만 많이 실패했는데.. 정리하면 다음과 같다.
 * 1. 우선순위 큐 를 소팅하는 함수 구조체에 대해서 다시 공부해야 됐다.
 * 2. 우선순위 큐 소팅하는 과정에서 필수 링크(g-h) 를 지났는지 여부에 대한 처리에 대해서 생각을 많이 했다.
 * 3. 메모리 초과가 나는데 같은 노드에 같은 코스트로 여러번 갈 경우 디스크가 쌓여서 메모리 초과가 난다.
 *      이 트러블 슈팅하기 위해서 isCrossGH 라는 bool 배열을 두어 g-h 를 지났는지 여부를 메모라이징 해두어
 *      위 와같은 경우 isCrossGH 값을 확인하여 저장할 수 있도록 한다.
 */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> pii;

int const MAXN = 2000;

typedef struct
{
    int distance;
    bool isGH;
    int index;
}elem;

struct comp
{
    bool operator()(const elem& a, const elem& b) { return (a.distance != b.distance)?(a.distance > b.distance):b.isGH; }
};

int n, m, t, s, g, h, dist[MAXN];
bool isCrossGH[MAXN];
vector<pii> dist_next[MAXN];
vector<int> candidate, answers;
priority_queue<elem, vector<elem>, comp> pq;

void sol()
{
    for( int i = 0; i < n; i++ )
        dist_next[i].clear();
    candidate.clear();
    answers.clear();
    memset(dist, 0x7f, sizeof(dist));
    memset(isCrossGH, 0x00, sizeof(isCrossGH));

    cin >> n >> m >> t >> s >> g >> h;
    g--, h--;

    for (int i = 0, a, b, d; i < m; i++)
    {
        cin >> a >> b >> d;
        dist_next[a-1].push_back({d, b-1});
        dist_next[b-1].push_back({d, a-1});
    }

    for (int i = 0, x; i < t; i++)
    {
        cin >> x;
        candidate.push_back(x-1);
    }

    pq.push({0, false, s-1});
    dist[s-1] = 0;
    while( !pq.empty() )
    {
        elem t = pq.top(); pq.pop();

        int distance = t.distance;
        bool isGH = t.isGH;
        int cur = t.index;
        
        if( distance == dist[cur] )
        {
            auto itr = find(candidate.begin(), candidate.end(), cur);
            if( itr != candidate.end() )
            {
                candidate.erase(itr);
                if( isGH )
                    answers.push_back(cur);
            }
        }

        for( pii& tmp : dist_next[cur] )
        {
            bool nextGH = isGH;
            if( (cur == g && tmp.second == h) || (cur == h && tmp.second == g) )
                nextGH = true;

            int& distance_next = dist[tmp.second];
            if( distance + tmp.first < distance_next )
            {
                distance_next = distance + tmp.first;
                pq.push({distance_next, nextGH, tmp.second});
                isCrossGH[tmp.second] = nextGH;
            }
            else if( distance + tmp.first == distance_next && !isCrossGH[tmp.second] && nextGH )
            {
                isCrossGH[tmp.second] = nextGH;
                pq.push({distance_next, nextGH, tmp.second});
            }
        }
    }

    sort(answers.begin(), answers.end());
    for (int& x : answers)
        cout << x+1 << ' ';
    cout << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while(test_case--)
        sol();

    return 0;
}
