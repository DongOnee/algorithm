/**
 * 2019.10.01. 22:05 ~ 22:34
 * Fail
 */
#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> vt;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0, a, b; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        vt.push_back({a+b, a*b});
    }

    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            for (int k=j+1; k<=n; k++)
            {
                int flag = true;
                for (auto x : vt)
                {
                    if (i+j+k - x.first == i*j*k/x.second && (i*j*k)%x.second == 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
