#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000

int n, answer, arr[MAXN + 4], height[MAXN + 4];

void init()
{
    answer = 0;
    memset(arr, 0, sizeof(arr));
    memset(arr, 0, sizeof(height));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i + 2];
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("1206_input.txt", "r", stdin);
    int t; t = 10;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        for (int i = 2; i < n+2; i++)
        {
            height[i] = arr[i] - max(max(arr[i-2], arr[i-1]), max(arr[i+1], arr[i+2]));
            answer += (height[i] < 0?0:height[i]);
        }
        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}
