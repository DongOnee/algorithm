/**
 * 2019.08.07. 23:49 ~
 */
#include <iostream>
using namespace std;

typedef long long ll;
bool ans[1000001];
bool visited[1000001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m; cin >> n >> m;

    int cnt = (m-n+1);

    for (ll comp = 2, comp2; (comp2 = comp * comp) <= m; comp++)
    {
        if (visited[comp]) continue;
        for (int k = comp; (ll) k*k <= m; k += comp) visited[k] = true;
        for (ll comp3 = comp2; comp3 <= m; comp3 += comp2)
        {
            if (comp3 - n >= 0)
            {
                if (!ans[comp3 - n]) cnt--;
                ans[comp3 - n] = true;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}