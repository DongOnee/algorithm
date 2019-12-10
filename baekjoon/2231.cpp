#include <cstdio>

int n, cnt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int i = n;
    while (i) cnt++, i/=10;

    for (i=n-9*cnt; i<n; i++)
    {
        int sol = 0;
        sol += i;
        for (int j=i; j; j/=10) sol += j%10;
        if (sol == n) break;
    }

    printf("%d\n", i==n?0:i);
    return 0;
}
