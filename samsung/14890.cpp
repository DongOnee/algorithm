/**
 * 19.4.9. 22:28~
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, l, map[101][101], sol;

int dir[2][2] = {{1, 0}, {0, 1}};

bool makeSlide(int row, int col, int slideDir)
{
    int cnt=1;
    for (int i=1; i<n; i++)
    {
        int prev = map[row][col];
        int nextRow = row + dir[slideDir][0];
        int nextCol = col + dir[slideDir][1];
        int curr = map[nextRow][nextCol];
        if (abs(curr-prev)>1) return false;

        if (prev == curr)
        {
            row = nextRow;
            col = nextCol;
            cnt++;
        }
        else
        {
            if (prev < curr)
            {
                if (cnt < l) return false;
                cnt = 1;
            }
            else if (curr < prev)
            {
                if (cnt < 0) return false;
                cnt = 1-l;
            }
        }
        row = nextRow;
        col = nextCol;
    }
    if (cnt < 0) return false;
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &l);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);

    for (int i=0; i<n; i++) sol += (makeSlide(0, i, 0)? 1:0);
    for (int i=0; i<n; i++) sol += (makeSlide(i, 0, 1)? 1:0);

    printf("%d\n", sol);

    return 0;
}
