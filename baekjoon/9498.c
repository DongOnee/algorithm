#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    n /=10;
    if (n>=9) printf("A\n");
    else if (n>=8) printf("B\n");
    else if (n>=7) printf("C\n");
    else if (n>=6) printf("D\n");
    else printf("F\n");
    
    return 0;
}
