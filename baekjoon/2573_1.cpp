#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int **map;
bool **visited;
int height, width;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

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
    if (_count != 0) minus_q.push(make_pair(make_pair(row, col), _count));
}

void dfs(int row, int col) {
    visited[row][col] = true;
    point_q.push(make_pair(row, col));
    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];

        if(!chk(new_row, new_col)) continue;
        if(map[new_row][new_col] != 0 && !visited[new_row][new_col]) dfs(new_row, new_col);
    }
}

bool fullSearch() {
    bool finish = false;
    for (int i=1; i<height-1; i++) for (int j=1; j<width-1; j++) visited[i][j]=false;
    for (int row=1; row<height-1; row++)
    {
        for (int col=1; col<width-1; col++)
        {
            if (map[row][col] != 0)
            {
                if (visited[row][col]) continue;
                else if (finish) return false;
                dfs(row, col);
                finish = true;
            }
        }
    }
    return true;
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
        }
    }

    int ret = 0;
    while(fullSearch())
    {
        ret++;
        int qs = point_q.size();
        while(qs--)
        {
            int _row = point_q.front().first;
            int _col = point_q.front().second;
            point_q.pop();

            getIce(_row, _col);
        }
        qs = minus_q.size();
        while(qs--)
        {
            int _row = minus_q.front().first.first;
            int _col = minus_q.front().first.second;
            int _diff = minus_q.front().second;
            minus_q.pop();

            map[_row][_col] -= _diff;
            if (map[_row][_col] < 0) map[_row][_col] = 0;
        }
    }
    if (point_q.size() == 0) printf("0\n");
    else printf("%d\n", ret);
}


/**
 * 1. 풀 서치
 * 1-1. 덩어리 갯수
 * 1-2. 빙산들 q에 넣기
 * 2. 덩어리가 2이상이 나오는지 확인하고
 * 3. 각 빙산들의 minus 값 구하고
 * 4. map 업데이트
 */