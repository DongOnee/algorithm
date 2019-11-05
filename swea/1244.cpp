#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, k, ans, cnt;
bool visit[1000000][2];

int swapp(int input, int i, int j)
{
    int ii = input / i % 10, jj = input / j % 10;
    return input - ii * i + jj * i - jj * j + ii * j;
}

int main(int argc, char const *argv[])
{
    freopen("1244_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        ans = 0;
        memset(visit, false, sizeof(visit));
        queue<int> qu;
        scanf("%d%d", &n, &k);
        qu.push(n);
        visit[n][k%2] = true;

        while (k--)
        {
            long sz = qu.size();
            while (sz--)
            {
                int f = qu.front(); qu.pop();
                for (int i=1; i<n; i*=10) for (int j=1; j<n; j*=10)
                {
                    if (i == j) continue;
                    int aa =swapp(f, i, j);
                    if (visit[aa][k%2]) continue;
                    visit[aa][k%2] = true;
                    if (k >0)qu.push(aa);
                    if (k%2 ==0) ans = ans>aa?ans:aa;
                }
            }
        }

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
