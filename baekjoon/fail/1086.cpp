/**
 * 2020.04.08 12:38 ~
 */
#include <iostream>
#include <string>
using namespace std;

int n, k, par;
string arr[15];
int dp[15][1<<15];

int func(int remain, int cur, int calcedBit)
{
    if (calcedBit == (1<<n) -1) 
    {
        par++;
        return remain?0:1;
    }
    for (int i=0; i<n; i++)
    {
        if ( !((1<<i) & calcedBit) )
        {
            int nxt_remain = remain;
            for (auto x : arr[i])
            {
                nxt_remain *= 10;
                nxt_remain += x-'0';
                nxt_remain %= k;
            }
            dp[cur][calcedBit] += func(nxt_remain, i, calcedBit | (1<<i));
        }
    }
    return dp[cur][calcedBit];
}

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;

    int son = func(0, 0, 0);
    if (son == 0) cout << "0/1" << '\n';
    else
    {
        int g = gcd(son, par);
        cout << g << '\n';
        cout << son/g << '/' << par/g << '\n';
    }

    return 0;
}
