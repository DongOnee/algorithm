/**
 * 19.06.12. 13:02 ~
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<pair<int, int>> vt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    ans = 987654321;
    for (int i=0, a, b; i<n; i++) 
    {
        scanf("%d %d", &a, &b);
        vt.push_back({a, b});
    }
    sort(vt.begin(), vt.end());

    printf("%d\n", ans);
    return 0;
}
