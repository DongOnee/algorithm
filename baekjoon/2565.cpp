#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 500

int arr[MAXN+1], n, ans;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        arr[a] = b;
    } 

    for (int i=1; i<=500; i++)
    {
        if (arr[i] == 0) continue;
        auto itr = lower_bound(vt.begin(), vt.end(), arr[i]);
        if (itr == vt.end()) vt.push_back(arr[i]);
        else
        {
            *itr = arr[i];
            ans++;
        }
    }

    // printf("%d\n", vt.size());
    printf("%d\n", ans);
    
    return 0;
}
