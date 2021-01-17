#include <iostream>

using namespace std;

typedef struct tetromino_s tetromino_t;

struct tetromino_s {
    int hi;
    int wi;
    bool chk[4][4];
};

static tetromino_t tet[] = {
    {4, 1, { {1, 0, 0, 0} , {1, 0, 0, 0} , {1, 0, 0, 0} , {1, 0, 0, 0} }},

    {3, 2, { {1, 1, 0, 0} , {1, 0, 0, 0} , {1, 0, 0, 0} , {0, 0, 0, 0} }},
    {3, 2, { {1, 0, 0, 0} , {1, 1, 0, 0} , {1, 0, 0, 0} , {0, 0, 0, 0} }},
    {3, 2, { {1, 0, 0, 0} , {1, 0, 0, 0} , {1, 1, 0, 0} , {0, 0, 0, 0} }},

    {3, 2, { {1, 0, 0, 0} , {1, 1, 0, 0} , {0, 1, 0, 0} , {0, 0, 0, 0} }},
    {3, 2, { {0, 1, 0, 0} , {1, 1, 0, 0} , {1, 0, 0, 0} , {0, 0, 0, 0} }},

    {3, 2, { {1, 1, 0, 0} , {0, 1, 0, 0} , {0, 1, 0, 0} , {0, 0, 0, 0} }},
    {3, 2, { {0, 1, 0, 0} , {1, 1, 0, 0} , {0, 1, 0, 0} , {0, 0, 0, 0} }},
    {3, 2, { {0, 1, 0, 0} , {0, 1, 0, 0} , {1, 1, 0, 0} , {0, 0, 0, 0} }},

    {2, 2, { {1, 1, 0, 0} , {1, 1, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},

    {2, 3, { {1, 1, 1, 0} , {1, 0, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},
    {2, 3, { {1, 1, 1, 0} , {0, 1, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},
    {2, 3, { {1, 1, 1, 0} , {0, 0, 1, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},

    {2, 3, { {1, 1, 0, 0} , {0, 1, 1, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},
    {2, 3, { {0, 1, 1, 0} , {1, 1, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},

    {2, 3, { {1, 0, 0, 0} , {1, 1, 1, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},
    {2, 3, { {0, 1, 0, 0} , {1, 1, 1, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},
    {2, 3, { {0, 0, 1, 0} , {1, 1, 1, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }},

    {1, 4, { {1, 1, 1, 1} , {0, 0, 0, 0} , {0, 0, 0, 0} , {0, 0, 0, 0} }}
};

const int MAXN = 500;

int board[MAXN][MAXN];
int ans, hi, wi;

void run(int row, int col) {
    for (int t = 0; t < 19; ++t) {
        if (row + tet[t].hi <= hi && col + tet[t].wi <= wi) {
            int ans2 = 0;
            for (int i = 0; i < tet[t].hi; ++i)
                for (int j = 0; j < tet[t].wi; ++j)
                    ans2 += tet[t].chk[i][j] * board[row + i][col + j];
            ans = max(ans, ans2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> hi >> wi;
    for (int r = 0; r < hi; ++r)
        for (int c = 0; c < wi; ++c)
            cin >> board[r][c];

    for (int r = 0; r < hi; ++r)
        for (int c = 0; c < wi; ++c)
            run(r, c);

    cout << ans << '\n';

    return 0;
}