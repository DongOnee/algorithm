#include <cstdio>

#define MOD 1000000007

int map[2][1000001];

int main(int argc, char const *argv[])
{
    int n, r;
    scanf("%d%d", &n, &r);
    bool toggle = false;
    map[false][0] = 1;
    map[true][0] = 1;

    r = r<n-r?r:n-r;
    for (int i=1; i<=n; i++)
    {
        for (int j = 1; j <= r && j < i; j++) map[!toggle][j] = (map[toggle][j] + map[toggle][j-1]) % MOD;
        map[!toggle][i] = 1;
        toggle ^= true;
    }

    printf("%d\n", map[toggle][r]);
    return 0;
}
