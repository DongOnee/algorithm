/**
 * 19.2.25.
 */
#include <cstdio>

#define mod 1000000

int main(int argc, char const *argv[])
{
    long long n; scanf("%lld", &n);

    int a, b;
    for (a=0, b=1; n; n--)
    {
        int tmp = b;
        b += a;
        b %= mod;
        a = tmp;
    }

    printf("%d\n", a);

    return 0;
}
