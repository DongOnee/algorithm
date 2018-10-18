#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int** map;
int** visited;
int chance;
int height, width;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int dir_horse[8][2] = { {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1} };

queue<pair<pair<int, int>, int> > q;

bool chk(int x, int y) {return 0<=x && x<height && 0<=y && y<width;}

void bfs(int x, int y, int chn, int count) {
    int _x = x;
    int _y = y;
    int _chance = chn;

    for (int i=0; i<4; i++)
    {
        int _xx = _x + dir[i][0];
        int _yy = _y + dir[i][1];
        if (!chk(_xx, _yy)) continue;
        if (map[_xx][_yy] == 1 || visited[_xx][_yy] == 1) continue;
        
        q.push(make_pair(make_pair(_xx, _yy), _chance));
        visited[_xx][_yy] = 1;
    }

    _chance--;
    for (int i=0; i<8 && 0<=_chance; i++)
    {
        int _xx = _x + dir_horse[i][0];
        int _yy = _y + dir_horse[i][1];
        if (!chk(_xx, _yy)) continue;
        if (map[_xx][_yy] == 1 || visited[_xx][_yy] != 0) continue;
        
        q.push(make_pair(make_pair(_xx, _yy), _chance));
        visited[_xx][_yy] = 2;
    }
}

int main(int argc, char const *argv[])
{
    cin >> chance;
    cin >> width;
    cin >> height;

    map = new int*[height];
    visited = new int*[height];
    for (int row=0; row<height; row++)
    {
        map[row] = new int[width];
        visited[row] = new int[width];
        for (int col=0; col<width; col++)
        {
            cin >> map[row][col];
            visited[row][col] = 0;
        }
    }

    q.push(make_pair(make_pair(0, 0), chance));
    visited[0][0] = 1;
    bool isRun = true;
    int ret = -1;
    while(!q.empty() && isRun)
    {
        ret++;
        int qs = q.size();
        while(qs--)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int chn = q.front().second;
            q.pop();
            if (x==height-1 && y==width-1)
            {
                isRun = false;
                break;
            }
            bfs(x, y, chn, ret);
        }
    }
    if (visited[height-1][width-1] == 0 ) 
    {
        if (width == 1 && height == 1) printf("0\n");
        else printf("-1\n");
    }
    else printf("%d\n", ret);

    return 0;
}
