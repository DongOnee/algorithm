#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int h=0; h<n; h++)
    {
        if (h%2) printf(" *");
        else printf("*");
        for (int c=1; c<n; c++) printf(" *");
        printf("\n");
    }
    return 0;
}
