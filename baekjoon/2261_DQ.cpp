#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> point;

bool operator<(const point& a, const point& b) 
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int sqrt_point(const point& a, const point& b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }

int n; 
int ans = 987654321;
vector<point> vt;

int sol(int st, int ed) 
{
    if (ed - st < 2) return 987654321;
    if (ed - st == 2) return sqrt_point(vt[st], vt[st+1]);
    if (ed - st == 3) return min(min(sqrt_point(vt[st], vt[st+1]), sqrt_point(vt[st+1], vt[st+2])), sqrt_point(vt[st], vt[st+2]));

    int m = (ed + st) / 2;

    int mid = vt[m-1].first + vt[m].first; mid /= 2;
    int d = min(sol(st,m), sol(m, ed));

    vector<point> across_y;

    for (int i = st; i < ed; ++i) {
        int tmp = mid - vt[i].first;
        if (tmp * tmp < d) across_y.push_back(vt[i]);
    }
    sort(across_y.begin(), across_y.end(), [](const point& a, const point& b) -> bool { return a.second < b.second; });

    for (auto itr = across_y.begin(); itr != across_y.end(); ++itr) {
        auto itr2 = itr + 1;
        while (itr2 != across_y.end()) {
            if (d <= (itr->second - itr2->second) * (itr->second - itr2->second)) break;
            d = min(d, sqrt_point(*itr, *itr2));
            ++itr2;
        }
    }

    return d;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0, x,y; i < n; ++i) {
        cin >> x >> y;
        vt.emplace_back(x, y);
    }

    sort(vt.begin(), vt.end()); 

    cout << sol(0, n) << '\n';

    return 0;
}
