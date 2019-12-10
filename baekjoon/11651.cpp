#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> vt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++)
    {
        scanf("%d%d", &b, &a);
        vt.push_back({a, b});
    }
    
    sort(vt.begin(), vt.end());

    for (auto x : vt) printf("%d %d\n", x.second, x.first);
    return 0;
}
