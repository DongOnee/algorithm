/**
 * 18.12.16. 일요일
 * 수학적인 유추가 필요하다. 어렵다. 이런 문제가 나오면 꼼 짝 없을거 같다.
 * ref. http://coloredrabbit.tistory.com/48
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    int a[N];

    for (int i=0; i<N; i++) scanf("%d", &a[i]);
    sort(a, a+N);

    int g = a[1] - a[0];
    for (int i=2; i<N; i++) g = gcd(g, a[i]- a[i-1]);

    vector<int> ret;
    for (int i=1; i*i<=g; i++)
    {
        if (g%i == 0)
        {
            ret.push_back(i);
            if (i != g/i) ret.push_back(g/i);
        }
    }
    sort(ret.begin(), ret.end());
    for (int i=1; i<ret.size(); i++)
    {
        printf("%d ", ret[i]);
    }

    return 0;
}