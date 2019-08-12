/**
 * 19.4.13. 19:23~20:05
 */
#include <cstdio>
#include <queue>
using namespace std;

char map[12][7];
bool visited[12][6];
queue<pair<char, pair<int, int>>> qu;
queue<pair<int, int>> rmqu;
int sol;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool chk(int row, int col) { return 0<=row&&row<12&&0<=col&&col<6; }

void update()
{
    sol++;
    for (int j=0; j<6; j++)
    {
        for (int i=11, k=-1; 0<=i; i--)
        {
            if (map[i][j] != '.')
            {
                if (k==-1) continue;
                map[k][j] = map[i][j];
                map[i][j] = '.';
                k--;
            }
            else if (k==-1) k=i;
        }
    }
}

int dfs(char block, pair<int, int> point)
{
    rmqu.push(point);
    int ret = 1;
    visited[point.first][point.second] = true;
    for (int i=0; i<4; i++)
    {
        int nextRow = point.first+dir[i][0];
        int nextCol = point.second+dir[i][1];
        if (!chk(nextRow, nextCol)) continue;
        if (visited[nextRow][nextCol]) continue;
        if (map[nextRow][nextCol] != block) continue;
        ret += dfs(block, {nextRow, nextCol});
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<12; i++)
    {
        scanf("%s", map[i]);
        // for (int j=0; j<6; j++)
        // {
        //     if (map[i][j] == '.') continue;
        //     qu.push({map[i][j], {i, j}});
        // }
    }
    bool isChange = true;
    while (isChange)
    {
        isChange = false;
        for (int i=0; i<12; i++) for (int j=0; j<6; j++) 
        {
            visited[i][j]=false;
            if (map[i][j] != '.') qu.push({map[i][j], {i, j}});
        }
        long sz = qu.size();
        while (sz--)
        {
            pair<char, pair<int, int>> f = qu.front(); qu.pop();
            if (visited[f.second.first][f.second.second]) continue;
            int ret = dfs(f.first, f.second);
            if (ret<4)
            {
                queue<pair<int, int>> emptyqu;
                swap(emptyqu, rmqu);
            }
            else
            {
                while(!rmqu.empty())
                {
                    pair<int, int> s = rmqu.front(); rmqu.pop();
                    map[s.first][s.second] = '.';
                }
                isChange = true;
            }
        }
        if (isChange) update();
        else break;
    }


    for (int i=0; i<12; i++)
    {
        for (int j=0; j<6; j++) printf("%c", map[i][j]);
        printf("\n");
    }
    printf("%d\n", sol);

    return 0;
}


/*

......
......
......
......
......
......
......
......
......
.YGG..
RRYG..
RRYGG.

*/