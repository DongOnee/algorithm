#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll tk[100000];
int t_count, f_count;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t_count >> f_count;
    for (int idx = 0; idx < t_count; ++idx) cin >> tk[idx];

    ll l = 0, ans = *max_element(tk, tk+t_count) * f_count;
    ll r = ans + 1;
    while (l < r) {
        ll m = (l + r) / 2;
        ll c = 0;

        for (int idx = 0; idx < t_count; ++idx) {
            c += m / tk[idx];
        }

        if (c < f_count) l = m + 1;
        else {
            r = m;
            ans = m;
        }
    }

    cout << ans << '\n';

    return 0;
}
