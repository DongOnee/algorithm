/**
 * 2019-08-26 20:52 ~
 */
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int a, b;

pii convert(int input)
{
    pii ret = {1, 1};
    if (input == 1) return ret;
    int k=2;
    while ( k*(k+1)/2 < input ) k++;
    
    return {k, k*(k+1)/2 - input};
}

int main(int argc, char const *argv[])
{
    int T; scanf("%d", &T);
    for (int test_case =1; test_case <= T; test_case++)
    {
        scanf("%d%d", &a, &b);
        pii aa = convert(a);
        pii bb = convert(b);
        int ff = aa.first - bb.first;
        int ss = aa.second - bb.second;
        int ans = (aa.first < bb.first ? bb.first - aa.first:aa.first - bb.first);
        int diff = (aa.second < bb.second ? bb.second - aa.second:aa.second - bb.second);
        if ((aa.first <= bb.first && aa.second <= bb.second) || (aa.first >= bb.first && aa.second >= bb.second))
        {
            if (ans < diff) ans += (diff-ans);
        }
        else 
        {
            ans += diff;
        }
        printf("#%d %d\n", test_case, ans);
    }
    return 0;
}
