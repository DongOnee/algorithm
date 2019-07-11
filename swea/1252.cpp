/**
 * 2019.07.11. 08:11 ~
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool map[101][101];
vector<pair<int, int>> vt;

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
            vt.push_back({r+c, c});
        }

        sort(vt.begin(), vt.end());

        for (auto x : vt)
        {
            int row = x.first - x.second;
            int col = x.second;
            printf("%d %d\n", row, col);
        }
    }
    return 0;
}
