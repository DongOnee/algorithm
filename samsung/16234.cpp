/**
 * 19.4.9. 14:11~14:56
 */
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n, l, r, map[51][51];
bool visited[51][51];
queue<pair<int, int>> q;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

int bfs(int row, int col)
{
    visited[row][col] = true;
    int ret = map[row][col];
    q.push(make_pair(row, col));
    for (int i=0; i<4; i++)
    {
        int newRow = row +dir[i][0];
        int newCol = col +dir[i][1];
        if (!chk(newRow, newCol)) continue;
        if (visited[newRow][newCol]) continue;

        int diff = abs(map[row][col] - map[newRow][newCol]);
        if (l<= diff && diff <= r) ret += bfs(newRow, newCol);
    }
    return ret;
}

void dfs(int row, int col, bool* isChange)
{
    if (!chk(row, col)) return;
    if (!visited[row][col])
    {
        int sum = bfs(row, col);
        int av = sum/q.size();
        while (!q.empty())
        {
            pair<int, int> f = q.front();
            q.pop();
            if (map[f.first][f.second] != av) *isChange = true;
            map[f.first][f.second] = av;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &l, &r);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    bool isChange = true;
    int sol = 0;
    while (isChange)
    {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) visited[i][j] = false;
        isChange = false;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) dfs(i, j, &isChange);
        if (isChange) sol++;
    }

    printf("%d\n", sol);
    return 0;
}
