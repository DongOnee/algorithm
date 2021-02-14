#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN = 50;
const int EMPTY     = 0;
const int WALL      = 1;
const int VIRUS     = 2;

const pii dirs[4]   = {{1,0},{0,1},{-1,0},{0,-1}};

int board[MAXN][MAXN];
int board_init[MAXN][MAXN];
int board_size, active_virus_cnt;
int empty_cnt, ans = 987654321;

bool visited[MAXN][MAXN];

vector<pii> viruses;

void dfs(int st, vector<int>& viruses_idx)
{
    if (viruses_idx.size() == active_virus_cnt) {
        memcpy(board, board_init, sizeof(board));
        memset(visited, false, sizeof(visited));

        queue<pii> qu;
        int remain = empty_cnt;
        int t = 0;
        for (auto x : viruses_idx) {
            qu.push(viruses[x]);
            visited[viruses[x].first][viruses[x].second] = true;
        }

        while (!qu.empty() && remain > 0) {
            long sz = qu.size();
            ++t;
            while (sz--) {
                pii f = qu.front(); qu.pop();
                for (int d = 0; d < 4; ++d) {
                    pii nxt = f + dirs[d];
                    if (nxt.first < 0 || board_size <= nxt.first || nxt.second < 0 || board_size <= nxt.second) continue;
                    if (visited[nxt.first][nxt.second]) continue;
                    if (board[nxt.first][nxt.second] == WALL) continue;

                    visited[nxt.first][nxt.second] = true;
                    if (board[nxt.first][nxt.second] == EMPTY) --remain;
                    qu.push(nxt);
                }
            }
        }

        if (remain == 0)
            ans = min(ans, t);

        return;
    }

    for (int i = st; i < viruses.size(); ++i) {
        viruses_idx.emplace_back(i);
        dfs(i + 1, viruses_idx);
        viruses_idx.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size >> active_virus_cnt;

    for (int r = 0; r < board_size; ++r) {
        for (int c = 0; c < board_size; ++c) {
            cin >> board_init[r][c];
            if (board_init[r][c] == VIRUS) {
                viruses.emplace_back(r, c);
            }
            else if (board_init[r][c] == EMPTY) {
                ++empty_cnt;
            }
        }
    }

    vector<int> active_viruses_idx;
    dfs(0, active_viruses_idx);

    cout << (ans==987654321?-1:ans) << '\n';

    return 0;
}
