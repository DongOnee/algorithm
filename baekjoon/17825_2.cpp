#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

typedef pair<int,int> pii;

const int GOAL = 32;

const int scores[33] = {0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 
                           22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 
                           13, 16, 19, 22, 24, 25, 26, 27, 28, 30,
                           35,  0};
const vector<int> route_idx[4] = {
    { 0,  1,  2,  3,  4,  5,  6,  7,  8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 32},
    { 5, 21, 22, 23, 26, 30, 31, 20, 32},
    {10, 24, 25, 26, 30, 31, 20, 32},
    {15, 29, 28, 27, 26, 30, 31, 20, 32}
};

map<pii, int> mp;

int move_values[10], ans;
pii idx_pieces[4];

pii piece_move(pii cur, int val) {
    int stat = cur.first;
    int idx = cur.second;

    if (idx + val >= route_idx[stat].size()) return {0, 21};

    idx += val;
    if (mp.find({stat,idx}) != mp.end()) {
        stat = mp[{stat,idx}];
        idx = 0;
    }

    return {stat, idx};
}

void dfs(int step, int score)
{
    if (step == 10) {

        ans = max(ans, score);
        return;
    }

    int move_value = move_values[step];
    for (int idx = 0; idx < 4; ++idx) {
        if (route_idx[idx_pieces[idx].first][idx_pieces[idx].second] == GOAL) continue;
        pii nxt = piece_move(idx_pieces[idx], move_value);

        if (route_idx[nxt.first][nxt.second] == GOAL);
        else if (route_idx[idx_pieces[0].first][idx_pieces[0].second] == route_idx[nxt.first][nxt.second]) continue;
        else if (route_idx[idx_pieces[1].first][idx_pieces[1].second] == route_idx[nxt.first][nxt.second]) continue;
        else if (route_idx[idx_pieces[2].first][idx_pieces[2].second] == route_idx[nxt.first][nxt.second]) continue;
        else if (route_idx[idx_pieces[3].first][idx_pieces[3].second] == route_idx[nxt.first][nxt.second]) continue;

        pii tmp = idx_pieces[idx];
        idx_pieces[idx] = nxt;
        dfs(step+1, score + scores[route_idx[idx_pieces[idx].first][idx_pieces[idx].second]]);
        idx_pieces[idx] = tmp;
    }
}

void run()
{
    ans += scores[move_values[0]];
    idx_pieces[0] = piece_move(idx_pieces[0], move_values[0]);

    dfs(1, scores[move_values[0]]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; ++i) cin >> move_values[i];

    mp.insert({{0, 5}, 1});
    mp.insert({{0, 10}, 2});
    mp.insert({{0, 15}, 3});
    run();

    cout << ans << '\n';

    return 0;
}
