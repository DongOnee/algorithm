/**
 * 2019-08-25 22:35 ~
 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, tree[1000001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        cin >> n >> m;
        for (int i=0; i<n; i++) cin >> tree[i];

        sort(tree, tree+n);
        ans = 0;

        int l = 0, r = tree[n-1]+1;
        while (l < r)
        {
            int md_tree = ( l + r ) / 2;
            long long sum = 0;
            for (int idx = 0; idx < n; idx++)
            {
                if ( md_tree < tree[idx] ) sum += (tree[idx] - md_tree);
            }

            if (sum < m) r = md_tree;
            else 
            {
                ans = max(ans, md_tree);
                l = md_tree +1;
            }
        }

        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}
