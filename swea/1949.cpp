#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 8

typedef pair<int, int> pii;

int n, k, map[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pii> heights;
int maxhi, answer, dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void init()
{
    heights.clear();
    maxhi = 0, answer = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    {
        cin >> map[i][j];
        if (maxhi < map[i][j])
        {
            heights.clear();
            maxhi = map[i][j];
        }
        if (maxhi == map[i][j]) heights.push_back({i, j});
    } 
}

void dfs(pii point, int cnt, bool chance)
{
    answer = max(answer, cnt);
    for (int di=0; di<4; di++)
    {
        int nr = point.first + dir[di][0];
        int nc = point.second + dir[di][1];

        if (!chk(nr, nc)) continue;
        if (visited[nr][nc]) continue;

        if (map[point.first][point.second] > map[nr][nc])
        {
            visited[nr][nc] = true;
            dfs({nr, nc}, cnt+1, chance);
            visited[nr][nc] = false;
        }
        else if (map[point.first][point.second] > map[nr][nc] - k && chance)
        {
            int tmp = map[nr][nc];

            map[nr][nc] = map[point.first][point.second] -1;
            visited[nr][nc] = true;
            dfs({nr, nc}, cnt+1, false);
            visited[nr][nc] = false;
            map[nr][nc] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1949_input.txt", "r", stdin);
    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        for (auto x : heights)
        {
            memset(visited, false, sizeof(visited));
            visited[x.first][x.second] = true;
            dfs(x, 1, true);
        }

        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}
