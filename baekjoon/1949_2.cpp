#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int const MAXN = 10'000;

vector<int> tree[MAXN];
vector<int> child[MAXN];
vector<int> village_depth[MAXN];
int people[MAXN];
int village_count;
int dp[MAXN][3];
bool visited[MAXN];
int max_depth;

void  func1(int index, vector<int>& use_first_child)
{
    for (auto& x : use_first_child) {
        int ret = dp[x][0];
        for (auto& c : child[index]) {
            if (x == c) continue;
            ret += max(dp[c][0], dp[c][1]);
        }
        dp[index][1] = max(dp[index][1], ret);
    }
}

void bfs() 
{
    visited[0] = true;
    queue<int> qu; qu.push(0);

    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz--) {
            int f = qu.front(); qu.pop();
            village_depth[max_depth].emplace_back(f);

            for (auto& nxt : tree[f]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                child[f].push_back(nxt);
                qu.push(nxt);
            }
        }
        ++max_depth;
    }
}

void run()
{
    bfs();
    
    for (int depth = max_depth - 1; 0 <= depth; --depth) {
        for (auto& searchIndex : village_depth[depth])  {
            bool selected = true;
            bool not_selected = true;
            vector<int> index_child_not_selected;
            for (auto& c : child[searchIndex]) {
                if (dp[c][1] == -1 && dp[c][2] == -1) selected = false;
                if (dp[c][1] == -1) not_selected = false;
                if (dp[c][0] != -1) index_child_not_selected.emplace_back(c);
            }

            if (selected) {
                dp[searchIndex][0] = people[searchIndex];
                for (auto& c : child[searchIndex]) {
                    dp[searchIndex][0] += max(dp[c][1], dp[c][2]);
                }
            }

            if (not_selected) {
                dp[searchIndex][2] = 0;
                for (auto& c : child[searchIndex]) {
                    dp[searchIndex][2] += dp[c][1];
                }
            }

            if (index_child_not_selected.size() > 0) {
                func1(searchIndex, index_child_not_selected);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> village_count;
    for (int i = 0; i < village_count; ++i)
        cin >> people[i];
    
    for (int i = 0, a, b; i < village_count - 1; ++i) {
        cin >> a >> b;
        tree[a-1].emplace_back(b-1);
        tree[b-1].emplace_back(a-1);
    }

    run();

    //cout << max(max(dp[0].first, dp[0].second.first), dp[0].second.second) << '\n';
    cout << max(dp[0][0], dp[0][1]);

    return 0;
}
