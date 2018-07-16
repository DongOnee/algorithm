#include <stdio.h>

int rev(int a)
{
    int sol=0;
    for (int i=0; i<3; i++)
    {
        sol *=10;
        sol += a%10;
        a /=10;
    }
    return sol;
}

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);

    a=rev(a);
    b=rev(b);

    if (a <b) printf("%d\n", b);
    else printf("%d\n", a);

    return 0;
}
