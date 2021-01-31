#include <iostream>
#include <vector>

using namespace std;

const int MAX_HEIGHT = 30;
const int MAX_WIDTH = 10;

int hi, wi, ans = -1;
int ladder[MAX_HEIGHT][MAX_WIDTH];
int ladder_cp[MAX_HEIGHT][MAX_WIDTH];

bool go_ladder()
{
    for (int col = 0; col < wi; ++col) {
        int cur = col;
        for (int row = 0; row < hi; ++row) {
            cur += ladder[row][cur];
        }

        if (cur != col) return false;
    }

    return true;
}

bool select_ladder(int cnt, int r, int c)
{
    if (cnt == 0) {
        return go_ladder();
    }

    // bool ret = false;
    for (int row = r, col = c; row < hi; ++row, col = 0) {
        for (; col < wi-1; ++col) {
            if (ladder[row][col] == 0 && ladder[row][col+1] == 0) {
                ladder[row][col] = 1;
                ladder[row][col+1] = -1;
                if (select_ladder(cnt-1, row, col+1)) return true;
                // ret = ret || select_ladder(cnt-1, row, col+1);
                ladder[row][col] = 0;
                ladder[row][col+1] = 0;
            }
        }
    }

    return false;
}

void run()
{
    for (int cnt = 0; cnt < 4; ++cnt) {

        for (int row = 0; row < hi; ++row)
            for (int col = 0; col < wi; ++col)
                ladder[row][col] = ladder_cp[row][col];

        if (select_ladder(cnt, 0, 0)) {
            ans = cnt;
            break;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ladder_count;
    cin >> wi >> ladder_count >> hi;
    while (ladder_count--) {
        int a, b; cin >> a >> b;
        --a, --b;
        ladder_cp[a][b] = 1;
        ladder_cp[a][b+1] = -1;
    }

    run();

    cout << ans << '\n';

    return 0;
}
