/**
 * 19.4.13. 00:00~1:10
 */
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int cube[5][5][5], states[5], sol, height[5];
bool visited[5][5][5], floors[5];

int dir[8][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
queue<pair<int, pair<int, int>>> qu;

bool chk(pair<int, pair<int, int>> point)
{
    int curFloor = point.first;
    int curRow = point.second.first;
    int curCol = point.second.second;
    return 0<=curRow&&0<=curCol&&0<=curFloor&&curRow<5&&curCol<5&&curFloor<5;
}

pair<int, int> convertLoc(int row, int col, int state)
{
    if (state == 0) return {row, col};
    else if (state == 1) return {col, 4-row};
    else if (state == 2) return {4-row, 4-col};
    else return {4-col, row};
}

bool bfs(pair<int, pair<int, int>> input_)
{
    int curFloor = input_.first;
    int curRow = input_.second.first;
    int curCol = input_.second.second;
    for (int i=0; i<8; i++)
    {
        int nextFloor = curFloor+dir[i][0];
        int nextRow = curRow+dir[i][1];
        int nextCol = curCol+dir[i][2];
        if (!chk({nextFloor, {nextRow, nextCol}})) continue;
        if (visited[nextFloor][nextRow][nextCol]) continue;
        if (nextFloor==4 && nextRow==4 && nextCol==4) return true;
        pair<int, int> converted = convertLoc(nextRow, nextCol, states[height[nextFloor]]);
        if (cube[height[nextFloor]][converted.first][converted.second] == 0) continue;
        visited[nextFloor][nextRow][nextCol] = true;
        qu.push({nextFloor, {nextRow, nextCol}});
    }
    return false;
}

void go()
{
    pair<int, int> x = convertLoc(0, 0, states[height[0]]);
    if (cube[height[0]][x.first][x.second] == 0) return ;
    x = convertLoc(4, 4, states[height[4]]);
    if (cube[height[4]][x.first][x.second] == 0) return ;

    for (int i=0; i<5; i++) for (int j=0; j<5; j++) for (int x=0; x<5; x++) visited[i][j][x] = false;
    queue<pair<int, pair<int, int>>> eq;
    swap(eq, qu);
    
    qu.push({0, {0, 0}});
    visited[0][0][0]= true;
    int t=0;
    while (!qu.empty())
    {
        t++;
        long sz = qu.size();
        // printf("%ld", sz);
        while (sz--)
        {
            pair<int, pair<int, int>> f = qu.front(); qu.pop();
            if (bfs(f))
            {
                sol = min(sol, t);
                return ;
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<5; i++) for (int j=0; j<5; j++) for (int x=0; x<5; x++) scanf("%d", &cube[i][j][x]);
    sol = 987654321;
    
    for (int a=0; a<5; a++)
    {
        floors[a] = true;
        height[0] = a;
        for (int b=0; b<5; b++)
        {
            if (floors[b]) continue;
            floors[b] = true;
            height[1] = b;
            for (int c=0; c<5; c++)
            {
                if (floors[c]) continue;
                floors[c] = true;
                height[2] = c;
                for (int d=0; d<5; d++)
                {
                    if (floors[d]) continue;
                    floors[d] = true;
                    height[3] = d;
                    for (int e=0; e<5; e++)
                    {
                        if (floors[e]) continue;
                        height[4] = e;
                        for (states[0]=0; states[0]<4; states[0]++)
                        for (states[1]=0; states[1]<4; states[1]++)
                        for (states[2]=0; states[2]<4; states[2]++)
                        for (states[3]=0; states[3]<4; states[3]++)
                        for (states[4]=0; states[4]<4; states[4]++) go();
                    }
                    floors[d] = false;
                }
                floors[c] = false;
            }
            floors[b] = false;
        }
        floors[a] = false;
    }

    printf("%d\n", (sol==987654321?-1:sol));

    return 0;
}
