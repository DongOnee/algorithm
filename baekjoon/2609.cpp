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
    printf("%lld\n%lld\n", _gcd, a*b/_gcd);

    return 0;
}
