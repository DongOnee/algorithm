#include <iostream>
#include <algorithm>

using namespace std;

typedef
struct {
    int h;
    int c;
}info;

bool operator<(const info& a, const info& b) { return a.h < b.h; }

int ans;
int dump;
int board[100];

void init()
{
    ans = 0;

    cin >> dump;
    for (int i = 0; i < 100; ++i) {
        cin >> board[i];
    }
    
    sort(board, board+100);
}

void run()
{
    while (dump > 0) {
        auto l = upper_bound(board, board+100, board[0]) - board - 1;
        auto h = lower_bound(board, board+100, board[99]) - board;

        ++board[l];
        --board[h];
        --dump;
    }
    ans = board[99] - board[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int tc = 1; tc <= 10; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
