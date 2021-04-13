#include <iostream>

using namespace std;

const int MAX_HOME = 40;
const int MAXK = 41;

int hr[MAX_HOME], hc[MAX_HOME];
int home_count;
int fee[MAXK];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int k = 1; k <= 40; ++k) fee[k] = 2*k*k+1-2*k;

    int T; cin >> T;
    int n, m, k;
    bool h;
    for (int tc = 1; tc <= T; ++tc) {
        home_count = 0;
        cin >> n >> m;
        for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) {
            cin >> h;
            if (h) {
                hr[home_count] = r, hc[home_count++] = c;
            }
        }

        for (int k = (n/2)*2+1; 0<k; --k) {
            for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) ;
        }
    }

    return 0;
}
