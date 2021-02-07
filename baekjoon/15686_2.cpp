#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first, a.second+b.second); }

const int INF   = 987654321;
const int MAXN  = 50;
const int MAXM  = 13;
const int HOME  = 1;
const int CHI   = 2;
const pii dirs[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int board[MAXN][MAXN];
int home_to_chi[2*MAXN][MAXM];
int home_to_chi_cp[2*MAXN][MAXM];
int board_wi, choose_count, chi_count;
pii chi_info[MAXM];
map<pii, int> chi_idx;

pii home_info[2*MAXN];
int home_count;
bool visited[MAXN][MAXN];

int ans = INF;

void dfs(int st, int cnt)
{
    if (cnt == choose_count) {
        int sum = 0;
        for (int ho = 0; ho < home_count; ++ho) {
            int len = INF;
            for (int ch = 0; ch < chi_count; ++ch) {
                len = min(len, home_to_chi_cp[ho][ch]);
            }
            sum += len;
        }
        ans = min(ans, sum);

        return ;
    }
    for (int idx = st; idx < chi_count; ++idx) {
        for (int j = 0; j < home_count; ++j) home_to_chi_cp[j][idx] = home_to_chi[j][idx];
        dfs(idx+1, cnt+1);
        for (int j = 0; j < home_count; ++j) home_to_chi_cp[j][idx] = INF;
    }
}

void run()
{
    queue<pii> qu;
    for (int i = 0; i < home_count; ++i) {
        memset(visited, false, sizeof(visited));
        qu.push(home_info[i]);
        visited[home_info[i].first][home_info[i].second] = true;

        int len = 0;
        while (!qu.empty() ) {
            ++len;
            long sz = qu.size();
            while (sz--) {
                pii f = qu.front(); qu.pop();
                for (int d = 0; d < 4; ++d) {
                    pii nxt = f + dirs[d];
                    if (nxt.first < 0 || board_wi <= nxt.first || nxt.second < 0 || board_wi <= nxt.second) continue;
                    if (visited[nxt.first][nxt.second]) continue;
                    
                    visited[nxt.first][nxt.second] = true;
                    qu.push(nxt);
                    if (board[nxt.first][nxt.second] == CHI) {
                        int ch =  chi_idx.at(nxt);
                        home_to_chi[i][ch] = len;
                    }
                }
            }
        }
    }

#if 0
    for (int ho = 0; ho < home_count; ++ho) {
        for (int ci = 0; ci < chi_count; ++ci) 
            cout << home_to_chi[ho][ci] << ' ';
        cout << '\n';
    }
#endif

    dfs(0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_wi >> choose_count;
    for (int i = 0; i < board_wi; ++i) {
        for (int j = 0; j < board_wi; ++j) {
            cin >> board[i][j];
            if (board[i][j] == CHI) {
                chi_info[chi_count] = {i, j};
                chi_idx.insert({{i, j}, chi_count});
                chi_count++;
            }
            else if (board[i][j] == HOME) {
                home_info[home_count] = {i, j};
                home_count++;
            }
        }
    }

    for (int ho = 0; ho < home_count; ++ho) {
        for (int ci = 0; ci < chi_count; ++ci) {
            home_to_chi[ho][ci] = INF;
            home_to_chi_cp[ho][ci] = INF;
        }
    }

    run();
    
    cout << ans << '\n';

    return 0;
}
