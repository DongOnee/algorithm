/**
 * 19.06.12 22:32 ~ 24:22
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> n_val, m_val;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, a; i<n; i++)
    {
        scanf("%d", &a);
        n_val.push_back(a);
    }
    scanf("%d", &m);
    for (int i=0, a; i<m; i++)
    {
        scanf("%d", &a);
        m_val.push_back(a);
    }

    sort(n_val.begin(), n_val.end());

    for (int x : m_val)
    {
        int l = 0, r = n;
        bool chk = false;

        while (l < r)
        {
            int mid = (l+r)/2;
            if (x == n_val[mid])
            {
                chk = true;
                break;
            }
            else if (x < n_val[mid]) r = mid;
            else l = mid + 1;
        }

        if (chk) printf("1 ");
        else printf("0 ");
    }
    
    printf("\n");

    return 0;
}
