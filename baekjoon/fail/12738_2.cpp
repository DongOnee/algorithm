#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 1'000'001;

int n;
int a[MAXN], cnt[MAXN], dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    
    cin >> n;
    int l, r, m, ans = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        l = 0, r = i;
        while (l < r) {
            m = (l + r) / 2;
            if (a[m] < a[i]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        cnt[i] = l;
        sort(a, a+i);
        ans = max(ans, cnt[i]);
    }
    
    cout << ans - 1 << '\n';
    
    return 0;
}

