#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int m, int n)
{
    if (m%n ==0) return m;
    return gcd(n, m%n);
}

int lcd(int m, int n)
{
    
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int xy = gcd(x, y);

        cout << xy << endl;

    }
    return 0;
}
