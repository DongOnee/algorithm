#include <cstdio>

int n, map[10][10];

int main(int argc, char const *argv[])
{
    // freopen("1954_input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        scanf("%d", &n);
        int a = 1, r = 0, c = -1, cnt = n, k = 1;
        while (cnt)
        {
            for (int i=0; i<cnt; i++)
            {
                c += k;
                map[r][c] = a++;
            }
            cnt--;
            for (int i=0; i<cnt; i++)
            {
                r += k;
                map[r][c] = a++;
            }
            k *= -1;
        }

        printf("#%d\n", test_case);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++) printf("%d ", map[i][j]);
            printf("\n");
        }
    }
    return 0;
}
