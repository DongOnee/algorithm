/**
 * 19.2.18.
 * ref code. https://fatc.club/2017/03/01/1357
*/
#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int map[101][101];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) map[i+1][j+1] = (i == j ? 0 : 1e9);

    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        map[a][b] = min(map[a][b], c);
    }

    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) for (int k=1; k<=n; k++) map[j][k] = min(map[j][k], map[j][i] + map[i][k]);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) printf("%d ", map[i+1][j+1]>=(int)1e9?0:map[i+1][j+1]);
        puts("");
    }

    return 0;
}