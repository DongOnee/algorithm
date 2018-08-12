#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    
    for (int test_case=0; test_case<t; test_case++)
    {
        char input[80];
        scanf("%s", input);

        int i=0;
        int count=1;
        int sol=0;
        char k;
        while ((k = input[i]) != '\0')
        {
            if (k == 'X') count=1;
            else sol += count++;
            i++;
        }

        printf("%d\n", sol);
    }
    return 0;
}
