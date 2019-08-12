/**
 * 19.3.3.
 */
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, x;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> a2b[1001];
int dist[2][1001];      //      0: ? -> x     1: x -> ?

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &m, &x);
    
    for (int i=1; i<=n; i++) 
    {
        dist[0][i]=1e9;
        dist[1][i]=1e9;
    }
    dist[0][x]=0;
    dist[1][x]=0;

    for (int i=0, a, b, t; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &t);
        a2b[a].push_back(make_pair(t, b)); // a 에서 가는것들 b
    }

    for (auto start : a2b[x]) pq.push(make_pair(-start.first, start.second));

    while (!pq.empty())
    {
        pair<int, int> tp = pq.top();
        pq.pop();
        int x2dest = tp.second;
        int x2dest_tm = -tp.first;

        if (dist[1][x2dest] <= x2dest_tm) continue;
        dist[1][x2dest] = x2dest_tm;
        for (auto st : a2b[x2dest])
        {
            int x2dest2dest = st.second;
            int dest2dest_tm = st.first;

            if (dist[1][x2dest2dest] < x2dest_tm+dest2dest_tm) continue;
            pq.push(make_pair(-x2dest_tm-dest2dest_tm, x2dest2dest));
        }
    }
    // for (int i=1; i<=n; i++) printf("%d ", dist[1][i]);
    // puts("");

    for (int i=1; i<=n; i++)
    {
        int visited[1001];
        fill_n(visited, 1001, 1e9);
        visited[i] = 0;
        for (auto dest : a2b[i]) pq.push(make_pair(-dest.first, dest.second));

        while (!pq.empty())
        {
            pair<int, int> tp = pq.top();
            pq.pop();
            int dest = tp.second;
            int tm = -tp.first;

            if (visited[dest] <= tm) continue;
            visited[dest] = tm;
            for (auto d2d : a2b[dest])
            {
                int _2dest = d2d.second;
                int tm2dest = d2d.first;
                if (visited[_2dest] < tm + tm2dest) continue;
                pq.push(make_pair(-tm-tm2dest, _2dest));
            }
        }
        dist[0][i] = visited[x];
    }

    int _max = 0;
    for (int i=1; i<=n; i++)
    {
        // printf("%d -> %d : %d\t%d -> %d : %d\n", i, x, dist[0][i], x, i, dist[1][i]);
        _max = max(_max, dist[0][i]+dist[1][i]);
    }
    // for (int i=1; i<=n; i++) _max = max(_max, dist[0][i]+dist[1][i]);

    printf("%d\n", _max);
    return 0;
}


/*
4 7 4
4 1 2
4 2 2
4 3 2
1 2 1
2 3 4
2 4 6
3 4 1



(2)   6   (4)

 1    4    1

(1)       (3)



*/