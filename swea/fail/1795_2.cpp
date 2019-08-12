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
        freopen("input_1795.txt", "r", stdin);
        int T; scanf("%d", &T);
        for (int tc=1, n, m, l; tc<=T; tc++)
        {
            int ans = 0, map[1000][1000];
            for (int i=0; i<1000; i++) 
            {
                for (int j=0; j<1000; j++) map[i][j] = INF;
                map[i][i] = 0;
            }
            scanf("%d%d%d", &n, &m, &l); l--;

            for (int i=0, a, b, c; i<m; i++)
            {
                scanf("%d%d%d", &a, &b, &c);
                map[a-1][b-1] = c;
            }

            for (int k=0; k<n; k++)
            {
                for (int i=0; i<n; i++)
                {
                    for (int j=0; j<n; j++)
                    {
                        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                    }
                }
            }

            for (int i=0; i<n; i++) ans = max(ans, map[i][l]+map[l][i]);

            printf("#%d %d\n", tc, ans);
        }
        return 0;
    }
