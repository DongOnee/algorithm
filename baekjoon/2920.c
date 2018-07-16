#include <stdio.h>

int main(int argc, char const *argv[])
{
    int init;
    scanf("%d", &init);

    int flag=0;

    if (init == 1)
    {
        for (int i=2; i<9; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp != i) flag=1;
        }
        if (!flag) printf("ascending\n");
    }
    else if (init == 8)
    {
        for (int i=7; 0<i; i--)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp != i) flag=1;
        }
        if (!flag) printf("descending\n");
    }
    if(flag) printf("mixed\n");
    return 0;
}
