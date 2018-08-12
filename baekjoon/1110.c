#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int sol=0;
    int tmp = n;
    do
    {
        int a= tmp/10;
        int b= tmp%10;
        int c= (a+b)%10;
        tmp = b*10+c;
        sol++;
    }
    while (tmp != n);

    printf("%d\n", sol);

    return 0;
}
