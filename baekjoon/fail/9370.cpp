/**
 * 19.06.28. 05:27 ~
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int t;
int n, m, candidate;
int s, g, h;
int cp_map[2001][2001], map[2001][2001];

vector<int> candidates;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++)
    {
        priority_queue<pair<int, pair<bool, int>>> pq;
        vector<int> vt[2001];
        int ans = 987654321;

        scanf("%d%d%d", &n, &m, &candidate);
        for(int i=1; i<=n; i++) for (int j=1; j<=n; j++) map[i][j] = 0;
        for (int j=1; j<=n; j++) map[0][j] = 987654321;
        scanf("%d%d%d", &s, &g, &h);
        for (int i=0, a, b, d; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            map[a][b] = d;
            map[b][a] = d;
            vt[a].push_back(b);
            vt[b].push_back(a);
            if (a == s) pq.push({-d, {false, b}});
            else if (b == s) pq.push({-d, {false, a}});
        }
        for (int i=0, a; i<candidate; i++)
        {
            scanf("%d", &a);
            candidates.push_back(a);
        }
        
        while (!pq.empty())
        {
            pair<int, pair<bool, int>> tp = pq.top(); pq.pop();
            int point = tp.second.second;            
            int d = -tp.first;
            bool is_cross = tp.second.first;
            if (map[0][point] <= d) continue;
            map[0][point] = d;

            if (ans < d) break;
            bool is_candidate = false;
            for (int cand : candidates) if (cand == point) { is_candidate = true; break; }

            if (is_candidate)
            {
                    printf("is candidate %d\n", point); 
                if(is_cross)
                {
                    ans = d;
                    printf("%d ", point);
                }
                continue;
            }
            else
            {
                if (point == g)
                {
                    if (!is_cross)
                    {
                        pq.push({-d-map[g][h], {true, h}});
                        continue;
                    }
                    for (int i : vt[point])
                    {
                        if (i == h) pq.push({-d-map[point][i], {true, i}});
                        else pq.push({-d-map[point][i], {false, i}});
                    }
                }
                else if (point == h)
                {
                    if (!is_cross)
                    {
                        pq.push({-d-map[g][h], {true, g}});
                        continue;
                    }
                    for (int i : vt[point])
                    {
                        if (i == g) pq.push({-d-map[point][i], {true, i}});
                        else pq.push({-d-map[point][i], {false, i}});
                    }
                }
                else
                    for (int i : vt[point]) pq.push({-d-map[point][i], {is_cross, i}});
                printf("else, point : %d\tpq.size() : %ld\n", point, pq.size()); 
            }
        }
        printf("\n");
    }
    return 0;
}


/*
1
5 4 2
1 2 3
1 2 6
2 3 2
3 4 4
3 5 3
5
4
 */