#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 20

struct point
{
    int x, y;
    point() : x(0), y(0) {};
    point(int _x, int _y) : x(_x), y(_y) {};

    point operator-(const point& p) const
    {
        return point(x - p.x, y - p.y);
    }
};


bool close(const point& a, const point& b)
{
    point p = a - b;
    
    return abs(p.x) + abs(p.y) == 1;
}


int n;
int board[MAXN+2][MAXN+2];
int preference[MAXN*MAXN + 1][4];
point seat[MAXN*MAXN+1];
int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int score[5] = {0, 1, 10, 100, 1000};

void setSeat(int idx, point p)
{
    seat[idx] = p;
    board[p.x][p.y] = idx;
}


void setSeat(int idx, int x, int y)
{
    setSeat(idx, point(x,y));
}


struct item
{
    point p;
    int nearPreference;
    int nearEmpty;

    bool operator<(const item& i)  const {
        return (nearPreference==i.nearPreference?
            (nearEmpty==i.nearEmpty?
        (p.x==i.p.x?p.y<i.p.y:p.x<i.p.x)
            :nearEmpty>i.nearEmpty)
                :nearPreference>i.nearPreference);
    }
};



point getCollectSeat(int idx)
{
    vector<item> cands;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (board[i][j] != 0) continue;
            cands.emplace_back();
            auto& cand = cands.back();

            cand.p = point(i,j);
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                for (int c = 0; c < 4; ++c) {
                    if (board[ni][nj] == preference[idx][c]) {
                        ++cand.nearPreference;
                    }
                }
                
                if (board[ni][nj] == 0) ++cand.nearEmpty;
            }
        }
    }

    sort(cands.begin(), cands.end());

#ifndef ONLINE_JUDGE
    cout << idx << '\n';
    for (auto c : cands) {
        cout << '(' << c.p.x  << ',' << c.p.y << ')' << ' ' << c.nearPreference << ' ' << c.nearEmpty << '\n';
    }
#endif

    return cands[0].p;
}


int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i <= n+1; ++i) {
        board[i][0] = board[i][n+1] = board[0][i] = board[n+1][i] = -1;
    }

    for (int i = 0; i < n * n; ++i) {
        int idx; cin >> idx;
        cin >> preference[idx][0] >> preference[idx][1] >> preference[idx][2] >> preference[idx][3];

        point p = getCollectSeat(idx);
        setSeat(idx, p);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            int idx = board[i][j];
            int count_preference = 0;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                for (int c = 0; c < 4; ++c) {
                    if (board[ni][nj] == preference[idx][c]) {
                        ++count_preference;
                    }
                }
            }
#ifndef ONLINE_JUDGE
            cout << board[i][j] << ' ';
#endif
            ans += score[count_preference];
        }
#ifndef ONLINE_JUDGE
        cout << '\n';
#endif
    }

    cout << ans << '\n';

    return 0;
}