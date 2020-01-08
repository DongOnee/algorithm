#include <cstdio>

int a, b;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &a, &b);
    while (a !=0)
    {
        if (a < b && b % a == 0) printf("factor\n");
        else if (a > b && a % b == 0) printf("multiple\n");
        else printf("neither\n");

        scanf("%d%d", &a, &b);
    }
    return 0;
}
