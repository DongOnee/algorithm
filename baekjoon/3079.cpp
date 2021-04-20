#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef
struct _info
{
    int sum;
    int t;
    _info(int s, int x) : sum(s), t(x) {}
}info;

bool operator<(const info& a, const info& b) { return a.sum+a.t==b.sum+b.t?a.t>b.t:a.sum+a.t>b.sum+b.t; }

int judge_count, human_count;
priority_queue<info> pq;
vector<info> vt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> judge_count >> human_count;
    for (int i = 0; i < judge_count; ++i) {
        int t; cin >> t;
        pq.emplace(0, t);
        // vt.emplace_back(0,t);
    }

    sort(vt.begin(), vt.end());
    int ans = 0;
    for (int i = 0; i < human_count; ++i) {
        // auto tp = pq.top(); pq.pop();
        // auto& tp = vt.back();

        auto& tp = pq.top();
        // tp.sum += tp.t;
        // sort(vt.begin(), vt.end());
        ans = max(ans, tp.sum);
    }

    cout << ans << '\n';

    return 0;
}
