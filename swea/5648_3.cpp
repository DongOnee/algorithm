#include <iostream>
#include <vector>


using namespace std;

typedef struct
{
    int d,k;
}atom_info;

typedef struct _pii
{
    int x, y;
    _pii(int _x, int _y) : x(_x), y(_y) {}
}pii;

const int dirs[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
const int inv_dir[4] = {1,0,3,2};

int board[2001][2001];
vector<int> candi[2001][2001];
vector<pii> alive_atoms;
atom_info atoms[1001];
int atom_count;
int ans;


bool chk(pii cur) { return 0<=cur.x&&cur.x<2001&&0<=cur.y&&cur.y<2001; }


void init()
{
    ans = 0;

    cin >> atom_count;
    for (int i = 1; i <= atom_count; ++i) {
        int x, y, d, k;
        cin >> x >> y >> d >> k;
        x+=1000, y+=1000;
        atoms[i] = {d, k};
        alive_atoms.emplace_back(x,y);
        board[x][y] = i;
    }
}


void run() 
{
    vector<pii> _alived, _candi;

    for (auto& cur : alive_atoms) {
        int idx = board[cur.x][cur.y];
        board[cur.x][cur.y] = 0;
        int d = atoms[idx].d;
        int k = atoms[idx].k;
        if (k == 0) continue;
        
        pii nxt = {cur.x + dirs[d][0], cur.y + dirs[d][1]};
        if (!chk(nxt)) continue;
        
        int nxt_idx = board[nxt.x][nxt.y];
        if (nxt_idx > 0 && atoms[nxt_idx].d == inv_dir[d] && atoms[nxt_idx].k > 0) {
            board[nxt.x][nxt.y] = 0;
            ans += k;
            ans += atoms[nxt_idx].k;
            atoms[nxt_idx].k = 0;
        }
        else {
            candi[nxt.x][nxt.y].emplace_back(idx);
            _candi.emplace_back(nxt);
        }
    }
    alive_atoms.clear();

    for (auto& cur : _candi) {
        if (candi[cur.x][cur.y].size() == 0) continue;
        else if (candi[cur.x][cur.y].size() == 1) {
            alive_atoms.emplace_back(cur);
            board[cur.x][cur.y] = candi[cur.x][cur.y][0];
        }
        else {
            for (auto& idx : candi[cur.x][cur.y]) 
                ans += atoms[idx].k;
        }

        candi[cur.x][cur.y].clear();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        while (!alive_atoms.empty()) run();

        cout << '#' << test_case << ' '<< ans << '\n';
    }

    return 0;
}
