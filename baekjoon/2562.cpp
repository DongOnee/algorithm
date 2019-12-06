#include <cstdio>

int main(int argc, char const *argv[])
{
    int a[10];
    int ans = -1, ans2 =0;
    for (int i=1; i<=9; i++) 
    {
        scanf("%d", a+i);
        if (a[i] > ans2)
        {
            ans2 = a[i];
            ans = i;
        }
    }

    printf("%d\n%d\n", ans2, ans);
    return 0;
}
