#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef pair<int,uint> pii;

uint init_remain[32];
uint cnt_remain[32];
uint m, n, ans;
int si[500];
int mx_idx;
bool done[500];
vector<pii> vt;

void init()
{
    ans = 1;
    mx_idx = 0;
    vt.clear();
    for (int i = 0; i < 32; ++i) init_remain[i] = cnt_remain[i] = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> si[i];
        done[i] = false;
    }

    sort(si, si+n);

    int prv_i = -1, max_i = -1;
    for (int i = 31; 0 <= i; --i) {
        if (((uint) 1 << i) <= m) {
            mx_idx = max(mx_idx, i);
            m -= (uint)1 << i;
            if (max_i == -1) {
                cnt_remain[i] = init_remain[i] = 1;
                max_i = 1;
            }
            else {
                cnt_remain[i] = init_remain[i] = 2 * max_i * (1 << (prv_i - i)) + 1;
                max_i = max_i * (1 << (prv_i - i)) + 1;
            }
            prv_i = i;
        }
    }
}

void run()
{
    int remain = n;
    bool r = true;

    while (remain) {
        r = false;
        for (int sidx = n-1; 0 <= sidx && !r; --sidx) {
            if (done[sidx]) continue;

            int sz = si[sidx];
            for (int ridx = sz; ridx <= mx_idx; ++ridx) {
                if (cnt_remain[ridx] > 0) {
                    --cnt_remain[ridx];
                    done[sidx] = true;
                    cnt_remain[sz] += ((uint)1 << (2 * (ridx - sz))) - 1;
                    r = true;
                    --remain;
                    break;
                }
            }
        }

        if (!r) {
            ++ans;
            for (int i = 0; i < 32; ++i) cnt_remain[i] = init_remain[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
