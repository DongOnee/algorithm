#include <iostream>
#include <algorithm>
#include <memory.h>


using namespace std;

#define MAXN 100001

typedef long long ll;

int cnt, ans;
ll arrC[MAXN];
ll arrD[MAXN];
ll cp_arrD[MAXN];

ll sol()
{
    ll ret = 0;
    ll l = 1'000'000'000'000;
    ll r = 0;

    for (int i = 0; i < cnt-1; ++i) cin >> arrC[i] >> arrD[i];
    cin >> arrC[cnt-1];

    l = arrC[cnt-1];
    for (int i = 0; i < cnt-1; ++i) {
        l = min(l, arrC[i]);
        r = max(r, arrC[i] + arrD[i]);
        r = max(r, arrC[i+1] + arrD[i]);
    }

    ++r;
    while (l < r) {
        memcpy(cp_arrD, arrD, sizeof(ll) * (cnt-1));

        ll m = (l + r) / 2;
        bool bFail = false;
        if (arrC[0] < m) {
            if (arrC[0] + cp_arrD[0] < m) bFail = true;
            else cp_arrD[0] -= (m - arrC[0]);
        }

        for (int i = 1; i < cnt-1 && !bFail; ++i) {
            int underIdx = i - 1;
            int upperIdx = i;

            if (arrC[i] < m) {
                if (cp_arrD[underIdx] + arrC[i] < m) {
                    if (cp_arrD[underIdx] + arrC[i] + cp_arrD[upperIdx] < m) {
                        bFail = true;
                        break;
                    }
                    else {
                        cp_arrD[upperIdx] -= (m - arrC[i] - cp_arrD[underIdx]);
                    }
                }
                else {
                    cp_arrD[underIdx] -= (m - arrC[i]);
                }
            }
        }

        if (arrC[cnt-1] < m && !bFail) {
            if (arrC[cnt-1] + cp_arrD[cnt-2] < m) bFail = true;
            else cp_arrD[cnt-2] -= (m - arrC[cnt-1]);
        }

        if (bFail) {
            r = m;
        }
        else {
            ret = m;
            l = m + 1;
        }
    }

    return ret;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> cnt >> tc;
    while (tc--) {
        cout << sol() << '\n';
    }

    return 0;
}

