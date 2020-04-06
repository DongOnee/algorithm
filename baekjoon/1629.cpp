/**
 * 2020.04.06 20:50 ~ 20:58
 */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    long long ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret *= a;
            ret %= c;
        }
        a *= a;
        a %= c;
        b >>= 1;
    }

    cout << ret;

    return 0;
}
