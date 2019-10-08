#include <cstdio>
using namespace std;

int n, m, l, cnt[1001];

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &l);
    int cur = 0;
    int sol = 0;
    while (++cnt[cur] != m)
    {
        if (cnt[cur] %2 == 1) cur += l;
        else cur += (n-l);
        cur %= n;
        sol++;
    }
    printf("%d\n", sol);
    return 0;
}
