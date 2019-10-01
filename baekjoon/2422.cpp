/**
 * 2019.10.02. 08:48 ~
 */
#include <cstdio>

int n, m;
bool excepted[201][201];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        excepted[a][b] = true;
        excepted[b][a] = true;
    }

    int ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            for (int k=j+1; k<=n; k++)
            {
                if (!(excepted[i][j] || excepted[j][k] || excepted[k][i])) ans++;
            }

    printf("%d\n", ans);

    return 0;
}