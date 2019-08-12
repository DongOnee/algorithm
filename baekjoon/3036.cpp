/**
 * 18.12.16. 일요일
 */
#include <cstdio>

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    int N; scanf("%d", &N);
    int a[N]; scanf("%d", &a[0]);
    for (int i=1; i<N; i++) {
        scanf("%d", &a[i]);
        int _gcd = gcd(a[0], a[i]);
        printf("%d/%d\n", a[0]/_gcd, a[i]/_gcd);
    }
    return 0;
}