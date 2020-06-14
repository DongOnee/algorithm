/**
 * 2020.06.14. 12:34 ~ 13:00
 * list iterator 사용하는거 말고 특별한거 없다
 */
#include <iostream>
#include <list>
using namespace std;

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    list<int> lt;
    for (int i=0; i<n; i++)
    {
        lt.push_back(i+1);
    }
    int st = 0;
    k--;
    cout << "<";
    while (n)
    {
        st += k;
        st %= n;

        auto itr = lt.begin();

        for (int i=0; i<st; i++)
        {
            itr++;
        }
        cout << *itr;
        lt.erase(itr);
        --n;
        if (n) cout << ", ";
    }
    cout << ">\n";

    return 0;
}
