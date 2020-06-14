/**
 * 2020.06.14. 11:26 ~
 *  매우매우 쉬운문제... 
 */
#include <iostream>
using namespace std;

int n, a;

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (true)
    {
        cin >> a;
        if (a == 0) break;
        cout << a << " is";
        cout << (a%n == 0?"":" NOT");
        cout << " a multiple of " << n << ".\n";
    }

    return 0;
}
