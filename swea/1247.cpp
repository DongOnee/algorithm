#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string.h>

using namespace std;

typedef 
struct _info
{
    int h;
    int c;
    int idx;
    _info() : h(0), c(0), idx(0) {}
    _info(int a, int b, int i) : h(a), c(b), idx(i) {}
}info;

bool operator<(const info& a, const info& b) { return a.c==b.c?a.h>b.h:a.c<b.c; }

const int INF = 987654321;
const int MAXC = 10;

int ans, client_count;
int home[2], company[2], client[MAXC+1][2];
int board[MAXC+2][MAXC+2];
int dp[1<<13][12];
int count_bit[1<<13];

void init()
{
    ans = INF;
    memset(dp, 0 , sizeof(dp));
    cin >> client_count;
    cin >> company[0] >> company[1] >> home[0] >> home[1]; 
    for (int i = 1; i <= client_count; ++i) {
        cin >> client[i][0] >> client[i][1];
        dp[1 | 1 << i][i] = board[0][i] = board[i][0] = abs(company[0] - client[i][0]) + abs(company[1] - client[i][1]);
        dp[1 << (client_count + 1) | 1 << i][i] = board[client_count+1][i] = board[i][client_count+1] = abs(home[0] - client[i][0]) + abs(home[1] - client[i][1]);
        for (int j = 1; j < i; ++j) dp[1 << i | 1 << j][i] = dp[1 << i | 1 << j][j] = board[i][j] = board[j][i] = abs(client[i][0] - client[j][0]) + abs(client[i][1] - client[j][1]);
    }
}

void run()
{
    for (int i = 3; i < 1 << (client_count+1); i+=2) {
        int bit_count = 0;
        int temp = i;
        while (temp) {
            if (temp & 1) ++bit_count;
            temp >>= 1;
        }
        if (bit_count < 3) continue;

        for (int bit_idx = 0; bit_idx <= client_count; ++bit_idx) {
            int p = 1 << bit_idx;
            dp[i][bit_idx] = INF;
            if (i & p) {
                int prv = i ^ p;
                for (int b_idx = 1; b_idx <= client_count; ++b_idx) {
                    int b = 1 << b_idx;
                    if (prv & b) {
                        int nxt = dp[prv][b_idx] + board[bit_idx][b_idx];
                        dp[i][bit_idx] = min(dp[i][bit_idx], nxt);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= client_count; ++i) {
        ans = min(ans, dp[(1 << (client_count+1)) - 1][i] + board[i][client_count+1]);
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
