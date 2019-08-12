#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 5000
using namespace std;

int arr[MAXN+1], n;

int main (int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for(int tc=1; tc <= T; tc++)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);

        int cur_idx = 0, swap_idx = MAXN;
        bool toSwap = false;
        for (int idx=1; idx<n; idx++)
        {
            if (arr[idx-1] == arr[idx]) continue;
            else if (arr[idx-1] != arr[idx] && toSwap)
            {
                toSwap = false;
                int tmp = arr[swap_idx];
                arr[swap_idx] = arr[idx];
                arr[idx] = tmp;
                cur_idx = swap_idx +1;
            }
            else if (arr[idx-1] == arr[idx] -1)
            {
                toSwap = true;
                swap_idx = idx;
            }
            else cur_idx = idx;
        }
        if (toSwap) 
        {
            toSwap = false;
            for (int i = min(n - swap_idx, swap_idx - cur_idx) -1; 0 <= i; i--)
            {
                int tmp = arr[cur_idx + i];
                arr[cur_idx + i] = arr[n -1 -i];
                arr[n -1 -i] = tmp;
            }
        }

        cout << '#' << tc;
        for (int i=0; i<n; i++) cout << ' ' << arr[i];
        cout << '\n';
    }
    return 0;
}