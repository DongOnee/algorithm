/**
 * 2019.07.23. 22:19 ~ 
 */
#include <cstdio>
#include <utility>
using namespace std;

#define MAXN 2002
#define MAXM 502

char map[MAXN][MAXM];
int n, m, ans;
pair<int, int> cur;

int ascii2dec(int row, int col) { return map[row][--col] - (map[row][col] < 'A' ? '0' : 'A' - 10); }

void solve(int row, int col) // start point
{
    printf("%d %d\t", row, col);
    int code[4] = {0, 0, 0, 0}, index = 3, cur_code = 1;
    int cur_value = map[row][--col] - (map[row][col] < 'A' ? '0' : 'A' - 10);
    while (cur_value % 2 == 0) cur_value >>= 1;
    while (1)
    {
        printf("cur value : %d\n", cur_value);
        if (cur_value % 2 != cur_code)
        {
            printf("cur_code : %d\n", cur_code);
            cur_code ^= 1; // toggle
            if(--index < 0) break;
        }
        code[index]++;
        cur_value >>= 1;
        if (cur_value == 0) cur_value = map[row][--col] - (map[row][col] < 'A' ? '0' : 'A' - 10);
    }
    printf("%d %d %d %d\n", code[0], code[1], code[2], code[3]);
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int test_case=1; test_case<=T; test_case++)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++) scanf("%s", map[i]);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) printf("%c", map[i][j]);
            printf("\n");
        }
        cur = {0, m-1};

        for (int i=0; i<n; i++) for (int j=m-1; 0<=j; j--)
        {
            if (map[i][j] == '0') continue;
            solve(i, j);
        }

        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
