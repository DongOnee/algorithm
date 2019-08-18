/**
 * 이 문제는 유클리드 호제법을 사용한다는걸 알고있어도 띠용 하는 문제이다.
 * 일단 문제에서가
 */

#include <cstdio>

long long int gcd(long long int a, long long int b) { // a<b 를 전제로
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(int argc, char const *argv[])
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    long long int _gcd = gcd(a, b);
    long long int ret=1;
    for (int i =0; i<_gcd; i++) printf("1");

    return 0;
}
