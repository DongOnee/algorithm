#include <cstdio>

int n;

int main(int argc, char const *argv[])
{
    // freopen("1926_input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        int cnt = 0;

        int tmp = i;
        while (tmp)
        {
            int tmp2 = tmp%10;
            if (tmp2 == 3 || tmp2 == 6 || tmp2 == 9) cnt++;
            tmp /= 10;
        }

        if (cnt == 0) printf("%d", i);
        else while (cnt--) printf("-");
        printf(" ");
    }
    return 0;
}
