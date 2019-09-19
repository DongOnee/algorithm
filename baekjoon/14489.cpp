#include <cstdio>

int main(int argc, char const *argv[])
{
    int a, b, c, sum=0;
    scanf("%d%d%d", &a, &b, &c);
    sum += (a+b);
    if (sum < 2*c) printf("%d\n", sum);
    else printf("%d\n", sum - 2*c);
    
    return 0;
}
