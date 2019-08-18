#include <stdio.h>

int main(int argc, char const *argv[])
{
    int d[26];
    for (int i=0; i<26; i++) d[i] = -1;
    char input;
    int i=0;
    while ((input = getchar()) != '\n')
    {
        if (d[input-97] == -1) d[input-97] =i;
        i++;
    }
    for(int i=0; i<26; i++) printf("%d ", d[i]);
    puts("");
    return 0;
}
