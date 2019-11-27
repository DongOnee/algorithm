#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int h=0; h<n*2; h++)
    {
        for (int c=0; c<n; c++) printf("%c", ((h+c)%2?' ':'*'));
        printf("\n");
    }
    return 0;
}
