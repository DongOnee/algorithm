// https://www.acmicpc.net/blog/view/25

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

#define INF 987654321

struct point
{
    int x, y;
    bool operator<(const point& b) const { return y!=b.y?y<b.y:x<b.x; }
};

int getDistace(const point& a, const point& b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<point> points; points.resize(n);
    for (int i = 0; i < n; ++i) cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end(), [](const point& a, const point& b) -> bool {
        return a.x < b.x;
    });

    set<point> candi{points[0], points[1]};

    int ans = getDistace(points[0], points[1]);

    for (int cur = 2, start = 0; cur < n; ++cur) {
        point& p = points[cur];
        
        while (start < cur) {
            point st = points[start];

            if ( ans < (p.x - st.x) * (p.x - st.x) ) {
                candi.erase(st);
                ++start;
            }
            else break;
        }

        int d = (int) sqrt(ans) + 1;

        auto lb = candi.lower_bound({-INF, p.y - d});
        auto ub = candi.upper_bound({INF, p.y + d});

        while (lb != ub) {
            ans = min(ans, getDistace(*lb, p));
            ++lb;
        }

        candi.insert(p);
    }

    cout << ans << '\n';

    return 0;
}
