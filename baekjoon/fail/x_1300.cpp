/**
 * 19.2.2.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);
    int res = 0;
    int left = 1, right = K;

    while (left<= right)
    {
        int mid = (left+ right)/2;
        int cnt = 0 ;

        for (int i=1; i<= N; i++) cnt += min( mid/i, N );
        
        if (cnt < K) left = mid +1;
        else
        {
            res = mid;
            right = mid -1;
        }
    }
    printf("%d\n", res);
    return 0;
}
