#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int **map;
bool **visited;
int height, width;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
bool isRun;

queue<pair<pair<int, int>, int> > minus_q;
queue<pair<int, int> > point_q;

bool chk(int row, int col) {return 0<=row && row<height && 0<=col && col<width;}

void getIce(int row, int col) {
    int _count = 0;
    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];
        
        if(!chk(new_row, new_col)) continue;
        if(map[new_row][new_col] == 0) _count++;
    }
    visited[row][col] = false;
    minus_q.push(make_pair(make_pair(row, col), _count));
}

void dfs(int row, int col) {
    visited[row][col] = true;
    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];

        if(!chk(new_row, new_col)) continue;
        if(map[new_row][new_col] != 0 && !visited[new_row][new_col]) dfs(new_row, new_col);
    }
}

int main(void) {
    cin >> height >> width;
    map = new int*[height];
    visited = new bool*[height];
    for (int row=0; row<height; row++)
    {
        map[row] = new int[width];
        visited[row] = new bool[width];
        for (int col=0; col<width; col++)
        {
            cin >> map[row][col];
            if (map[row][col] != 0) point_q.push(make_pair(row, col));
            visited[row][col] = false;
        }
    }

    isRun = true;
    int ret = 0;
    while(isRun)
    {
        int front_row = point_q.front().first;
        int front_col = point_q.front().second;
        int point_count = point_q.size();

        if (point_count == 0) break;
        dfs(front_row, front_col);

        while(point_count--)
        {
            front_row = point_q.front().first;
            front_col = point_q.front().second;
            point_q.pop();

            if (!visited[front_row][front_col])
            {
                isRun = false;
                break;
            }

            getIce(front_row, front_col);
        }

        int update_count = minus_q.size();
        while(isRun && update_count--)
        {
            int row = minus_q.front().first.first;
            int col = minus_q.front().first.second;
            int minus = minus_q.front().second;
            minus_q.pop();

            map[row][col] -= minus;
            if (map[row][col] <= 0) map[row][col]=0;
            else point_q.push(make_pair(row, col));
        }

        if(isRun)ret++;
    }
    if (isRun) printf("0\n");
    else printf("%d\n", ret);

    return 0;
}