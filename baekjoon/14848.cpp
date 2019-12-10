#include <cstdio>
using namespace std;

typedef long long ll;

int n, k, a[15], answer;

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a, a);
}

void init()
{
    scanf("%d%d", &n, &k);
    for (int i=0; i<k; i++) scanf("%d", a+i);
}

int main(int argc, char const *argv[])
{
    init();

    int maxComb = (1 << k);
    for (int i = 1; i < maxComb; i++)
    {
        int cnt = 0;
        ll gcd2 = 0;
        for (int shift = 0; shift < k; shift++)
        {
            if (i & (1 << shift))
            {
                cnt++;
                if (gcd2 == 0) gcd2 = a[shift];
                else gcd2 = gcd2 * a[shift] / gcd(gcd2, a[shift]);
            }
        }

        if (cnt)
        {
            int p = n / gcd2;
            if (cnt % 2 == 0) p = -p;
            answer += p;
        }
    }

    printf("%d\n", n - answer);

    return 0;
}
