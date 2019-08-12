/**
 * 19.4.10. 18:54~19:18 / 19:47
 */
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n, map[33][33];
long long sol;
bool visited[33][33][3];
long long memorize[33][33][3];
queue<pair<pair<int, int>, int>> qu;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

vector<pair<pair<int, int>, int>> dir[3]={
    {{{0, 1}, 0}, {{1, 1}, 2}},
    {{{1, 0}, 1}, {{1, 1}, 2}},
    {{{0, 1}, 0}, {{1, 0}, 1}, {{1, 1}, 2}}
};

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    qu.push({{0, 1}, 0});
    visited[0][1][0] = true;
    memorize[0][1][0] = 1;

    while(!qu.empty())
    {
        pair<pair<int, int>, int> f = qu.front();
        qu.pop();
        int pointRow = f.first.first;
        int pointCol = f.first.second;
        int pointDir = f.second;
        for (auto x : dir[pointDir])
        {
            int nextRow = pointRow + x.first.first;
            int nextCol = pointCol + x.first.second;
            int nextDir = x.second;
            if (!chk(nextRow, nextCol)) continue;
            if (nextDir == 2 && (map[pointRow][nextCol] || map[nextRow][pointCol])) continue;
            if (map[nextRow][nextCol]) continue;
            if (!visited[nextRow][nextCol][nextDir])
            {
                visited[nextRow][nextCol][nextDir] = true;
                qu.push({{nextRow, nextCol}, nextDir});
            }
            memorize[nextRow][nextCol][nextDir] += memorize[pointRow][pointCol][pointDir];
        }
    }

    printf("%lld\n", memorize[n-1][n-1][0]+ memorize[n-1][n-1][1]+ memorize[n-1][n-1][2]);

    return 0;
}