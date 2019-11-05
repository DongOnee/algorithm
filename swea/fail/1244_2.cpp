#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, ans, cnt;

void dfs(int s, int c)
{
    if (c%2==0) ans = ans>s?ans:s;
    if (c > 0)
    {
        for (int i=1; i<n; i *= 10)
        {
            for (int j=1; j<n; j*= 10)
            {
                if (i == j) continue;
                int a = s;
                int b = a/i%10, bb = a/j%10;
                dfs(a-b*i+bb*i-bb*j+b*j, c-1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("1244_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        ans = 0;
        scanf("%d%d", &n, &k);
        dfs(n, k);
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
