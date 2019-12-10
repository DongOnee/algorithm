#include <cstdio>

int a[2] = {0, 1}, n;
bool toggle;

int pib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return pib(n-1) + pib(n-2);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    printf("%d\n", pib(n));

    return 0;
}
