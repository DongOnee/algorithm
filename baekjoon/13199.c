#include <stdio.h>

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int test_case =0; test_case< T; test_case++)
    {
        int p;
        int m;
        int f;
        int c;
        scanf("%d %d %d %d", &p, &m, &f, &c);

        int count_coupon = (m/p) * c;
        int sol = 0;
        count_coupon = (count_coupon /f)*c + count_coupon%f;

        while (f <= count_coupon)
        {
            sol += count_coupon/f;
            count_coupon = (count_coupon /f)*c + count_coupon%f;
        }
        printf("%d\n", sol);
    }
    return 0;
}
