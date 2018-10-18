/**
 * BFS / DFS 모두 이용하는 문제
 * DFS 를 이용하여 각 육지들을 넘버링 한다.
 * BFS 를 이용하여 각 육지에서 최단 거리를 찾는다.
 * */

#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int** map;
bool** visited;
int size;
int culture_count;

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

bool chk(int x, int y) {return 0<=x && x<size && 0<=y && y<size;}

void dfs(int row, int col, int culture_flag) {
    int _x = row;
    int _y = col;
    int _flag = culture_flag;

    visited[_x][_y] = true;
    map[_x][_y] = _flag;

    for(int i=0; i<4; i++)
    {
        int _xx = _x + dir[i][0];
        int _yy = _y + dir[i][1];

        if (chk(_xx, _yy) && map[_xx][_yy] && !visited[_xx][_yy]) dfs(_xx, _yy, _flag);
    }
}

int bfs(int flag) {
    queue<pair<int, int> > q;
    for (int i=0; i<size; i++) for (int j=0; j<size; j++) visited[i][j] = false;

    for (int i=0; i<size; i++) 
        for (int j=0; j<size; j++)
        {
            if(map[i][j] == flag)
            {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }

    int ret = 0;
    while(!q.empty())
    {
        int qs = q.size();
        while(qs--){
            int _x = q.front().first;
            int _y = q.front().second;
            q.pop();

            for (int dir_index=0; dir_index<4; dir_index++)
            {
                int _xx = _x +dir[dir_index][0];
                int _yy = _y +dir[dir_index][1];

                if (!chk(_xx, _yy)) continue;
                if (map[_xx][_yy] != 0 && map[_xx][_yy] != flag) return ret;
                if (map[_xx][_yy] == 0 && !visited[_xx][_yy])
                {
                    visited[_xx][_yy] = true;
                    q.push(make_pair(_xx, _yy));
                }
            }
        }
        ret++;
    }
    return 2*size;
}

int main(void) {
    cin >> size;
    culture_count = 0;

    map = new int*[size];
    visited = new bool*[size];

    for (int i=0; i<size; i++)
    {
        map[i] = new int[size];
        visited[i] = new bool[size];
        for (int j=0; j<size; j++)
        {
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }

    for (int row=0; row<size; row++)
        for (int col=0; col<size; col++)
            if (map[row][col] && !visited[row][col]) dfs(row, col, ++culture_count);
    
    int minimum = 2*size;
    for (int i=1; i<=culture_count; i++) minimum = min(minimum, bfs(i));
    printf("%d\n", minimum);

    return 0;
}
