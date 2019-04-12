/**
 * 19.4.8.22:24~22:46
 */
#include <cstdio>

int n, m, x, y, k, map[21][21];
int roll[5][6] = {
        {0, 0, 0, 0, 0, 0},
        {3, 1, 0, 5, 4, 2}, // E
        {2, 1, 5, 0, 4, 3}, // W
        {4, 0, 2, 3, 5, 1}, // N
        {1, 5, 2, 3, 0, 4}  // S
    };
int dir[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

void rollFunc(int command)
{
    if (!chk(x+dir[command][0], y+dir[command][1])) return;
    int cpyDice[6];
    for (int i=0; i<6; i++) cpyDice[i] = roll[0][i];
    for (int i=0; i<6; i++) roll[0][i] = cpyDice[roll[command][i]];
    x += dir[command][0], y += dir[command][1];

    if (map[x][y] == 0) map[x][y] = roll[0][5];
    else
    {
        roll[0][5] = map[x][y];
        map[x][y] = 0;
    }
    printf("%d\n", roll[0][0]);
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);

    for (int i=0, cmd; i<k; i++)
    {
        scanf("%d", &cmd);
        rollFunc(cmd);
    }

    return 0;
}
