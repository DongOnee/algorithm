#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

const int MAXN  = 50;
const int MAXM  = 1000;
const int dirs[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

typedef struct _fireball_attr
{
    int _m, _s, _d;
    _fireball_attr(int m, int s, int d) : _m(m), _s(s), _d(d) {}
}fireball_attr;

typedef struct _fireball_info
{
    int _r, _c;
    fireball_attr _att;
    _fireball_info(int r, int c, int m, int s, int d) : _r(r), _c(c), _att(m, s, d) {}
    _fireball_info(int r, int c, fireball_attr attr) : _r(r), _c(c), _att(attr) {}
}fireball_info;

vector<fireball_attr> board[MAXN][MAXN];
int board_size;

void move(fireball_info& f) 
{
    f._r += dirs[f._att._d][0] * f._att._s;
    f._c += dirs[f._att._d][1] * f._att._s;
    if (f._r < 0)   f._r = board_size - ((-f._r) % board_size);
    f._r %= board_size;

    if (f._c < 0)   f._c = board_size - ((-f._c) % board_size);
    f._c %= board_size;
}

void move(vector<pii>& points)
{
    vector<fireball_info> fireball_infos;
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            while (!board[row][col].empty()) {
                fireball_infos.emplace_back(row,col,board[row][col].back());
                board[row][col].pop_back();
            }
        }
    }

    for (fireball_info& f : fireball_infos) {
        move(f);
        board[f._r][f._c].emplace_back(f._att);
        if (board[f._r][f._c].size() == 2) points.emplace_back(f._r, f._c);
    }
}

void split(vector<pii>& points)
{
    for (pii& p : points) {
        vector<fireball_attr> tmp;
        swap(tmp, board[p.first][p.second]);

        int fireball_count = tmp.size();
        int sum_m = 0;
        int sum_s = 0;
        bool dir0246 = true;

        for (fireball_attr& attr : tmp) {
            sum_m += attr._m;
            sum_s += attr._s;
            if (dir0246 && (tmp[0]._d + attr._d) % 2 == 1) dir0246 = false;
        }

        if (sum_m / 5 == 0) continue;

        board[p.first][p.second].emplace_back(sum_m/5,sum_s/fireball_count,1-dir0246);
        board[p.first][p.second].emplace_back(sum_m/5,sum_s/fireball_count,3-dir0246);
        board[p.first][p.second].emplace_back(sum_m/5,sum_s/fireball_count,5-dir0246);
        board[p.first][p.second].emplace_back(sum_m/5,sum_s/fireball_count,7-dir0246);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k, ans = 0; cin >> board_size >> m >> k;
    for (int i = 0; i < m; ++i) {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        board[r-1][c-1].emplace_back(m, s, d);
    }

    while (k--) {
        vector<pii> points;
        move(points);
        split(points);
    }

    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            for (auto& f : board[row][col]) {
                ans += f._m;
            }
        }
    }

    cout << ans << '\n';


    return 0;
}
