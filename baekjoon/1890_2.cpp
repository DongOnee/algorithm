#include <cstdio>
using namespace std;

int** map;
long** dp;
int size;

int main(int argc, char const *argv[])
{
    scanf("%d", &size);
    map = new int*[size];
    dp = new long*[size];
    for (int row=0; row<size; row++)
    {
        map[row] = new int[size];
        dp[row] = new long[size];
        for (int col=0; col<size; col++)
        {
            scanf("%d", &map[row][col]);
            dp[row][col] =0;
        }
    }
    dp[0][0] = 1;

    for (int row=0; row<size; row++)
    {
        for (int col=0; col<size; col++)
        {
            if (dp[row][col] == 0 || (row == size-1 && col == size-1)) continue;
            int dist = map[row][col];
            int r = col + dist;
            int d = row + dist;
            if (r < size) dp[row][r] += dp[row][col];
            if (d < size) dp[d][col] += dp[row][col];
        }
    }
    printf("%ld\n", dp[size-1][size-1]);

    return 0;
}
