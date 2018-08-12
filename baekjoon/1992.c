#include <stdio.h>

int d[64][64];

void go(int x, int y, int n)
{
    int tmp = d[x][y];
    int i;
    if (n != 1) for (i=x; i<x+n; i++) for (int j=y; j<y+n; j++)
    {
        if (tmp != d[i][j])
        {
            printf("(");
            go(x, y, n/2);
            go(x, y+n/2, n/2);
            go(x+n/2, y, n/2);
            go(x+n/2, y+n/2, n/2);
            printf(")");
            i =65;
            j= 65;
        }
    }
    if (i !=66) printf("%d", tmp);
}

int main(int argc, char const *argv[])
{
    // data init
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        char tmp[n];
        scanf("%s", tmp);
        for (int j=0; j<n; j++)
        {
            if (tmp[j] == '0') d[i][j] = 0;
            else d[i][j]=1;
        }
    }

    // algorithm
    go(0,0,n);
    puts("");

    return 0;
}