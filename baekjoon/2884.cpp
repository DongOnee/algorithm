#include <cstdio>

int main(int argc, char const *argv[])
{
    int h, m;
    scanf("%d%d", &h, &m);
    m -= 45;
    if (m < 0)
    {
        h--;
        if (h<0) h += 24;
        m+=60;
    }
    printf("%d %d\n", h, m);
    return 0;
}
