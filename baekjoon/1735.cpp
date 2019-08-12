/**
 * 19.4.5.
 */
#include <cstdio>
#include <utility>
using namespace std;

pair<int, int> a, b;

int gcd(int n, int m)
{
    if (n==0) return m;
    return gcd(m%n, n);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &a.first, &a.second, &b.first, &b.second);
    int parents = a.second * b.second;
    int child = a.first*b.second + b.first*a.second;
    int gcdPC = gcd(parents, child);
    printf("%d %d\n", child/gcdPC, parents/gcdPC);

    return 0;
}
