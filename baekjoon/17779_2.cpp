#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int board[MAXN][MAXN];
int board_size;
int ans = 987654321;

void run(int R, int C, int d1, int d2)
{
    int people[5] = {0, };
    for (int r = 0; r < board_size; ++r) {
        for (int c = 0; c < board_size; ++c) {
            int team = 0;
            if (r + c < R + C && r < R +d1 && c <= C) team = 0;
            else if (r - c < R - C && r <= R + d2 && c > C) team = 1;
            else if (r - c > R - C + 2* d1 && r >= R+ d1 && c < C - d1 + d2) team = 2;
            else if (r + c > R + C + 2 * d2 && r > R + d2 && c >= C - d1 + d2) team = 3;
            else team = 4;
            people[team] += board[r][c];
        }
    }

    sort(people, people + 5);

    ans = min(ans, people[4] - people[0]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size;
    for (int r = 0; r < board_size; ++r)
        for (int c = 0; c < board_size; ++c)
            cin >> board[r][c];
    
    for (int R = 0; R < board_size; ++R) {
        for (int C = 0; C < board_size; ++C) {
            for (int d1 = 1; R + d1 < board_size && 0 <= C - d1; ++d1) {
                for (int d2 = 1; R + d2 < board_size
                              && C + d2 < board_size
                              && R - d1 + d2 < board_size
                              && 0 <= C - d1 + d2
                              && C - d1 + d2 < board_size; ++ d2) {
                    run(R, C, d1, d2);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
