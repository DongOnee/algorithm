#include <stdio.h>

int main(int argc, char const *argv[])
{
    int d[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

    char input;
    int sol=0;
    while ( (input = getchar()) != '\n') sol += d[input-65];
    
    printf("%d\n", sol);
    return 0;
}
