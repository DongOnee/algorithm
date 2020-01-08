#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    for (int mod = 2; mod * mod <= n; mod++)
    {
        while (n % mod == 0)
        {
            printf("%d\n", mod);
            n /= mod;
        }
    }

    if (n > 1) printf("%d\n", n);
    return 0;
}
