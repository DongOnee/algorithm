/**
 * 19.2.26.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int N, map[101][101];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i=0; i<N; i++) for (int j=0; j<N; j++) scanf("%d", &map[i+1][j+1]);
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (!map[i+1][j+1]) map[i+1][j+1] = 1e9;
    
    for (int k=1; k<=N; k++)
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=N; j++)
            printf("%d ", (map[i][j] == 1e9 ? 0 : 1));
        printf("\n");
    }
    return 0;
}
