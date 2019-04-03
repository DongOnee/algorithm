/**
 * 19.3.14.
 */
#include <cstdio>

int t; 

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int test_case=0, n, m; test_case<t; test_case++)
    {
        scanf("%d%d", &n, &m);
        long long ret = 1;
        for (int i=0; i<n && i<m-n; i++)
        {
            ret *= m-i;
            ret /= i+1;
        }
        printf("%lld\n", ret);
    }
    return 0;
}
