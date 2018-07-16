#include <stdio.h>

int main(int argc, char const *argv[])
{
    char input[103];
    int sol = 0;
    scanf("%s", input);
    int i=0;
    while( input[i] != '\0')
    {
        if (input[i] =='c')
        {
            if (input[i+1] == '=' || input[i+1] =='-') i++;
        }
        else if (input[i] == 'd')
        {
            if (input[i+1] == '-') i++;
            else if (input[i+1] == 'z' && input[i+2] =='=') i +=2;
        }
        else if (input[i] == 'l' && input[i+1] == 'j') i++;
        else if (input[i] == 'n' && input[i+1] == 'j') i++;
        else if (input[i] == 's' && input[i+1] == '=') i++;
        else if (input[i] == 'z' && input[i+1] == '=') i++;
        i++; sol++;
    }
    printf("%d\n", sol);
    return 0;
}
