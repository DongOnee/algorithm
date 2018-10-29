#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int **map;
bool **visited;
int size;
int ret;

queue<pair<int, int>> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool chk(int row, int col) { return 0<=row && row<size && 0<=col && col<size; }

void bfs(int row, int col) {
    visited[row][col] = true;
    map[row][col] = ret;
    
    for (int index=0; index<4; index++)
    {
        int new_row = row + dir[index][0];
        int new_col = col + dir[index][1];

        if (chk(new_row, new_col))
        {
            if (map[new_row][new_col] == 1 && !visited[new_row][new_col]) bfs(new_row, new_col);
        }
    }
}

void fullSearch(int row, int col) {
    if (map[row][col] != 0)
    {
        if (!visited[row][col]) 
        {
            bfs(row, col);
            ret++;
        }
    }
    for (int i=0; i<2; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];
        if(chk(new_row, new_col)) if(!visited[row][col]) q.push({row, col});
    }
}

int main(void) {
    ret = 1;
    cin >> size;
    map = new int*[size];
    visited = new bool*[size];
    for (int i=0; i<size; i++)
    {
        map[i] = new int[size];
        visited[i] = new bool[size];
        int tmp;
        cin >> tmp;
        for (int j=size-1; 0<=j; j--)
        {
            map[i][j] = tmp%10;
            tmp /= 10;
            visited[i][j] = false;
        }
    }

    q.push({0, 0});
    for (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        fullSearch(row, col);
    }

    int sol[ret];
    for (int i=0; i<ret; i++) sol[i] = 0;
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            if (map[i][j] == 0) continue;
            sol[map[i][j]-1]++;
        }
    }
    printf("%d\n", ret);
    for (int i=0; i<ret-1; i++) {
        int min_index = 0;
        for (int j=0; j<ret-1; j++) if (sol[min_index] > sol[j] ) min_index = j;
        printf("%d\n", sol[min_index]);
        sol[min_index] = size*size;
    }

}