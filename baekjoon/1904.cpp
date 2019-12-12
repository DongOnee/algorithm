#include <cstdio>

int n, a[2] = {1, 2};
bool toggle;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    if (n == 1 || n == 2) printf("%d\n", a[n-1]);
    else
    {
        while (n-->2)
        {
            a[toggle] += a[!toggle];
            a[toggle] %= 15746;
            toggle ^= true;
        }
        printf("%d\n", a[!toggle]);
    }
    

    return 0;
}