/**
 * 2019.06.26. 11:07 ~
 * 반복문을 돌면 안된다.
 */
#include <cstdio>

int t, p, m, f ,c;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++)
    {
        scanf("%d%d%d%d", &p, &m, &f, &c);
        int coupon = m/p*c;
        int remain_coupon = (coupon / f * c) + (coupon % f);
        int ans = 0;
        while (remain_coupon / f != 0) 
        {
            ans += remain_coupon / f;
            remain_coupon = remain_coupon % f + remain_coupon / f * c;
        }
        printf("%d\n", ans);
    }
    return 0;
}
