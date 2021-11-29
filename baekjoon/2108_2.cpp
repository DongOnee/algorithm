#include <iostream>
#include <algorithm>

using namespace std;

int cnt[8001];
int arr[500000];
int isArr[8001];
int cntArr;
int sum;
int ans;

typedef 
struct {
    int cnt;
    int v;
}info;

bool operator<(const info& a, const info& b)
{
    return (a.cnt==b.cnt?a.v<b.v:a.cnt>b.cnt);
}
    
info cnt_v[8001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        if (cnt[arr[i] + 4000]++ == 0) isArr[cntArr++] = arr[i];
    }

    for (int i = 0; i < cntArr; ++i) {
        cnt_v[i] = {cnt[isArr[i]+4000], isArr[i]};
    }

    sort(cnt_v, cnt_v + cntArr);
    sort(arr, arr+n);
    ans = cnt_v[0].v;
    if (cntArr > 1) {
        if (cnt_v[1].cnt==cnt_v[0].cnt) {
            ans = cnt_v[1].v;
        }
    }

    if (sum < 0) cout << (int) -((double)-sum / n + 0.5) << '\n';
    else cout << (int)((double) sum / n + 0.5) << '\n';
        cout << arr[n/2] << '\n' 
        << ans << '\n'
        << arr[n-1] - arr[0] << '\n';

    return 0;
}
