#include "bits/stdc++.h"
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int n, k, r10[51], ra[15], ra2[100][15];
string a[15];
ll tbl[1<<15][100];

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    cin >> k;

    r10[0] = 1 % k;
    for (int i=1; i<51; ++i)
        r10[i] = 10 * r10[i-1] % k;
    for (int i=0; i<n; ++i)
        for (char c : a[i])
            ra[i] = (10 * ra[i] + c-'0') % k;

    for (int i=0; i<n; ++i)
        for (int r=0; r<k; ++r)
            ra2[r][i] = (r10[a[i].size()] * r + ra[i]) % k;

    tbl[0][0] = 1;
    for (int s=0; s<(1<<n)-1; ++s)
        for (int r=0; r<k; ++r)
            for (int i=0, b=1; i<n; ++i, b<<=1)
                if (!(s&b))
                    tbl[s|b][ra2[r][i]] += tbl[s][r];

    ll p = tbl[(1<<n)-1][0], q = 1;
    for (int i=2; i<=n; ++i) q *= i;
    ll d = gcd(p, q);
    cout << p/d << '/' << q/d;
}