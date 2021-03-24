#include <iostream>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const pii dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};
const int MAXN = 2000;

int board[MAXN*2+4][MAXN*2+4][2];

pii atoms[1001];
int atom_count;
int ans;
vector<pii> alived;
bool flag;
int c;

void init()
{
    ans = 0;
    flag = false;

    memset(board, 0, sizeof(board));
    for (int i = 0; i < 4003; ++i) {
        board[i][0][1] = -1;
        board[0][i][1] = -1;
        board[i][4002][1] = -1;
        board[0][4002][1] = -1;
        board[i][0][0] = -1;
        board[0][i][0] = -1;
        board[i][4002][0] = -1;
        board[0][4002][0] = -1;
    }

    int m,x,y,d,k;
    cin >> m;
    for (atom_count = 1; atom_count <= m; ++atom_count) {
        cin >> x >> y >> d >> k;
        x = (x + 1000) * 2 + 1;
        y = (y + 1000) * 2 + 1;
        board[x][y][flag] = atom_count;
        atoms[atom_count] = {d, k};
    }
}

bool move_atom()
{
    bool fg = true;
    vector<pii> bomb;
    for (int x = 1; x <= 4001; ++x) {
        for (int y = 1; y <= 4001; ++y) {
            if (board[x][y][flag] <= 0) continue;

            int idx = board[x][y][flag];
            int d = atoms[idx].first;
            int k = atoms[idx].second;
            int nx = x + dirs[d].first;
            int ny = y + dirs[d].second;
            bool z = true;

            if (board[nx][ny][!flag] == -1) z = false;
            else if (board[nx][ny][!flag] == 0) board[nx][ny][!flag] = idx;
            else {
                bomb.emplace_back(nx,ny);
                ans += k;
            }

            if (z) fg = false;

            board[x][y][flag] = 0;
        }
    }
    if (fg) return false;

    for (auto& p : bomb) {
        int x = p.first;
        int y = p.second;
        if (board[x][y][!flag] != 0) {
            ans += atoms[board[x][y][!flag]].second;
            board[x][y][!flag] = 0;
        }
    }
    flag ^= true;

    return true;
}

void chk_atoms()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        while (move_atom()) {
            ++c;
            chk_atoms();
        }

        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}
