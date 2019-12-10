#include <cstdio>

int n;

int func(int input)
{
    if (input == 0) return 1;
    return input * func(input-1);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    printf("%d", func(n));
    return 0;
}
