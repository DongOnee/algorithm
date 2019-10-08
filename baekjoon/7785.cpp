#include <iostream>
#include <set>
#include <string>
using namespace std;

auto string_cmp = [](string a, string b) {return a > b; };
set<string, decltype(string_cmp)> S(string_cmp);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    while (n--)
    {
        string name, cmd;
        cin >> name >> cmd;
        if (cmd == "enter") S.insert(name);
        else S.erase(name);
    }

    for (string x : S) cout << x << '\n';
    return 0;
}
