#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, p[10], total_p, ans = -1;
bool map[10][10];
vector<vector<int>> connected;
vector<bool> team;

bool canTeam(vector<int>& a)
{
    vector<bool> visited(n, true);
    int szTeam = a.size();
    if (szTeam == 0) return false;
    for (auto x : a) visited[x] = false;
    szTeam--;
    queue<int> qu;
    qu.push(a[0]);
    visited[a[0]] = true;
    while (!qu.empty())
    {
        int f = qu.front();
        qu.pop();
        for (int nxt : connected[f])
        {
            if (visited[nxt]) continue;
            visited[nxt] = true;
            szTeam--;
            qu.push(nxt);
        }
    }
    return szTeam == 0;
}

void dfs(vector<bool>& team, int idx, int sumP)
{
    vector<int> teamA, teamB;
    if (idx == n)
    {
        for (int i=0; i<n; i++)
        {
            if (team[i]) teamA.push_back(i);
            else teamB.push_back(i);
        }

        if (canTeam(teamA) && canTeam(teamB))
        {
            int diff = 2*sumP < total_p?total_p - 2 * sumP: 2 * sumP - total_p;
            if (ans == -1) ans = diff;
            else ans = ans<diff?ans:diff;
        }
    }
    else
    {
        dfs(team, idx+1, sumP);
        team[idx] = true;
        dfs(team, idx+1, sumP+p[idx]);
        team[idx] = false;
    }
}

int main(int argc, char const *argv[])
{
    // 초기화 과정
    scanf("%d", &n);
    connected.resize(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", p+i);
        total_p += p[i];
    }
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        for (int j=0, b; j<a; j++)
        {
            scanf("%d", &b);
            map[i][b-1] = true;
            connected[i].push_back(b-1);
        }
    }
    team.resize(n);
    team[0] = true;

    dfs(team, 1, p[0]);

    printf("%d\n", ans);

    return 0;
}
