/**
 *
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int t;

int map[21][21];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dice[4][3];

void rollDice( int cmd)
{
    int tmp = dice[1][1];
    switch (cmd)
    {
        case 1:
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = dice[1][0];
            dice[1][0] = tmp;
            break;
        case 2:
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = dice[1][2];
            dice[1][2] = tmp;
            break;
        case 3:
            dice[1][1] = dice[2][1];
            dice[2][1] = dice[3][1];
            dice[3][1] = dice[0][1];
            dice[0][1] = tmp;
            break;
        case 4:
            dice[1][1] = dice[0][1];
            dice[0][1] = dice[3][1];
            dice[3][1] = dice[2][1];
            dice[2][1] = tmp;
            break;
        default:
            break;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int tc=1, n, m; tc<=t; tc++)
    {
        int sol=0;
        // int dice[4][3] = {
        //     { 0, -1,  0},
        //     {-1, -1, -1},
        //     { 0, -1,  0},
        //     { 0, -1,  0}
        // };

        int defaultDice[4][3] = {
            { 0, -1,  0},
            {-1, -1, -1},
            { 0, -1,  0},
            { 0, -1,  0}
        };
        swap(dice, defaultDice);
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", &map[i][j]);

        int curRow=0, curCol=0;
        for (int i=0, cmd; i<m; i++)
        {
            scanf("%d", &cmd);
            int nextRow = curRow+dir[cmd][0], nextCol = curCol+dir[cmd][1];
            if (!(0<=nextRow&&nextRow<n&&0<=nextCol&&nextCol<n)) continue;

            rollDice(cmd);

            if (map[nextRow][nextCol] == -1) map[nextRow][nextCol] = dice[1][1];
            else
            {
                sol += map[nextRow][nextCol];
                dice[1][1] = map[nextRow][nextCol];
                map[nextRow][nextCol] = -1;
            }
            curRow = nextRow, curCol = nextCol;
        }

        printf("#%d %d\n", tc, sol);
    }
    return 0;
}


