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

    int T;cin >> T;
    for(int tc=1; tc <= T; tc++)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);

        vector<pair<int, int>> vt;
        int cur_idx = 0, cur_cnt = 1;
        bool flag = true;
        for (int idx=1; idx < n; idx++)
        {
            if (arr[idx-1] == arr[idx]) cur_cnt++;
            else if (arr[idx-1] +1 == arr[idx])
            {
                flag = true;
                int next_idx = idx, next_cnt=1;
                while ( arr[next_idx] == arr[++idx] && idx < n ) next_cnt++;
                if ( idx < n )
                {
                    vt.push_back({arr[cur_idx], cur_cnt});
                    cur_idx = idx;
                    cur_cnt = 1;
                    while ( arr[cur_idx] == arr[++idx] && idx < n ) cur_cnt++;
                    vt.push_back({arr[cur_idx], cur_cnt});
                    vt.push_back({arr[next_idx], next_cnt});
                    arr[idx-1]= arr[cur_idx];
                    cur_idx =idx, cur_cnt =1;
                }
                else  vt.push_back({arr[next_idx], next_cnt});
            }
            else
            {
                vt.push_back({arr[cur_idx], cur_cnt});
                cur_idx = idx, cur_cnt =1;
            }
        }
        cout << '#' << tc << ' ';
        for (auto x: vt) for ( int i =0; i < x.second ; i++) cout << x.first << ' ';
        for ( int i =0; i<cur_cnt && cur_idx < n; i++) cout << arr[cur_idx] << ' ';
        cout << '\n';
    }
    return 0;
}