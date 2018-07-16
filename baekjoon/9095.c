#include <stdio.h>

int d[11][3];

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    int n = 4;

    d[0][0] = 0;
    d[0][1] = 0;
    d[0][2] = 0;

    d[1][0] = 1;
    d[1][1] = 0;
    d[1][2] = 0;

    d[2][0] = 1;
    d[2][1] = 1;
    d[2][2] = 0;

    d[3][0] = 2;
    d[3][1] = 1;
    d[3][2] = 1;
    for (int test_case=0; test_case <t; test_case++)
    {
        int tmp;
        scanf("%d", &tmp);
        while ( n <= tmp)
        {
            d[n][0] = d[n-1][0] + d[n-1][1] + d[n-1][2];
            d[n][1] = d[n-2][0] + d[n-2][1] + d[n-2][2];
            d[n][2] = d[n-3][0] + d[n-3][1] + d[n-3][2];
            n++;
        }
        printf("%d\n", d[tmp][0] + d[tmp][1] + d[tmp][2]);
    }
    return 0;
}
