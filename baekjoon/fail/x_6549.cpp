/**
 * 19.2.26.
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n;
long long height[100000];
long long max_;

int main(int argc, char const *argv[])
{
    while(true)
    {
        scanf("%d", &n);
        if (n==0) break;

        max_ = 0;
        for (int i=0, tmp; i<n; i++) scanf("%lld", height+i);

        for (int start_=0; start_<n; start_++)
        {
            long long max_size = height[start_];
            long long min_height = height[start_];
            for (int width_=1; start_ + width_ <n; width_++)
            {
                min_height = min(min_height, height[start_+width_]);
                max_size = max(max_size, (width_+1)*min_height);
                if (max_size < (width_+1)*min_height) max_size = (width_+1)*min_height;
                else if (max_size > (width_+1)*min_height) break;
            }
            max_ = max(max_, max_size);
        }
        printf("%lld\n", max_);
    }
    return 0;
}
