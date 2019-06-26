/**
 * 19.06.10. 13:06 ~ 14:34
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, map[50][50], empty_cnt, ans;
vector<pair<int, int>> virus_list;
vector<int> virus_selected;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

void bfs()
{
    int remain_empty = empty_cnt;
    int cnt=0, cpmap[50][50];
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cpmap[i][j] = map[i][j];
    
    queue<pair<int, int>> virus_qu;
    for (int x : virus_selected)
    {
        virus_qu.push(virus_list[x]);
        cpmap[virus_qu.back().first][virus_qu.back().second] = -1;
    }
    
    while(remain_empty !=0)
    {
        cnt++;
        long sz = virus_qu.size();
        while(sz--)
        {
            pair<int, int> f = virus_qu.front(); virus_qu.pop();
            for (int i=0; i<4; i++)
            {
                int next_row = f.first+dir[i][0], next_col = f.second+dir[i][1];
                if (!chk(next_row, next_col)) continue;

                if (cpmap[next_row][next_col] == 0)
                {
                    remain_empty--;
                    virus_qu.push({next_row, next_col});
                    cpmap[next_row][next_col] = -1;
                }
                else if (cpmap[next_row][next_col] == 2)
                {
                    virus_qu.push({next_row, next_col});
                    cpmap[next_row][next_col] = -1;
                }
            }
        }
        if (virus_qu.size() == 0 && remain_empty != 0)
        {
            cnt = 987654321;
            break;
        }
    }
    
    ans = min(ans, cnt);
}

void dfs(int start, int cnt)
{
    if (cnt == m) bfs();
    else
    {
        for (int st = start; st<virus_list.size(); st++)
        {
            pair<int, int> choice = virus_list[st];

            virus_selected.push_back(st);
            map[choice.first][choice.second] = -1;
            dfs(st+1, cnt+1);
            virus_selected.pop_back();
            map[choice.first][choice.second] = 2;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    ans = 987654321, empty_cnt = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", map[i]+j);
            if (map[i][j] == 2) virus_list.push_back({i, j});
            else if (map[i][j] == 0) empty_cnt++;
        }
    }

    dfs(0, 0);

    printf("%d\n", (ans == 987654321 ? -1: ans));

    return 0;
}
