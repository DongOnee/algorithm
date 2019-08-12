#include <cstdio>

int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++) printf("*");
        printf("\n");
    }
    for (int i=n-1; 0<=i; i--)
    {
        for (int j=0; j<i; j++) printf("*");
        printf("\n");
    }
    
    return 0;
}
