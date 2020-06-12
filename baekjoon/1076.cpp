/**
 * 2020.06.12. 22:31 ~
 */
#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

map<string, pair<int, int>> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mp["black"] = { 0, 1 };
    mp["brown"] = { 1, 10 };
    mp["red"] = { 2, 100 };
    mp["orange"] = { 3, 1000 };
    mp["yellow"] = { 4, 10000 };
    mp["green"] = { 5, 100000 };
    mp["blue"] = { 6, 1000000 };
    mp["violet"] = { 7, 10000000 };
    mp["grey"] = { 8, 100000000 };
    mp["white"] = { 9, 1000000000 };

    string st, st2, st3;
    cin >> st >> st2 >> st3;

    cout << (long long) mp[st3].second * ( mp[st].first * 10 + mp[st2].first );

    return 0;
}
