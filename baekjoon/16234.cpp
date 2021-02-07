#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int,int> pii;
pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN  = 50;
const vector<pii> dirs = { {1,0}, {0,1} , {-1,0}, {0,-1} };

int n, l, r, ans;
int a[MAXN][MAXN];
int grp[MAXN][MAXN];
int sum[MAXN * MAXN];
int cnt[MAXN * MAXN];
int grp_count;

bool chk(pii c) { return 0<=c.first&&c.first<n&&0<=c.second&&c.second<n; }

void bfs(int _r, int _c)
{
    grp[_r][_c] = grp_count;
    cnt[grp_count] = 1;
    sum[grp_count] = a[_r][_c];

    queue<pii> qu;
    qu.push({_r, _c});

    while (!qu.empty()) {
        pii f = qu.front(); qu.pop();

        for  (pii d : dirs) {
            pii nxt = f + d;
            if (!chk(nxt)) continue;
            if (grp[nxt.first][nxt.second] != -1) continue;

            int diff = abs(a[f.first][f.second] - a[nxt.first][nxt.second]);
            if (l <= diff && diff <= r) {
                grp[nxt.first][nxt.second] = grp_count;
                ++cnt[grp_count];
                sum[grp_count] += a[nxt.first][nxt.second];
                qu.push(nxt);
            }
        }
    }

    ++grp_count;
}

void run() 
{
    for (;;) {
        grp_count = 0;

        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                grp[i][j] = -1;
            }
        }

        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grp[i][j] == -1) bfs(i, j);
            }
        }

        if (grp_count == n * n) break;
        ++ans;
        
        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int gr = grp[i][j];
                a[i][j] = sum[gr] / cnt[gr];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    run();

    cout << ans << '\n';

    return 0;
}
