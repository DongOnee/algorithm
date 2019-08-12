#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int sol=0;

    while (0<n)
    {
        if (n<3)
        {
            printf("-1\n");
            return 0;
        }
        if (n%5 != 0)
        {
            n -= 3;
            sol++;
        }
        else
        {
            sol += n/5;
            break;
        }
    }
    printf("%d\n", sol);
    return 0;
}
