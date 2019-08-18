/**
 * 19.4.9. 19:48~20:54
 */
#include <cstdio>
#include <utility>
using namespace std;

int n, m, map[51][51], sol;
bool visited[51][51];
int robRow, robCol, robDir;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &robRow, &robCol, &robDir);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);

    bool running = true;
    while (running)
    {
        // step 1.
        if (!visited[robRow][robCol])
        {
            visited[robRow][robCol] = true;
            sol++;
        }

        // step 2.
        bool isCleannig = false;
        for (int i=0; i<4; i++)
        {
            int searchDir = (robDir+3)%4;
            int nextRow = robRow+dir[searchDir][0];
            int nextCol = robCol+dir[searchDir][1];
            if (map[nextRow][nextCol] == 1 || visited[nextRow][nextCol])
            {
                robDir = searchDir;
                continue;
            }
            robDir = searchDir;
            robRow = nextRow;
            robCol = nextCol;
            isCleannig = true;
            i = 4;
        }
        if (isCleannig) continue;
        robRow -= dir[robDir][0];
        robCol -= dir[robDir][1];
        if (map[robRow][robCol] == 1) running = false;
    }

    printf("%d\n", sol);

    return 0;
}
