/**
 * 19.06.18. 09:16 ~ 10:18
 */
#include <cstdio>
#include <algorithm>
using namespace std;

long long n;
int dice[6], edge[8], line[12];
int edge_index[8][3] ={ {0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5} };
int line_index[12][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
/*
    +---+
    | 3 |
+---+---+---+---+
| 4 | 0 | 1 | 5 |
+---+---+---+---+
    | 2 |
    +---+
 */

int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i=0; i<6; i++) scanf("%d", dice+i);
    for (int i=0; i<8; i++) edge[i] = dice[edge_index[i][0]] + dice[edge_index[i][1]] + dice[edge_index[i][2]];
    for (int i=0; i<12; i++) line[i] = dice[line_index[i][0]] + dice[line_index[i][1]];
    
    sort(dice, dice+6);
    sort(edge, edge+8);
    sort(line, line+12);

    long long ans;
    if (n==1) ans =  dice[0] + dice[1] + dice[2] + dice[3] + dice[4];
    else ans = dice[0] * (n-2) * (5*n - 6) + line[0] * 4 * (2*n-3) + edge[0] * 4;
    printf("%lld\n", ans);
    return 0;
}
