/**
 * dfs 를 이용하여 풀어 보았다.
 * 하지만 제출 결과 시간 초과가 나왔다.
 * 검색해본 결과 시간 초과가 나오는 이유는 map[0][0]에서 출발하여 map[i][j] 에 도착하기까지 경로를 중첩해서 탐색하기 때문이다.
 */
#include <cstdio>

int **map;
int size;
int ret;
int dir[2][2] = { {1, 0}, {0, 1} };

bool chk(int row, int col) { return 0<=row && row<size && 0<=col && col<size; }

void dfs(int row, int col) {
    
    for (int i=0; i<2; i++)
    {
        int new_row = row + dir[i][0]*map[row][col];
        int new_col = col + dir[i][1]*map[row][col];

        if(!chk(new_row, new_col)) continue;
        else if (map[new_row][new_col] == 0) ret++;
        else dfs(new_row, new_col);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &size);
    map = new int*[size];
    for (int i=0; i<size; i++)
    {
        map[i] = new int[size];
        for (int j=0; j<size; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0, 0);

    printf("%d\n", ret);
    return 0;
}
