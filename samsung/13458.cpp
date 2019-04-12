/**
 * 19.4.8.21:51~22:12
 */
#include <cstdio>

int n, b, c;
int a[1000001];

int main(int argc, char const *argv[])
{
    long long sol = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    scanf("%d %d", &b, &c);

    for (int i=0; i<n; i++)
    {
        a[i] -= b;
        sol++;
        if (a[i] <= 0) continue;
        int cc = a[i]/c;
        sol += cc+(a[i]%c>0?1:0);
    }
    printf("%lld\n", sol);
    return 0;
}
