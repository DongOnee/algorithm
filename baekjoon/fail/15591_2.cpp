/**
 * 2020.08.05. 13:49 ~
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXQ = 5001;
const int MAXDIST = 0x7fffffff;

int n, q;
int board[MAXQ][MAXQ];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            board[i][j] = MAXDIST;
        }
        // board[i][i] = 0;
    }

    for (int i = 1, a, b, r; i < n; i++) {
        cin >> a >> b >> r;
        board[a][b] = r;
        board[b][a] = r;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int k = 1; k <= n ; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j || i == k || j == k) {
                    continue;
                }

                int tmp = MAXDIST;
                if (board[i][k] < MAXDIST && board[k][j] < MAXDIST) {
                    tmp = min(board[i][k], board[k][j]);
                }
                board[i][j] = min(board[i][j], tmp);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int i=0, k, v; i<q; i++) {
        cin >> k >> v;
        int ret = 0;
        for (int nextIdx = 1; nextIdx <= n; ++nextIdx) {
            if (k <= board[v][nextIdx] && board[v][nextIdx] < MAXDIST) {
                ++ret;
            }
        }
        cout << ret << '\n';
    }
    
    return 0;
}
