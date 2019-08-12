/**
 * 19.3.6.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int ret=0, cur=0;
    for (int i=0, a, b; i<4; i++)
    {
        scanf("%d %d", &a, &b);
        cur -= a;
        cur += b;
        ret = max(ret, cur);
    }
    printf("%d\n", ret);
    return 0;
}
