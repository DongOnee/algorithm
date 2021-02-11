#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const int MAXN = 20;
const pii dirs[4] = {{-1,0},{0,-1},{0,1},{1,0}};

int board[MAXN][MAXN];
int board_size, ans;
bool visited[MAXN][MAXN];

pii shark;
int remain, shark_size;

bool chk(pii cur) { return 0<=cur.first&&cur.first<board_size&&0<=cur.second&&cur.second<board_size; }

int bfs() {
    for (int row = 0; row < board_size; ++row) for (int col = 0; col < board_size; ++col) visited[row][col] = false;

    queue<pii> qu;
    qu.push(shark);
    visited[shark.first][shark.second] = true;

    int search_time = 0;
    vector<pii> candidates;
    while (!qu.empty()) {
        long sz = qu.size();
        ++search_time;

        while (sz--) {
            pii f = qu.front(); qu.pop();

            for (int d = 0; d < 4; ++d) {
                pii nxt = f + dirs[d];

                if (!chk(nxt)) continue;
                if (visited[nxt.first][nxt.second]) continue;
                visited[nxt.first][nxt.second] = true;
                
                if (board[nxt.first][nxt.second] > shark_size) continue;
                else if (board[nxt.first][nxt.second] < shark_size && 0 < board[nxt.first][nxt.second]) {
                    candidates.emplace_back(nxt);
                }

                qu.push(nxt);
            }
        }
        
        if (candidates.size() > 0) {
            sort(candidates.begin(), candidates.end());
            pii nxt = candidates[0];
            shark = nxt;
            board[nxt.first][nxt.second] = 0;

            if (--remain == 0) remain = ++shark_size;
            return search_time;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size; 

    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cin >> board[row][col];
            if (board[row][col] == 9) {
                board[row][col] = 0;
                shark = {row, col};
                shark_size = 2;
                remain = 2;
            }
        }
    }

    while (true) {
#if 0
        cout << shark.first << ", " << shark.second << " " << shark_size << " " << ans << "\n";
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cout << board[row][col] << ' ';
        }
        cout << '\n';
    }
#endif
        int ret = bfs();
        if (ret == -1) break;
        ans += ret;
    }



    cout << ans << '\n';

    return 0;
}
