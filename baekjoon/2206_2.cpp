#include <cstdio>
#include <algorithm>  
using namespace std;

int N, M;
int map[1001][1001][3];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool chk(int row, int col) {return 0<=row&&row<N&&0<=col&&col<M;}

void dfs(int row, int col, int count, int chance) {
    map[row][col][chance+1] = count;
    for (int i=0; i<4; i++)
    {
        int new_row = row + dir[i][0];
        int new_col = col + dir[i][1];
        if(!chk(new_row, new_col)) continue;

        int new_chance = chance;
        if (map[new_row][new_col][0] == 1) {
            if (chance == 1) new_chance = 0;
            else continue;
        }
        if (map[new_row][new_col][new_chance+1] <= count+1 && map[new_row][new_col][new_chance+1] != 0) continue;
        dfs(new_row, new_col, count+1, new_chance);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int row=0; row<N; row++)
    {
        for (int col=0; col<M; col++)
        {
            scanf("%1d", &map[row][col][0]);
            map[row][col][1] = 0;
            map[row][col][2] = 0;
        }
    }

    dfs(0, 0, 1, 1);

    if (max(map[N-1][M-1][1], map[N-1][M-1][2]) == 0) printf("-1\n");
    else if (min(map[N-1][M-1][1], map[N-1][M-1][2]) == 0) printf("%d\n", max(map[N-1][M-1][1], map[N-1][M-1][2]));
    else printf("%d\n", min(map[N-1][M-1][1], map[N-1][M-1][2]));
    return 0;
}
