#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        mp.clear();
        int n; cin >> n;
        while (n--)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (mp.count(s2) == 0) mp[s2] = 1;
            else mp[s2]++;
        }
        int ans = 1;
        for (auto x : mp) ans *= (x.second+1);
        cout << ans-1 << '\n';
    }
    return 0;
}
