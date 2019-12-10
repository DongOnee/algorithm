#include <cstdio>

int a, b, c;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &a, &b, &c);
    while (a && b && c)
    {
        int aa = a*a, bb = b*b, cc = c*c;
        if (aa == bb+cc || bb == aa+cc || cc == aa+bb) printf("right\n");
        else printf("wrong\n");
        
        scanf("%d%d%d", &a, &b, &c);
    }
    return 0;
}
