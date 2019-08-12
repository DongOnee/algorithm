#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 5000
using namespace std;

typedef pair<int, int> pii;

int n, arr[MAXN];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int tc=1; tc<=t; tc++)
    {
        cin >> n;
        for (int idx=0; idx<n; idx++) cin >> arr[idx];
        sort(arr, arr+n);

        int pre_idx = 0;
        int cur_idx = 0;
        int cur_cnt = 1;
        
        vector<pii> vt;
        for (int idx=1; idx<n; idx++)
        {
            if (arr[idx] == arr[idx-1] + 1)
            {
                int next_cnt = 1;
                while (arr[idx] == arr[++idx] && idx < n) next_cnt++;
                vt.push_back({arr[idx-1], next_cnt});
                vt.push_back({arr[cur_idx], cur_cnt});
            }
            else if (arr[idx-1] == arr[idx] ) cur_cnt++;
            else
            {
                cur_idx = idx;
                cur_cnt = 1;
            }
        }
        cout << "#" << tc << " ";
        for (auto x : vt)
            for (int i=0; i<x.second; i++) cout << x.first << ' ';
        cout << '\n';
    }
    return 0;
}
