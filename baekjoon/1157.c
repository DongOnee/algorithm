#include <stdio.h>

int main(int argc, char const *argv[])
{
    int d[26] = {0};
    int top=0;
    char input;
    while((input = getchar()) != '\n')
    {
        if(96 < input) input -=32;
        d[input-65]++;
        if (top < d[input-65]) top = d[input-65];
    }

    int k=0;
    int sol;
    for (int i=0; i<26; i++) if (d[i] == top)
    {
        k++;
        sol = i;
    }

    if (k==1) printf("%c\n", sol+65);
    else printf("?\n");
    return 0;
}
