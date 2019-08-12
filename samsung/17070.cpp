/**
 * 19.4.10. 18:54~19:18 / 19:47
 */
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int n, map[17][17], sol;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

vector<pair<pair<int, int>, int>> dir[3]={
    {{{0, 1}, 0}, {{1, 1}, 2}},
    {{{1, 0}, 1}, {{1, 1}, 2}},
    {{{0, 1}, 0}, {{1, 0}, 1}, {{1, 1}, 2}}
};

void dfs(int row, int col, int state)
{
    if (row == n-1 && col == n-1) sol++;
    else 
    {
        for (auto x : dir[state])
        {
            int nextRow = row + x.first.first;
            int nextCol = col + x.first.second;
            int nextState = x.second;
            if (!chk(nextRow, nextCol)) continue;
            if (map[nextRow][nextCol] == 1) continue;
            if (nextState == 2)
                if (map[row][nextCol] || map[nextRow][col]) continue;
            dfs(nextRow, nextCol, nextState);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    dfs(0, 1, 0);

    printf("%d\n", sol);

    return 0;
}
