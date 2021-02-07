#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int  MAXN = 100;

int board[MAXN][MAXN];
int wi, l;

bool canWalk(int i, pii dir)
{
    int cnt = 1;
    int hi = board[dir.second * i][dir.first * i];
    pii cur = {dir.second * i, dir.first * i};

    for (int i  = 1; i < wi; ++i) {
        pii nxt = cur + dir;
        int hi_nxt = board[nxt.first][nxt.second];

        if (hi - hi_nxt == 0);
        else if (hi - hi_nxt == -1) {
            cnt -= l;
            if (cnt < 0) return false;
            cnt = 0;
        }
        else if (hi - hi_nxt == 1) {
            if (cnt < 0) return false;
            cnt = -l;
        }
        else
            return false;
        
        cur = nxt;
        ++cnt;
        hi = hi_nxt;
    }

    return cnt >= 0;
}

int run()
{
    int ret = 0;

    for (int i = 0; i < wi; ++i) {
        if (canWalk(i, {1, 0})) ++ret;
        if (canWalk(i, {0, 1})) ++ret;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> wi >> l;
    for (int row = 0; row < wi; ++row) 
        for (int col = 0; col < wi; ++col)
            cin >> board[row][col];

    cout << run() << '\n';

    return 0;
}
