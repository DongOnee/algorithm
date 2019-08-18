/**
 * 19.3.7.
 */
#include <cstdio>

int main(int argc, char const *argv[])
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i=1; ; i++)
    {
        a -=1, b -=1;
        a /=2, b /=2;
        if (a == b)
        {
            printf("%d\n", i);
            break;
        }
        a +=1, b +=1;
    }
    return 0;
}
