#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 100;
const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int board[MAXN+2][MAXN+2], board_size;
bool visited[MAXN+2][MAXN+2];

typedef
struct
{
    int t, r, c;
}item;

bool operator<(const item& a, const item& b) { return a.t > b.t; }

void init()
{
    cin >> board_size;
    for (int r = 1; r <= board_size; ++r) {
        string tmp; cin >> tmp;
        for (int c = 1; c <= board_size; ++c) {
            board[r][c] = tmp[c-1] - '0';
            visited[r][c] = false;
        }
        visited[r][0] = visited[0][r] = visited[board_size+1][r] = visited[r][board_size+1] = true;
    }
}

int run()
{
    priority_queue<item> pq;
    pq.push({0,1,1});

    while (!pq.empty()) {
        item tp = pq.top(); pq.pop();

        if (tp.r == board_size && tp.c == board_size) return tp.t;
        if (visited[tp.r][tp.c]) continue;
        visited[tp.r][tp.c] = true;

        for (int d = 0; d < 4; ++d) {
            int nr = tp.r + dirs[d][0];
            int nc = tp.c + dirs[d][1];

            if (visited[nr][nc]) continue;
            int nt = tp.t + board[nr][nc];
            pq.push({nt, nr, nc});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        int ans = run();

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
