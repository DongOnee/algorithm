/**
 * 18.12.30.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int value[10];

int main(int argc, char const *argv[])
{
    int N, sol; scanf("%d %d", &N, &sol);

    int ret = 100000000;

    for (int _case=0; _case<N; _case++)
    {
        int _sol = sol;
        int _ret = 0;
        scanf("%d", &value[_case]);
        for (int i=_case; 0<=i; i--)
        {
            _ret += _sol/value[i];
            _sol %= value[i];
        }
        ret = min(ret, _ret);
    }

    printf("%d\n", ret);
    return 0;
}
