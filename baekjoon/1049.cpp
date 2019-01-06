/**
 * 19.1.4.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, M;
int pack_min, one_min;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    pack_min=1000, one_min=1000;
    for (int i=0; i<M; i++)
    {
        int one, pack; scanf("%d %d", &pack, &one);
        pack_min = pack_min<pack ? pack_min:pack;
        one_min = one_min<one ? one_min:one;
    }

    int one = N*one_min;
    int pack = (N/6+1)*pack_min;
    int mix = N/6*pack_min+N%6*one_min;
    
    printf("%d\n", min(one, min(pack, mix)));
    return 0;
}
