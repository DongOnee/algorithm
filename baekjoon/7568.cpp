#include <cstdio>

int a[50][2], n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d%d", a[i]+0, a[i]+1);

    for (int i=0; i<n; i++)
    {
        int rank = 1;
        for (int j=0; j<n; j++)
        {
            if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) rank++;
        }
        printf("%d ", rank);
    }

    return 0;
}

/*
6
55 185
58 183
88 186
60 175
46 155
54 188

*/
