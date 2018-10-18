#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int **map, **visited;
int maxChance, height, width;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int dir_horse[8][2] = { {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1} };

typedef struct node {
    pair<int, int> point;
    int countChance;
}N;

queue<N> q;

bool chk(int row, int col) {return 0<=row && row<height && 0<=col && col<width;}

void bfs(int row, int col, int chance) {
    int _row = row;
    int _col = col;
    int _chance = chance;

    for (int i=0; i<4; i++)
    {
        int new_row = _row + dir[i][0];
        int new_col = _col + dir[i][1];
        if (!chk(new_row, new_col)) continue;
        if (map[new_row][new_col] == 1) continue;

        if (visited[new_row][new_col] < _chance)
        {
            N tmp={make_pair(new_row, new_col), _chance};
            q.push(tmp);
            visited[new_row][new_col] = _chance;
        }
    }

    if (_chance-- == 0) return;

    for (int i=0; i<8; i++)
    {
        int new_row = _row + dir_horse[i][0];
        int new_col = _col + dir_horse[i][1];
        if (!chk(new_row, new_col)) continue;
        if (map[new_row][new_col] == 1) continue;

        if (visited[new_row][new_col] < _chance)
        {
            N tmp={make_pair(new_row, new_col), _chance};
            q.push(tmp);
            visited[new_row][new_col] = _chance;
        }
    }
}

int main(void) {
    cin >> maxChance >> width >> height;

    map = new int*[height];
    visited = new int*[height];
    for (int row=0; row<height; row++)
    {
        map[row] = new int[width];
        visited[row] = new int[width];
        for (int col=0; col<width; col++)
        {
            cin >> map[row][col];
            visited[row][col] = -1;
        }
    }

    N init = {make_pair(0, 0), maxChance};
    visited[0][0] = maxChance;
    q.push(init);
    int ret = 0;
    bool isRun = true;
    while(!q.empty() && isRun)
    {
        int qs = q.size();
        while(qs--)
        {
            int row = q.front().point.first;
            int col = q.front().point.second;
            int chance = q.front().countChance;
            q.pop();

            if (row == height-1 && col == width -1)
            {
                isRun = false;
                break;
            }
            bfs(row, col, chance);
        }
        if (isRun) ret++;
    }

    if (visited[height-1][width-1] == -1) printf("-1\n");
    else printf("%d\n", ret);

    return 0;
}

/*
1
5 5
0 0 0 0 0
1 1 1 1 0
1 0 0 0 0
1 1 1 1 1
1 1 0 0 0
*/
