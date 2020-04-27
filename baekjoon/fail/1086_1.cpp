/**
 * 2020.04.09 20:08 ~
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string arr[15];
int dp[100][1<<15];
bool visited[100][1<<15];

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b%a, a);
}

int run(int remain, int passedBit)
{
    int ret = 0;
    for (int nxt=0; nxt<n; nxt++)
    {
        if (passedBit & (1<<nxt)) continue;
        int nxt_bit = passedBit | (1<<nxt);
        int nxt_remain = remain;
        for (auto& x : arr[nxt])
        {
            nxt_remain *= 10;
            nxt_remain += x-'0';
            nxt_remain %= k;
        }
        ret += run(nxt_remain, passedBit);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;

    int son =  run(0, 0);
    if (son == 0) cout << "0/1" << endl;
    else
    {
        int par = 1;
        while (--n)
            par *= (n+1);
        int g = gcd(son, par);
        cout << son/g <<'/' << par/g <<'\n';
    }

    return 0;
}
