/**
 * 19.06.19. 09:55 ~ 13:00 -1 hour
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, ans, sum;
vector<long long> budget;

int main(int argc, char const *argv[])
{
    scanf("%lld", &n);
    for (int i=0; i<n; i++)
    {
        long long a;
        scanf("%lld", &a);
        budget.push_back(a);
        sum += a;
    }
    scanf("%lld", &m);

    sort(budget.begin(), budget.end());
    if (sum <= m) ans =  budget[n-1];
    else
    {
        long long l = 1, r = sum;
        while (l<r)
        {
            long long mid = (l+r)/2;
            long long remain = m;

            for (auto x : budget)
            {
                if ( x < mid) remain -= x;
                else remain -= mid;
            }

            if (remain < 0) r = mid;
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}
