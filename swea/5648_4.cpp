#include <iostream>
#include <vector>
#include <utility>


using namespace std;

typedef pair<int,int> pii;
typedef struct
{
    int d;
    int k;
}atom_info;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const pii dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};
const int inv_dirs[4] = {1,0,3,2};

int board[2001][2001][2];
bool board_flag;

atom_info atoms[1001];
int atom_count;
int ans;

vector<pii> alive_points;


bool chk(pii a) { return 0<=a.first&&a.first<2001&&0<=a.second&&a.second<2001; }

void init()
{
    board_flag = false;
    ans = 0;

    cin >> atom_count;
    for (int i = 1; i <= atom_count; ++i) {
        int x, y, d, k;
        cin >> x >> y >> d >> k;
        x += 1000, y += 1000;
        atoms[i] = {d, k};
        board[x][y][false] = i;
        alive_points.emplace_back(x,y);
    }
}


void run()
{
    vector<pii> t;
    vector<pii> tmp_alive_points;

    for (pii cur : alive_points) {
        int idx = board[cur.first][cur.second][board_flag];
        if (idx == 0) continue;
        board[cur.first][cur.second][board_flag] = 0;

        pii nxt = cur + dirs[atoms[idx].d];
        if (!chk(nxt)) continue;

        int nxt_idx = board[nxt.first][nxt.second][board_flag];
        if (nxt_idx > 0 && atoms[nxt_idx].d == inv_dirs[atoms[idx].d] && atoms[nxt_idx].k > 0) {
            board[nxt.first][nxt.second][board_flag] = 0;
            ans += atoms[idx].k;
            ans += atoms[nxt_idx].k;
        }
        else {
            int iidx = board[nxt.first][nxt.second][!board_flag];
            if (iidx == 0) {
                board[nxt.first][nxt.second][!board_flag] = idx;
                tmp_alive_points.emplace_back(nxt);
            }
            else {
                ans += atoms[idx].k;
                atoms[idx].k = 0;
                t.emplace_back(nxt);
            }
        }
    }
    alive_points.clear();

    for (auto & cur : t) {
        int idx = board[cur.first][cur.second][!board_flag];
        board[cur.first][cur.second][!board_flag] = 0;
        ans += atoms[idx].k;
        atoms[idx].k = 0;
    }

    for (auto& cur : tmp_alive_points) {
        int idx = board[cur.first][cur.second][!board_flag];
        if (atoms[idx].k == 0) continue;
        alive_points.emplace_back(cur);
    }
    board_flag ^= true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        while (!alive_points.empty()) run();

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
