#include <cstdio>

int n, mod = 2;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);

    while (n > 1)
    {
        if (n % mod) mod++;
        else
        {
            printf("%d\n", mod);
            n /= mod;
        }
    }
    return 0;
}
