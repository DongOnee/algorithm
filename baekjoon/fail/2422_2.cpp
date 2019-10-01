/**
 * 2019.10.01. 22:34 ~ 22:52
 * Fail
 */
#include <cstdio>

int n, m;
bool visited[201];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        ans += n-2;
        if (visited[a]) ans -= 1;
        if (visited[b]) ans -= 1;
        visited[a] = true, visited[b] = true;
    }

    printf("%d\n", n * (n-1) * (n-2) / 6 - ans);
    return 0;
}
