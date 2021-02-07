/**
 * Time out
 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 1'000'001;

int n;
int a[MAXN], cnt[MAXN], dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (cnt[i] <= cnt[j] && a[j] < a[i]) {
                cnt[i] = cnt[j] + 1;
                dp[i] = j;
            }
        }
        ans = max(ans, cnt[i]);
    }

    cout << ans + 1 << '\n';
    
    return 0;
}
