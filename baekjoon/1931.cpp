#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int n, cur, mx;
vector<pii> datas;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        datas.push_back({a, b});
    }

    sort(datas.begin(), datas.end());
    
    for (pii x : datas)
    {
        if (cur <= x.second)
        {
            cur = x.first;
            mx++;
        }
    }

    printf("%d\n", mx);
    return 0;
}
