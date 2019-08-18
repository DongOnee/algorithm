#include <stdio.h>

int main(int argc, char const *argv[])
{
    int d[5];
    int sum=0;
    for (int i=0; i<5; i++) 
    {
        scanf("%d", &d[i]);
        if (d[i] < 40) d[i] = 40;
        sum += d[i];
    }
    printf("%d\n", sum/5);
    return 0;
}
