/**
 * 2019.06.28. 10:26 ~ 15:38 
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t;
int map[2001][2001], cnt[2][2001];
vector<int> nears[2001];
priority_queue<pair<int, pair<bool, int>>> pq;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case=0, n, m, cnt_candidate, start, g, h; test_case<t; test_case++)
    {
        vector<int> ans_vect;
        scanf("%d%d%d%d%d%d", &n, &m, &cnt_candidate, &start, &g, &h);
        for (int i=0; i<=n; i++)
        {
            for (int j=1; j<=n && 0<i; j++) map[i][j] = 987654321;
            // nears[i].clear();
            vector<int> empty_vt;
            nears[i].swap(empty_vt);
            cnt[0][i] = 987654321, cnt[1][i] = 987654321;
        }
        priority_queue<pair<int, pair<bool, int>>> empty_pq; swap(pq, empty_pq);
        for (int i=0, a, b, d; i<m; i++)
        {
            scanf("%d%d%d", &a, &b, &d);
            map[a][b] = d;
            map[b][a] = d;
            nears[a].push_back(b);
            nears[b].push_back(a);
        }
        for (int i=0, a; i<cnt_candidate; i++)
        {
            scanf("%d", &a);
            nears[0].push_back(a);
        }

        pq.push({0, {false, start}});
        cnt[false][start] = 0;
        while (!pq.empty())
        {
            int distance = -pq.top().first;
            int current_point = pq.top().second.second;
            bool is_success = pq.top().second.first;
            pq.pop();
            // printf("%d %d %d\n", current_point, is_success, distance);

            // if (cnt[is_success][current_point] <= distance) continue;
            // else cnt[is_success][current_point] = distance;

            bool find_goal = false;
            for (vector<int>::iterator itr = nears[0].begin(); itr != nears[0].end(); itr++)
            {
                if (*itr == current_point)
                {
                    if (is_success)
                    {
                        ans_vect.push_back(current_point);
                        find_goal = true;
                        nears[0].erase(itr);
                    }
                    else nears[0].erase(itr);
                    break;
                }
            }
            // if (find_goal) continue;

            for (int next_point : nears[current_point])
            {
                bool next_success = ((current_point == g && next_point == h) || (current_point == h && next_point == g) ? true : is_success);
                if (distance + map[current_point][next_point] <= cnt[next_success][next_point] )
                {
                    cnt[next_success][next_point] = distance + map[current_point][next_point];
                    pq.push({-cnt[next_success][next_point], { next_success, next_point}});
                }
            }
        }

        sort(ans_vect.begin(), ans_vect.end());
        for (int x : ans_vect) printf("%d ", x);
        printf("\n");
    }
    return 0;
}
