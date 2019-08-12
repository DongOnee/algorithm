/**
 * DFS 2 번을 이용하였다.
 * 첫번재 DFS 를 이용하여 mpa 을 초기화 하였고
 * 두번쨰 DFS 를 이용하여 진영의 숫자를 계산 하였다.
 * 이 문제는 BOJ 2146 문제를 참고 하였다.
 * 하지만 결과는 시간 초과를 하였고, 다른 방법을 찾아 보도록 하겠다.
 */
#include <iostream>
#include <cstdio>
using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool chk(int row, int col) { return 0<=row && row<5001 && 0<=col && col<5001; }

void dfs(int row, int col, int radar, int** map, bool** visited) {
    map[row][col] = 1;
    if (radar == 0) return;
    visited[row][col] = true;
    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];
        int new_radar = radar -1;

        if (!chk(new_row, new_col)) continue;
        if (!visited[new_row][new_col]) dfs(new_row, new_col, new_radar, map, visited);
    }
}

void dfs2(int row, int col, bool** visited) {
    visited[row][col] = false;

    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];

        if (!chk(new_row, new_col)) continue;
        if (visited[new_row][new_col]) dfs2(new_row, new_col, visited);
    }
}

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    // cin >> T;
    for (int test_case=0; test_case<T; test_case++)
    {

        int **map = new int*[5001];
        bool **visited = new bool*[5001];
        for (int i=0; i<5001; i++)
        {
            map[i] = new int[5001];
            visited[i] = new bool[5001];
            for (int j=0; j<5001; j++) 
            {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }

        int enemy;
        scanf("%d", &enemy);
        // cin >> enemy;
        for (int i=0; i<enemy; i++)
        {
            int enemy_row, enemy_col, enemy_radar;
            // cin >> enemy_row >> enemy_col >> enemy_radar;
            scanf(" %d%d%d", &enemy_row, &enemy_col, &enemy_radar);
            // cin >> enemy_row;
            // cin >> enemy_col;
            // cin >> enemy_radar;
            // cout << "i: "<<i << "\trow: " << enemy_row << "\tcol: " << enemy_col << "\tradar: " << enemy_radar << endl;
            dfs(enemy_row, enemy_col, enemy_radar, map, visited);
        }

        int ret=0;
        for (int i=0; i<5001; i++) 
        {
            for (int j=0; j<5001; j++)
            {
                if (visited[i][j]) {
                    dfs2(i, j, visited);
                    ret++;
                }
            }
            delete[] map[i];
            delete[] visited[i];
        }
        delete[] map;
        delete[] visited;

        printf("%d", ret);
    }
    return 0;
}
