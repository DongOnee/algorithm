#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, x;
    scanf("%d %d", &n, &x);

    for (int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (tmp<x) printf("%d ", tmp);
    }
    puts("");
    return 0;
}
