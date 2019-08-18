/**
 * 19.4.10. 15:02~ 16:10
 */
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int n, m, d, map[16][16], sol;
int archer[3], cpmap[16][16], visited[16][16];
int dir[3][2] = { {0, -1}, {-1, 0}, {0, 1} };
queue<pair<int, int>> qu;
vector<pair<int, int>> monster;
int turn_;

bool bfs(int row, int col)
{
    visited[row][col] = true;
    if (cpmap[row][col] ==1)
    {
        monster.push_back({row, col});
        queue<pair<int, int>> emptyQ;
        swap(qu, emptyQ);
        return true;
    }
    for (int i=0; i<3; i++)
    {
        int newRow = row + dir[i][0];
        int newCol = col + dir[i][1];
        if (!(0<=newRow&&newRow<n-turn_&&0<=newCol&&newCol<m)) continue;
        if (visited[newRow][newCol]) continue;
        
        qu.push({newRow, newCol});
    }
    return false;
}

void go()
{
    int ret = 0;
    vector<pair<int, int>> emptyVec;
    swap(emptyVec, monster);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        cpmap[i][j] = map[i][j];
        visited[i][j] = false;
    }
    for (turn_ = 0; turn_<n; turn_++)
    {
        for (int arc=0; arc<3; arc++)
        {
            queue<pair<int, int>> emptyQ;
            swap(qu, emptyQ);
            for (int i=0; i<n; i++) for (int j=0; j<m; j++) visited[i][j] = false;
            
            qu.push({n-turn_-1, archer[arc]});
            int range = d;
            while(!qu.empty() && range--)
            {
                long sz = qu.size();
                while(sz--)
                {
                    pair<int, int> f = qu.front();
                    qu.pop();
                    if(bfs(f.first, f.second)) break;
                }
            }
        }
        for (auto x : monster)
        {
            if (cpmap[x.first][x.second] == 1) 
            {
                ret++;
                // printf("%d %d\n", x.first, x.second);
            }
            cpmap[x.first][x.second] = 0;
        }
    }
    
    sol = max(sol, ret);
    
}

void dfs(int start ,int archerCnt)
{
    if (archerCnt == 3)
    {
        go();
        return;
    }
    for (int i=start; i<m; i++)
    {
        archer[archerCnt] = i;
        dfs(i+1, archerCnt+1);
        archer[archerCnt] = -1;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &m, &d);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);

    int turn =0;
    for (int i=0; i<m-2; i++)
    {
        dfs(i, 0);
    }

    printf("%d\n",sol);

    return 0;
}
