/**
 * 이전에 풀었떤 문제지만 다시한번 풀어 보기 위해 한다.
 * 유클리드 호제법을 이용한 방법이다.
 */

#include <cstdio>

long long int gcd(long long int a, long long int b) { // a<b 를 전제로
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    while (T--) 
    {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a*b/gcd(a, b));
    }

    return 0;
}
