#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

typedef pair<int,int> pii;

int board_size;
int init_k;
int m;
vector<pii> home_list;

#define dist(a,b) abs(a.first-b.first)+abs(a.second-b.second)

void init()
{
    int home;
    home_list.clear();
    cin >> board_size >> m;
    for (int r = 0; r < board_size; ++r) for (int c = 0; c < board_size; ++c) {
        cin >> home;
        if (home) {
            home_list.emplace_back(r, c);
        }
    }
    init_k = (board_size/2)*2 + 1;
}

int run()
{
    init();
    int ret = 0;

    for (int k = init_k; 0<k; --k) {
        int fee = 2*k*k+1-2*k;
        for (int r = 0; r < board_size; ++r) {
            for (int c = 0; c < board_size; ++c) {
                int cnt = 0;
                for (auto& h : home_list) {
                    int dst = dist(h, make_pair(r,c));
                    if (dst < k) ++cnt;
                }

                if (m * cnt >= fee) ret = max(ret, cnt);
            }
        }

    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("~/Downloads/input.txt", "r", stdin);


    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {

        cout << '#' << tc << ' ' << run() << '\n';
    }

    return 0;
}
