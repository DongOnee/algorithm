/**
 * 2020.04.27 21:30 ~ 22:24
 */
#include <iostream>
#include <math.h>

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
        ll ans = -1;
        cin >> a;

        ll l = 1;
        ll r = 1414213562;
        ll m;
        while (l < r)
        {
            m = (l + r) /2;
            ll mm = (m*m+m)/2;
            // ll aa = (int) sqrt(2*a-m);
            // cout << l << ' ' << r << ' ' << m << ' ' << a << ' ' << mm << '\n';
            if (mm == a)
            // if (m == aa)
            {
                ans = m;
                break;
            }
            
            // if (m < aa)
            if (mm < a)
                l = m+1;
            else
                r = m;
        }
        ll mm = (m*m+m)/2;
        if (mm == a) ans = m;

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}

/*
999999998765257141
1414213563
1414213562
1414213561
*/