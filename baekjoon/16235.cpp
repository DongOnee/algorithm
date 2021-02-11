#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

typedef struct
{
    int _age;
    pii _point;
}tree;

bool operator<(const tree& a, const tree& b) { return a._age < b._age;}

const int MAXN = 10;
const pii dirs[8] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int board[MAXN][MAXN];
int a[MAXN][MAXN];
int board_size, tree_count, k;

deque<int> trees[MAXN][MAXN];

bool chk(pii cur) { return 0<=cur.first&&cur.first<board_size&&0<=cur.second&&cur.second<board_size; }
bool chk(int r, int c) { return 0<=r&&r<board_size&&0<=c&&c<board_size; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size >> tree_count >> k;
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            cin >> a[row][col];
            board[row][col] = 5;
        }
    }

    while (tree_count--) {
        int age, row, col;
        cin >> row >> col >> age;
        trees[row-1][col-1].push_back(age);
    }

    while (k--) {

        // spring
        vector<tree> dead_trees;
        for (int row = 0; row < board_size; ++row) {
            for (int col = 0; col < board_size; ++col) {
                long sz = trees[row][col].size();
                if (sz == 0) continue;
                sort(trees[row][col].begin(), trees[row][col].end());
                while (sz--) {
                    int age = trees[row][col].front(); trees[row][col].pop_front();
                    if (age <= board[row][col]) {
                        board[row][col] -= age;
                        trees[row][col].push_back(age+1);
                    }
                    else
                        dead_trees.push_back({age , {row, col}});
                }
            }
        }

        // summer
        while (!dead_trees.empty()) {
            tree tp = dead_trees.back(); dead_trees.pop_back();
            board[tp._point.first][tp._point.second] += tp._age/2;
        }

        // autumn
        vector<tree> cur_trees;
        for (int row = 0; row < board_size; ++row) {
            for (int col = 0; col < board_size; ++col) {
                for (auto& t : trees[row][col])
                    if (t % 5 == 0)
                        cur_trees.push_back({t, {row, col}});
            }
        }
        for (auto& t : cur_trees) {
            for (int d = 0; d < 8; ++d) {
                pii nxt = t._point + dirs[d];
                if(!chk(nxt)) continue;
                trees[nxt.first][nxt.second].push_front(1);
            }
        }

        // winter
        for (int row = 0; row < board_size; ++row)
            for (int col = 0; col < board_size; ++col)
                board[row][col] += a[row][col];

    }

    int ans = 0;
    for (int row = 0; row < board_size; ++row) for (int col = 0; col < board_size; ++col) 
        ans += trees[row][col].size();

    cout << ans << '\n';

    return 0;
}
