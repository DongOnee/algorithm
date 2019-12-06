#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> vc;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, aa; i<n; i++)
    {
        scanf("%d", &aa);
        if (i == 0)
        {
            vc.push_back(aa);
            continue;
        }
        auto x = lower_bound(vc.begin(), vc.end(), aa);
        if (x == vc.end()) vc.push_back(aa);
        else *x = aa;
    }

    printf("%ld\n", vc.size());
    return 0;
}
