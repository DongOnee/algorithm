/**
 * 19.2.27.
 */
#include <cstdio>

int N, M, comp[101][101];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);

    for (int i=0, a, b; i<M; i++)
    {
        scanf("%d %d", &a, &b); // a > b
        comp[a][b] = 1, comp[b][a] = -1;
    }

    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
        {
            if (i==j) continue;
            if (comp[i][j] != 0) continue;
            comp[i][j] = (comp[i][k] == comp[k][j] ? comp[i][k] : 0);
        }
    
    for (int i=1; i<=N; i++)
    {
        int cnt=-1;
        for (int j=1; j<=N; j++) if (comp[i][j]==0) cnt++;
        printf("%d\n", cnt);
    }

    return 0;
}
