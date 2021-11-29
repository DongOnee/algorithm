/**
 * 2020.05.24. 16:34 ~
 */
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXN = 100001;

int n, m, arr[MAXN], sum[MAXN], dp[MAXN][MAXN];

int calc(int a, int b)
{
    int& dpab = dp[a][b];
    if (dpab != -1) return dp[a][b];
    if ( sum[b] - sum[a-1] == 0) return dpab = b - a + 1;
    return dpab = max(calc(a+1, b), calc(a, b-1));
}

void sol()
{
    int a, b; cin >> a >> b;

    cout << calc(a, b) << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i=1; i<=n; i++) 
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
        if (sum[i] == 0)
            dp[1][i] = i;
        dp[i][i] = 0;
    }
        

    cin >> m;
    while (m--)
        sol();

    return 0;
}
