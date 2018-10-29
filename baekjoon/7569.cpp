#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct point{
    int layer;
    int row;
    int col;
}Node;

queue<Node> q;
int ***map;
int ***visited;
int count_layers, count_rows, count_columns;
int dir[8][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

bool chk(int layer, int row, int col) { return 0<=layer && layer<count_layers && 0<=row && row<count_rows && 0<=col && col<count_columns; }

void bfs(int layer, int row, int col) {
    visited[layer][row][col] = 1;

    for (int i=0; i<8; i++)
    {
        int new_layer = layer + dir[i][0];
        int new_row = row + dir[i][1];
        int new_col = col + dir[i][2];

        if(chk(new_layer, new_row, new_col))
        {
            if (!visited[new_layer][new_row][new_col] && map[new_layer][new_row][new_col]==0)
            {
                q.push({new_layer, new_row, new_col});
                map[new_layer][new_row][new_col]=1;
            }
        }
    }
}

int main(void) {
    cin >> count_columns >> count_rows >> count_layers;

    map = new int**[count_layers];
    visited = new int**[count_layers];
    for (int layer=0; layer<count_layers; layer++)
    {
        map[layer] = new int*[count_rows];
        visited[layer] = new int*[count_rows];
        for (int row=0; row<count_rows; row++)
        {
            map[layer][row] = new int[count_columns];
            visited[layer][row] = new int[count_columns];
            for (int col=0; col<count_columns; col++)
            {
                cin >> map[layer][row][col];
                visited[layer][row][col] = 0;
                if (map[layer][row][col] == 1) q.push({layer, row, col});
            }
        }
    }

    int ret=0 ;
    while(!q.empty())
    {
        ret++;
        int qs = q.size();
        while(qs--)
        {
            int front_layer = q.front().layer;
            int front_row = q.front().row;
            int front_col = q.front().col;
            q.pop();

            bfs(front_layer, front_row, front_col);
        }
    }

    for(int i=0;i<count_layers;i++)for(int j=0;j<count_rows;j++)for(int k=0;k<count_columns;k++)if(map[i][j][k]==0){
        i=count_layers;j=count_rows;k=count_columns;
        ret=0;
    }
    printf("%d\n", ret-1);

    return 0;
}