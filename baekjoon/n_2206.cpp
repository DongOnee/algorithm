/**
 * 2018.10.5. 07`46``
*/
#include <cstdio>

int** d;
int** map; // 0 : road, 1 : wall
int sol;
bool chance;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int row, int col, int N, int M, int count) {
    bool change = false;
    if (d[row][col] == 1
        || (sol != -1 && sol < count + N-1 - row + M-1 - col )) return;
    if (map[row][col] == 1) // if wall
    {
        if (chance) 
        {
            chance = false;
            change = true;
        }
        else return;
    }
    if ((row == N-1) && (col == M-1)) {
        if (count < sol || sol == -1) sol = count;
    }
    else
    {
        d[row][col] = 1;
        for (int i=0; i<4; i++) {
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];
            if (-1<next_row && next_row<N
                && -1<next_col && next_col<M) dfs(next_row, next_col, N, M, count+1);
        }
        d[row][col] = 0;
        if (change) chance = true;
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    sol = -1;
    chance = true;
    map = new int*[N];
    d = new int*[N];
    for (int row=0; row < N; row++)
    {
        *(map+row) = new int[M];
        *(d+row) = new int[M];
        int input;
        scanf("%d", &input);
        for (int col=M-1; -1<col; col--)
        {
            map[row][col] = input%10;
            d[row][col] = 0;
            input /= 10;
        }
    }
    dfs(0,0,N,M,1);

    printf("%d\n", sol);

    return 0;
}
