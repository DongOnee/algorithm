#include <cstdio>
#include <algorithm>
using namespace std;

int nn[500000], mm[500000];

int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    for (int i=0, a; i<n; i++) scanf("%d", nn+i);

    sort(nn, nn+n);
    
    int m; scanf("%d", &m);
    for (int i=0, a; i<m; i++)
    {
        scanf("%d", &a);
        printf("%d ", upper_bound(nn, nn+n, a) - lower_bound(nn, nn+n, a));
    }
    return 0;
}
