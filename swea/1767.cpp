#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 12
#define INF 987654321

typedef pair<int, int> pii;

int n, map[MAXN][MAXN], answer, answer2;
vector<pii> cores;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool chk(int r, int c) { return 0<=r&&r<n&&0<=c&&c<n; }

void deleteline(pii core, int di)
{
    while (true)
    {
        int nr = core.first + dir[di][0];
        int nc = core.second + dir[di][1];
        if (!chk(nr, nc)) break;
        map[nr][nc] = 0;
        core = {nr, nc};
    }
}

int setline(pii core, int di)
{
    int idx = 0;
    bool cancel = false;

    while (true)
    {
        int nr = core.first + dir[di][0];
        int nc = core.second + dir[di][1];
        if (!chk(nr, nc)) break;
        if (map[nr][nc] != 0)
        {
            cancel = true;
            break;
        }
        map[nr][nc] = 2;
        idx++;
        core.first = nr;
        core.second = nc;
    }

    for (int i = 0; i < idx && cancel; i++)
    {
        map[core.first][core.second] = 0;
        core.first -= dir[di][0];
        core.second -= dir[di][1];
    }
    
    return cancel?-1:idx;
}

void dfs(int idx, int sum, int cnt)
{
    if (idx == cores.size())
    { 
        if (cnt == answer2) answer = min(answer, sum);
        else if (cnt > answer2)
        {
            answer2 = cnt;
            answer = sum;
        }
    }
    else
    {
        for (int di=0; di<4; di++)
        {
            int a = setline(cores[idx], di);
            if (a == -1) continue;
            dfs(idx+1, sum+a, cnt+1);
            deleteline(cores[idx], di);
        }
        dfs(idx+1, sum, cnt);
    }
}

void init()
{
    answer = INF, answer2 = 0;
    cin >> n;
    cores.clear();
    for (int i=0; i<n; i++) for (int j=0; j<n; j++)
    {
        cin >> map[i][j];
        if (map[i][j] && 0<i && i < n-1 && 0<j && j <n-1) cores.push_back({i, j});
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1767_input.txt", "r", stdin);
    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        dfs(0, 0, 0);
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}
