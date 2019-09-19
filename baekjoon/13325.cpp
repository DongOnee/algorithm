#include <cstdio>
#include <algorithm>
using namespace std;

int s, nodes[(2<<20) +1];

int main(int argc, char const *argv[])
{
    scanf("%d", &s);
    
    int cntNode = 1;
    for (int i=0; i<s; i++)
    {
        cntNode *= 2;
        for (int j=0, input; j<cntNode; j++) scanf("%d", nodes + cntNode + j);
    }

    long long ans = 0;
    while(cntNode>1)
    {
        for (int j=0; j<cntNode; j += 2)
        {
            int l = nodes[cntNode +j];
            int r = nodes[cntNode +j +1];

            int bigger = max(l, r);
            nodes[(cntNode+j +1) /2] += bigger;

            ans += bigger;
        }
        cntNode /=2;
    }

    printf("%lld\n", ans + nodes[1]);

    return 0;
}
