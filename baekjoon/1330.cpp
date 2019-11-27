#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b; scanf("%d%d", &a, &b);
    if (a<b) printf("<");
    if (a==b) printf("==");
    if (a>b) printf(">");
    return 0;
}
