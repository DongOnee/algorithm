/**
 * 2019.06.26. 11:07 ~ 14:29
 */
#include <cstdio>

int t, p, m, f ,c;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++)
    {
        scanf("%d%d%d%d", &p, &m, &f, &c);
        int coupon = m / p * c;
        int remain_coupon = coupon / f * c + coupon % f;
        int ans = 0;
        if (remain_coupon >= f) 
        {
            ans = (remain_coupon - f) / (f - c) +1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
