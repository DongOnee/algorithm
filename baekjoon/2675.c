#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int test_cast=0; test_cast<t; test_cast++)
    {
        int r;
        char s[21];
        scanf("%d %s", &r, s);

        int i=0;
        while(s[i] != '\0')
        {
            for (int j=0; j<r; j++)printf("%c",s[i]);
            i++;
        }
        puts("");
    }
    return 0;
}
