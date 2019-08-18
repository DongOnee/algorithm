#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int test_case=0; test_case<t; test_case++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}
