#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int h = 2*n-1;
    for (int i=0; i<h; i++)
    {
        if (i==0 || i == 2*n-2)
        {
            for (int j=0; j<n; j++) printf("*");
            for (int j=0; j<2*n-3; j++) printf(" ");
            for (int j=0; j<n; j++) printf("*");
        }
        else if (i < n-1)
        {
            for (int j=0; j<i; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
            for (int j=0; j<2*n-3-2*i; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
        }
        else if (i == n-1)
        {
            for (int j=0; j<i; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
        }
        else
        {
            for (int j=0; j<h-1-i; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
            for (int j=0; j<2*i-h; j++) printf(" ");
            printf("*");
            for (int j=0; j<n-2; j++) printf(" ");
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
