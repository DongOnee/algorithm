/**
 * 19.2.27.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, X, map[1001][1001];

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &N, &M, &X);
    for (int i=0, start, end, time_; i<M; i++)
    {
        scanf("%d %d %d", &start, &end, &time_);
        map[start][end] = time_;
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) if (!map[i][j] && i!=j) map[i][j] = 1e9;

    printf("\n");
    printf("\n");
    for (int i=1; i<=N; i++) 
    {
        for (int j=1; j<=N; j++) printf("%11d ", map[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("\n");




    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++) for (int j=1; j<=N; j++)
            if (i==j) continue;
            else map[i][j] = min(map[i][j], map[i][k] + map[k][j]);





    printf("\n");
    printf("\n");
    for (int i=1; i<=N; i++) 
    {
        for (int j=1; j<=N; j++) printf("%11d ", map[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("\n");




    int max_  =0;
    for (int i=1; i<=N; i++)
    {
        if (i == X) continue;
        max_ = max(max_, map[i][X]+map[X][i]);
    }

    printf("%d\n", max_);
    return 0;
}
