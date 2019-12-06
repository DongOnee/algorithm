#include <cstdio>

bool chk[42];
int ans;

int main(int argc, char const *argv[])
{
    for (int i=0, a; i<10; i++)
    {
        scanf("%d", &a);
        int b = a%42;
        if (!chk[b])
        {
            chk[b] = true;
            ans++;
        }
    }

    printf("%d\n", ans);
    return 0;
}
