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
            visited[row][col] = 0;
        }
    }

    N init = {make_pair(0,0), maxChance};
    visited[0][0] = 1;
    q.push(init);
    int ret = 0;
    while(!q.empty())
    {
        int qs = q.size();
        while(qs--)
        {
            int row = q.front().point.first;
            int col = q.front().point.second;
            int chance = q.front().countChance;

            
        }
    }

    return 0;
}