#include <stdio.h>

long long int GCD(long long int, long long int);

int main(void) {
  int T;
  scanf("%d", &T);

  while (T--) {
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    long long int ret;
    if (A<= B) {
      ret = GCD(A, B);
    }
    else {
      ret = GCD(B, A);
    }

    printf("%lld\n", A*B/ret);
  }
  return 0;
}

// a <= b
long long int GCD(long long int a, long long int b) {
  if (a == 0) return b;
  else return GCD(b%a, a);
}
