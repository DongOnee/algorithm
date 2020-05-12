#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
pii operator+(const pii &a, const pii &b) { return {a.first+b.first, a.second+b.second }; }
pii operator-(const pii &a, const pii &b) { return {a.first-b.first, a.second-b.second }; }
void operator+=(pii &a, const pii&b) { a.first+=b.first; a.second+=b.second; }
void operator-=(pii &a, const pii&b) { a.first-=b.first; a.second-=b.second; }

int n, m;
pii answer, dp[2];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=2; i<=n; i++)
    {
        if (i%2 == 0) dp[i].first  = dp[i/2].first  +1;
        if (i%5 == 0) dp[i].second = dp[i/5].second +1;
    }

    for (int i=0; i < m && i < n-m; i++)
    {
        answer = answer + dp[n-i];
        answer = answer - dp[i+1];
    }
    printf("%d\n", min(answer.first, answer.second));

    return 0;
}
