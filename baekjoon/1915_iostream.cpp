/**
 * 2019.08.07. ~ 21:31
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define _MAXNM 1000

#define MMIN(a, b, c) min(min(a, b), c)

int n, m, map[_MAXNM][_MAXNM], ans;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            char input;
            cin >> input;
            map[i][j] = input - '0';
            if (map[i][j] == 1) ans = max(1, ans);
            if (i>0 && j>0 && map[i][j] == 1)
            {
                if (map[i-1][j] != 0 && map[i-1][j-1] != 0 && map[i][j-1] != 0)
                {
                    int minv = MMIN(map[i-1][j], map[i-1][j-1], map[i][j-1]);
                    map[i][j] = minv+1;
                    ans = max(ans, minv+1);
                }
            }
        }
    }

    cout << ans*ans << '\n';

    return 0;
}
