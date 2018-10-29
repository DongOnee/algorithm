#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int **map;
bool **visited;
int size;
int ret;
int sol[25*25/2+1];

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row && row<size && 0<=col && col<size; }

void dfs(int row, int col) {
    map[row][col] = ret;
    visited[row][col] = true;

    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];

        if(!chk(new_row, new_col)) continue;
        if(!visited[new_row][new_col] && map[new_row][new_col] != 0) dfs(new_row, new_col);
    }
}

int main(void) {
    cin >> size;
    map = new int*[size];
    visited = new bool*[size];
    for (int i=0; i<size; i++)
    {
        map[i] = new int[size];
        visited[i] = new bool[size];
        for (int j=0; j<size; j++)
        {
            scanf("%1d", &map[i][j]);
            visited[i][j] = false;
        }
    }

    ret = 0;
    for (int row=0; row<size; row++)
    {
        for (int col=0; col<size; col++)
        {
            if (map[row][col] == 0) continue;
            if (!visited[row][col]) {
                sol[ret++] = 0;
                dfs(row, col);
            }
            sol[map[row][col]-1]++;
        }
    }

    printf("%d\n", ret);
    sort(sol, sol+ret);

    for (int i=0; i<ret; i++) printf("%d\n", sol[i]);

/*
    for (int row=0; row<size; row++)
    {
        for (int col=0; col<size; col++) cout << map[row][col] << " ";
        cout << endl;
    }
*/
    return 0;
}