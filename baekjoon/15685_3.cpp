#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 101;
const int dirs[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

bool board[MAXN][MAXN];

void run()
{
    int x, y, d, g; cin >> x >> y >> d >> g;
    vector<int> turn_codes(1,d);
    board[x][y] = board[x+dirs[d][0]][y+dirs[d][1]] = true;
    x+=dirs[d][0];
    y+=dirs[d][1];
    int turn_count = 1;

    while (g--) {
        for (int i = turn_count-1; 0<= i; --i) {
            int nxt_code = (turn_codes[i]+1)%4;
            x += dirs[nxt_code][0];
            y += dirs[nxt_code][1];
            board[x][y] = true;
            ++turn_count;
            turn_codes.emplace_back(nxt_code);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, ans = 0; cin >> t;
    while (t--) {
        run();
    }

    for (int row = 0; row < MAXN; ++row) for (int col = 0; col < MAXN; ++col) if (board[row][col] && board[row][col+1] && board[row+1][col] && board[row+1][col+1]) ++ans;

    cout << ans << '\n';

    return 0;
}
