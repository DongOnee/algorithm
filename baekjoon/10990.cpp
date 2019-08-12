#include <cstdio>

int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=1; j<n-i; j++) printf(" ");
        printf("*");
        for (int j=0; j<2*i-1; j++) printf(" ");
        if ( i != 0) printf("*");
        printf("\n");
    }
    return 0;
}
