#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n ,ans;
vector<pii> sk;

int main()
{
    scanf("%lld", &n);
	while (n)
    {
		int pos = n;
		ans = 0;
		for (int i = 0, a; i < n; i++)
        {
            scanf("%d", &a);

            if (sk.empty()) sk.push_back({i, a});
			else 
            {
				if(sk.back().second > a) 
                {
					while (!sk.empty() && sk.back().second > a) 
                    {
						pos = sk.back().first;
						ll t = (i - pos) * sk.back().second;
						ans = ans < t ? t : ans;
						sk.pop_back();
					}
                    sk.push_back({pos, a});
				}
				else if (sk.back().second == a) continue;
				else sk.push_back({i, a});
			}
		}
		for (pii x : sk)
        {
			ll t = (n - x.first) * x.second;
			ans = ans < t ? t : ans;
		}
        sk.clear();
        printf("%lld\n", ans);
        scanf("%lld", &n);
	}
	return 0;
}
