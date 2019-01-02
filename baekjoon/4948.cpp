/**
 * 18.12.29. 토요일 
 */
#include <cstdio>

int main(int argc, char const *argv[])
{
    while(true)
    {
        int input; scanf("%d", &input);
        if (input == 0) break;
        else if (input == 1)
        {
            printf("1\n");
            continue;
        }

        int i=input+1, count=0;
        if (i%2 == 0) i++;

        while (i<2*input)
        {
            bool flag=true;
            for (int j=2; j*j<=i; j++)
            {
                if (i%j == 0) {
                    flag = false;
                    break;
                }
            }
            i+=2;
            if (flag) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
