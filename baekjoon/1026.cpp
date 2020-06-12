/**
 * 2020.06.12. 21:56 ~ 20:56
 * 문제에 작은 함정이 있지만 굉장히 쉬운 문제이다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i=0; i<n; ++i)
    {
        a.emplace_back();
        cin >> a[i];
    }
    for (int i=0; i<n; ++i)
    {
        b.emplace_back();
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for (int i=0; i<n; i++)
    {
        ans += (a[i] * b[i]);
    }
    cout << ans << '\n';

    return 0;
}
