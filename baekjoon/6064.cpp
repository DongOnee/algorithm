#include <iostream>
#include <algorithm>
using namespace std;

// m >= n
int gcd(int m, int n)
{
    if (m%n ==0) return n;
    return gcd(n, m%n);
}

int lcm(int m, int n)
{
    return m*n/gcd(m, n);
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n, x, y, mn;
        cin >> m >> n >> x >> y;

        if (m<n) mn = lcm(n, m);
        else mn = lcm(m, n);


        while(x != y && x < mn)
        {
            if ( x < y ) x += m;
            else y += n;
        }
        if ( x != y ) cout << "-1" <<endl;
        else cout << x << endl;
    }
    return 0;
}
