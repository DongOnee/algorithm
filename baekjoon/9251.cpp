
#include <iostream>
#include <string.h>
using namespace std;

const int MAXLEN = 1002;

int dp[MAXLEN][MAXLEN];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int a1 = a.length();
    int b1 = b.length();

    for (int i=0; i<a1; i++)
    {
        for (int j=0; j<b1; j++)
        {
            if (a[i] == b[j])
                dp[i+1][j+1] = dp[i][j] +1;
            else 
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }

    cout << dp[a1][b1] << '\n';

    return 0;
}
