#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sol = 0;
    int i=0;
    int flag;
    char cur = getchar();
    if (cur == ' ') flag = 0;
    else flag = 1;
    while((cur = getchar()) != '\n')
    {
        if (cur == ' ')
        {
            if (flag) sol++;
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag) sol++;

    printf("%d\n", sol);
    return 0;
}
