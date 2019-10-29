#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;


int main(int argc, char const *argv[])
{
    // freopen("1204_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        vector<pii> arr2;
        vector<int> arr(101, 0);
        int n; scanf("%d", &n);
        for (int i=0; i<1000; i++)
        {
            int a; scanf("%d", &a);
            arr[a]++;
        }
        for (int i=0; i<101; i++) arr2.push_back({arr[i], i});
        sort(arr2.begin(), arr2.end());
        printf("#%d %d\n", test_case, arr2[100].second);
        arr.clear();
    }
    return 0;
}
