/**
 * 2020.04.27 20:41 ~
 */
#include <iostream>

using namespace std;

typedef long long ll;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int tc=1; tc<= t; ++tc)
    {
        ll a;
        int ans = -1;
        cin >> a;

        int l = 1;
        int r = 1414213562;
        ll m;
        while (l < r)
        {
            m = (l + r) /2;
            ll mm = (m*m+m)/2;
            if (mm == a)
            {
                ans = m;
                break;
            }
            
            if (mm < a)
                l = m+1;
            else
                r = m;
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
