/**
 * 2019-08-27 23:29~24:43
 */
#include <cstdio>
#include <vector>
using namespace std;

int n, k, dp[10001][2];
bool tog = false;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    for (int i=0, input; i<n; i++) 
    {
        scanf("%d", &input);
        vt.push_back(input);
    }

    dp[0][tog] = 1;
    dp[0][!tog] = 1;
    for (int x : vt)
    {
        for (int sumValue = 1; sumValue<=k; sumValue++)
        {
            if (sumValue < x) dp[sumValue][tog] = dp[sumValue][!tog];
            else dp[sumValue][tog] = dp[sumValue - x][tog] + dp[sumValue][!tog];
        }
        tog ^= 1;
    }
    printf("%d\n", dp[k][!tog]);
    return 0;
}
