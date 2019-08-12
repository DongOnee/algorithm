/**
 * 19.2.26.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M, relation[101][101];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (j!=i) relation[i+1][j+1] = 1e9;

    for (int i=0, a, b; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
            {
                if (i == j) continue;
                relation[i][j] = min(relation[i][j], relation[i][k]+relation[k][j]);
                relation[j][i] = relation[i][j];
            }

    int min_ = 987654321, min_index = 0;
    for (int i=1; i<=N; i++)
    {
        int sum_=0;
        for (int j=1; j<=N; j++) sum_ += relation[i][j];
        if (sum_ < min_)
        {
            min_ = sum_;
            min_index = i;
        }
    }

    printf("%d\n", min_index);
    return 0;
}
