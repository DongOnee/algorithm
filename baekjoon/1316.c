#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    int sol=0;
    for (int test_case=0; test_case<t; test_case++)
    {
        char pre;
        int alpabat[26];
        for (int i=0; i<26; i++) alpabat[i] =0;
        char input=getchar();
        pre = input;
        int flag=0;
        while ( (input = getchar()) != '\n')
        {
            if(pre == input || flag) continue;
            alpabat[pre-97] =1;
            // printf("pre:\t\t%d\n", alpabat[pre-97]);
            // printf("input:\t\t%d\n", alpabat[input-97]);
            // printf("alpa pre:\t%d\n", pre);
            // printf("alpa input:\t%d\n", input);
            
            if(alpabat[input-97]==1) 
            {
                flag = 1;
                // printf("%c\n", input);
            }
            else pre = input;
        }
        if (!flag) sol++;
    }
    printf("%d\n", sol);
    return 0;
}
