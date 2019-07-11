/**
 * 2019.07.11. 08:11 ~
 */
#include <cstdio>

bool map[101][101];

int costs[4] = {0, 2, 4, 7};

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int tc=1,s, n; tc<=T; tc++)
    {
        scanf("%d%d", &s, &n);
        for (int i=0; i<s; i++) for (int j=0; j<s; j++) map[i][j] = false;
        for (int i=0, r, c; i<n; i++)
        {
            scanf("%d%d", &r, &c);
            map[r][c] = true;
        }
    }
    return 0;
}
