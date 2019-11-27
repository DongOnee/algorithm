#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b, ret=0, po = 1;
    scanf("%d%d", &a, &b);
    while (b)
    {
        printf("%d\n", a*(b%10));
        ret += a*(b%10)*po;
        b/=10;
        po *=10;
    }
    printf("%d\n", ret);
    return 0;
}
