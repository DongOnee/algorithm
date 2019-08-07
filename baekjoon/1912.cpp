#include <iostream>
using namespace std;
#define _MAXN 100000
#define MAX(a, b) (a)>(b)?(a):(b)

int dp[_MAXN+1], ans;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n; i++)
    {
        int input; cin >>input;
        if (i == 0) 
        {
            dp[i] = input;
            ans = dp[i];
        }
        else
        {
            dp[i] = MAX(dp[i-1] + input, input);
            ans = MAX(ans, dp[i]);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
