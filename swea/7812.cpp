/**
 * 19.7.3. 13:55 ~ 14:12
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    // freopen("input_7812.txt", "r", stdin);
    int T; scanf("%d", &T);
    for (int t_c=1; t_c<=T; t_c++)
    {
        int n, m, ans = 0;
        vector<int> vt;

        scanf("%d%d", &n, &m);
        for (int i=0, a; i<n; i++)
        {
            scanf("%d", &a);
            vt.push_back(a);
        }

        queue<int> qu;
        int sum = 0, cnt = 0;
        while (cnt < n)
        {
            if (sum + vt[cnt] < m )
            {
                qu.push(vt[cnt]);
                sum += vt[cnt++];
            }
            else if (sum + vt[cnt] == m )
            {
                qu.push(vt[cnt]);
                sum += vt[cnt++];
                sum -= qu.front();
                qu.pop();
                ans++;
            }
            else
            {
                sum -= qu.front();
                qu.pop();
            }
        }
        printf("#%d %d\n", t_c, ans);
    }
    return 0;
}
