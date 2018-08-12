#include <stdio.h>

int main(int argc, char const *argv[])
{
    // input data
    int n;

    // input
    scanf("%d", &n);

    // algorithm
    int d[n+1];
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;

    for (int i=4; i<=n; i++)
    {
        d[i] = d[i-1];
        if (i%2 == 0)
        {
            if (d[i/2] < d[i]) d[i] = d[i/2];
        }
        if (i%3 == 0)
        {
            if (d[i/3] < d[i]) d[i] = d[i/3];
        }
        d[i] += 1;
    }

    printf("%d\n", d[n]);
    return 0;
}
