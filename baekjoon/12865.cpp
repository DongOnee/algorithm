#include <iostream>
#include <vector>
#include <algorithm>
#define VALUE first
#define WEIGHT second
#define MAXN 100000
using namespace std;

typedef pair<int, int> pii;

int n, k;
vector<pii> goods;
int dp[MAXN+1][2];
bool toggle;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        pii tmp;
        cin >> tmp.WEIGHT >> tmp.VALUE;
        goods.push_back(tmp);
    }

    for (int i=0; i<n; i++)
    {
        for (int j=1; j<=k; j++)
        {
            if (j < goods[i].WEIGHT) dp[j][toggle] = dp[j][!toggle];
            else dp[j][toggle] = max(dp[j][!toggle], dp[j-goods[i].WEIGHT][!toggle] + goods[i].VALUE);
        }
        toggle = !toggle;
    }

    cout << max(dp[k][toggle], dp[k][!toggle]) << '\n';

    return 0;
}
