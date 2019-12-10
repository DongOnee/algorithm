#include <cstdio>

long long a, b, c;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &a, &b, &c);
    long long d = c - b;
    printf("%lld\n", (d > 0?(a/d+1):-1));
    return 0;
}