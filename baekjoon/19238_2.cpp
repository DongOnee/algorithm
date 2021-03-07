#include <iostream>
#include <utility>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppiii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first, a.second+b.second); }

const int EMPTY =   0;
const int WALL  =   1;
const int MAXN  =   20;
const int MAXM  =   400;
const pii dirs[4] = {{-1,0},{0,-1},{0,1},{1,0}};

int board[MAXN + 2][MAXN + 2], board_size;
int board_client_start[MAXN + 2][MAXN + 2];
bool visited[MAXN + 2][MAXN + 2];
ppiii client_end[MAXM+1];
int client_count;
pii taxi_point;
int taxi_fuel;

int bfs()
{
    int fuel = taxi_fuel;

    for (int r = 1; r <= board_size; ++r) for (int c = 1; c <= board_size; ++c) visited[r][c] = false;
    deque<pii> qu;
    qu.push_back(taxi_point);
    visited[taxi_point.first][taxi_point.second] = true;

    int t = 0, idx = -1;
    while (!qu.empty()) {
        auto sz = qu.size();
        while (sz--) {
            auto f = qu.front(); qu.pop_front();
            if (board_client_start[f.first][f.second] > 0) {
                idx = board_client_start[f.first][f.second];
                board_client_start[f.first][f.second] = 0;

                taxi_point = f;
                taxi_fuel -= t;

                return idx;
            }

            for (int d = 0; d < 4; ++d) {
                pii nxt = f + dirs[d];
                if (board[nxt.first][nxt.second] == WALL) continue;
                if (visited[nxt.first][nxt.second]) continue;

                visited[nxt.first][nxt.second] = true;
                qu.push_back(nxt);
            }
        }
        if (fuel - ++t < 0) return -1;
        sort(qu.begin(), qu.end());
    }

    return -1;
}

int get_distance(pii st, pii ed)
{
    for (int r = 1; r <= board_size; ++r) for (int c = 1; c <= board_size; ++c) visited[r][c] = false;
    queue<pii> qu;
    qu.push(st);
    visited[st.first][st.second] = true;

    int dist = 0;
    while (!qu.empty()) {
        int sz = qu.size();
        ++dist;

        while (sz--) {
            pii f = qu.front(); qu.pop();

            for (int d = 0; d < 4; ++d) {
                pii nxt = f + dirs[d];

                if (board[nxt.first][nxt.second] == WALL) continue;
                if (visited[nxt.first][nxt.second]) continue;

                visited[nxt.first][nxt.second] = true;
                qu.push(nxt);
                if (nxt == ed) return dist;
            }
        }
    }
    
    return -1;
}

bool run()
{
    int client_idx;
    for (int i = 0; i < client_count; ++i) {
        client_idx = bfs();
        if (-1 == client_idx) return false;
        if (client_end[client_idx].second == -1) return false;
        if (taxi_fuel - client_end[client_idx].second < 0) return false;
        taxi_point = client_end[client_idx].first;
        taxi_fuel += client_end[client_idx].second;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int row = 0; row < MAXN+2; ++row) for (int col = 0; col < MAXN+2; ++col) board[row][col] = WALL;

    cin >> board_size >> client_count >> taxi_fuel;
    for (int row = 1; row <= board_size; ++row) for (int col = 1; col <= board_size; ++col) cin >> board[row][col];

    cin >> taxi_point.first >> taxi_point.second;

    for (int i = 1; i <= client_count; ++i) {
        int st_row, st_col, ed_row, ed_col;
        cin >> st_row >> st_col;
        board_client_start[st_row][st_col] = i;

        cin >> ed_row >> ed_col;
        int dist = get_distance({st_row, st_col}, {ed_row, ed_col});
        client_end[i] = {{ed_row, ed_col}, dist};
    }

    cout << (run()?taxi_fuel:-1) << '\n';

    return 0;
}
