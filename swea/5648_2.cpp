#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const pii dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};
const int inv_dirs[4] = {1, 0, 3, 2};

map<pii, int> st;
map<pii, vector<int>> mp;

int board[2001][2001][2];
vector<pii> alived;
bool bf;
set<int> visited;

pii atoms[1001];
int atom_count;
int ans;

void init()
{
    bf = false;
    ans = 0;
    memset(board, 0, sizeof(board));
    
    cin >> atom_count;
    for (int i = 1; i <= atom_count; ++i) {
        int x, y, d, k;
        cin >> x >> y >> d >> k;
        board[x+1000][y+1000][0] = i;
        alived.emplace_back(x+1000,y+1000);
        atoms[i] = {d, k};
    }
}

bool chk(pii cur) { return 0<=cur.first&&cur.first<=2000&&0<=cur.second&&cur.second<=2000;}

void move_atom(int idx, pii cur)
{
    visited.insert(idx);
    int x = cur.first;
    int y = cur.second;
    int d = atoms[idx].first;
    int k = atoms[idx].second;
    pii nxt = cur + dirs[d];
    if (!chk(nxt)) return;

    int nx = nxt.first;
    int ny = nxt.second;

    if (board[nx][ny][bf] > 0) {
        int prev_idx = board[nx][ny][bf];
        int prev_d = atoms[prev_idx].first;
        int prev_k = atoms[prev_idx].second;

        if (prev_k == 0);
        else if (inv_dirs[d] == prev_d) {
            ans += k;
            ans += prev_k;
            atoms[idx].second = 0;
            atoms[prev_idx].second = 0;
            visited.insert(prev_idx);
        }
        else if (visited.find(prev_idx) == visited.end()) move_atom(prev_idx, nxt);

        board[nx][ny][!bf] = idx;
        board[x][y][bf] = 0;
        alived.emplace_back(nxt);
    }
    else {
        vector<pii> assembled;

        for (int d = 0; d < 4; ++d) {
            pii nnxt = nxt + dirs[d];
            if (!chk(nnxt)) continue;
            int nn_idx = board[nnxt.first][nnxt.second][bf];
            
            if (nn_idx > 0 && atoms[nn_idx].second > 0 && atoms[nn_idx].first == inv_dirs[d]) {
                assembled.emplace_back(nnxt);
            }
        }

        if (assembled.size() == 1) {
            pii atom = assembled[0];
            int alived_idx = board[atom.first][atom.second][bf];
            board[atom.first][atom.second][bf] = 0;
            visited.insert(alived_idx);
            board[nxt.first][nxt.second][!bf] = alived_idx;
            alived.emplace_back(nxt);
        }
        else {
            for (pii& p : assembled) {
                int atom_idx = board[p.first][p.second][bf];
                board[p.first][p.second][bf] = 0;
                ans += atoms[atom_idx].second;
                atoms[atom_idx].second = 0;
            }
        }
    }
}


void move_atoms()
{
    vector<pii> prev_alived;
    swap(alived, prev_alived);
    visited.clear();

    for (pii& cur : prev_alived) {
        int x = cur.first;
        int y = cur.second;
        int idx = board[x][y][bf];
        int d = atoms[idx].first;
        int k = atoms[idx].second;

        if (k == 0) continue;
        if (visited.find(idx) != visited.end()) continue;
        move_atom(idx, cur);
    }
    bf ^= true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        while (!alived.empty()) {
            move_atoms();
        }

        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}
