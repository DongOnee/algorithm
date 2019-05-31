// 무슨 피보나치 수열을 mod 로 나눳을때 반복된다고??

#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long n;
    scanf("%lld", &n);

    int a=0;
    int b=1;
    if (n == 0 ) printf("0\n");
    else if (n == 1 ) printf("1\n");
    else
    {
        for (long long i=1; i<n; i++)
        {
            int tmp = b;
            b = (a+b) % 1000000;
            a = tmp;
        }
        printf("%d\n", b);
    }
    return 0;
}
