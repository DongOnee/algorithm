#include <cstdio>

int a, b, v, answer = 1;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &a, &b, &v);
    v -= a;
    if (v> 0) answer += v / (a - b) + (v%(a-b)?1:0);
    printf("%d\n", answer);
    return 0;
}
