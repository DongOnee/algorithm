    /**
     * 19.7.3. 21:41 ~
     */
    #include <cstdio>
    #include <queue>
    #include <vector>
    using namespace std;

    #define INF 987654321

    int main(int argc, char const *argv[])
    {
        // freopen("input_1795.txt", "r", stdin);
        int T; scanf("%d", &T);
        for (int tc=1, n, m, l; tc<=T; tc++)
        {
            int ans = 0, map[1000][1000];
            for (int i=0; i<1000; i++) for (int j=0; j<1000; j++) map[i][j] = INF;
            scanf("%d%d%d", &n, &m, &l); l--;

            vector<vector<int>> to_vector(n);
            vector<vector<int>> from_vector(n);
            int dst_to[1000];
            int dst_from[1000];
            for (int i=0; i<n; i++)
            {
                dst_to[i] = INF;
                dst_from[i] = INF;
            }

            for (int i=0, a, b, c; i<m; i++)
            {
                scanf("%d%d%d", &a, &b, &c);
                map[a-1][b-1] = c;
                from_vector[b-1].push_back(a-1);
                to_vector[a-1].push_back(b-1);
            }

            priority_queue<pair<int, int>> pq;
            pq.push({0, l});
            while (!pq.empty())
            {
                pair<int, int> tp = pq.top(); pq.pop();
                if (-tp.first >= dst_to[tp.second]) continue;
                dst_to[tp.second] = -tp.first;
                for (int i=0; i<to_vector[tp.second].size(); i++)
                {
                    int x = to_vector[tp.second][i];
                    if (dst_to[tp.second] + map[tp.second][x] >= dst_to[x]) continue;
                    pq.push({tp.first-map[tp.second][x], x});
                }
            }

            priority_queue<pair<int, int>> pq2;
            pq2.push({0, l});
            while (!pq2.empty())
            {
                pair<int, int> tp = pq2.top(); pq2.pop();
                if (-tp.first >= dst_from[tp.second]) continue;
                dst_from[tp.second] = -tp.first;
                for (int i=0; i<from_vector[tp.second].size(); i++)
                {
                    int x = from_vector[tp.second][i];
                    if (map[x][tp.second] + dst_from[tp.second] >= dst_from[x]) continue;
                    pq2.push({tp.first-map[x][tp.second], x});
                }
            }

            for (int i=0; i<n; i++) ans = max(ans, dst_from[i]+dst_to[i]);

            printf("#%d %d\n", tc, ans);
        }
        return 0;
    }
