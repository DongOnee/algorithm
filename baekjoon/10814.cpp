#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
vector<pair<pair<int, int>, string>> vt;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0, a; i<n; i++)
    {
        string s;
        cin >> a >> s;
        vt.push_back({{a, i}, s});
    }
    
    sort(vt.begin(), vt.end());

    for (auto x : vt) cout << x.first.first << ' ' << x.second << '\n';

    return 0;
}
