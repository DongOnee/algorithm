#include <iostream>
#include <deque>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

typedef pair<int,int> pii;

const int MAX_BOARD_SIZE = 20;
const int MAX_CUSTOMER_COUNT = 400;
const pii dirs[4] = { {-1,0}, {0,-1}, {0,1}, {1,0} };

int board_size, goal_count, init_fuel;
int board[MAX_BOARD_SIZE + 1][MAX_BOARD_SIZE + 1];
pii init_driver;
pii customer_goals[MAX_CUSTOMER_COUNT + 1];

void show_board() {
    for (int row = 0; row <= board_size; ++row) {
        for (int col = 0; col <= board_size; ++col) {
            cout << board[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

inline bool chk_is_board(const int row, const int col) { return 0 < row && row <= board_size && 0 < col && col <= board_size; }

bool find_customer(int& used_fuel, int& customer_index) {
    bool visited_board[MAX_BOARD_SIZE+1][MAX_BOARD_SIZE+1];
    memset(visited_board, false, sizeof(visited_board));

    deque<pii> qu;
    qu.push_back(init_driver);

    visited_board[init_driver.first][init_driver.second] = true;

    while (!qu.empty()) {
        sort(qu.begin(), qu.end());
        int qu_size = qu.size();
        while (qu_size--) {
            pii f = qu.front(); qu.pop_front();

            if (0 != board[f.first][f.second]) {
                customer_index = board[f.first][f.second];
                board[f.first][f.second] = 0;
                init_driver = f;

                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int next_row = f.first + dirs[i].first;
                int next_col = f.second + dirs[i].second;

                if (!chk_is_board(next_row, next_col)) continue;
                if (-1 == board[next_row][next_col] || visited_board[next_row][next_col]) continue;
                else {
                    visited_board[next_row][next_col] = true;
                    qu.push_back({next_row, next_col});
                }
            }
        }
        ++used_fuel;
    }

    return false;
}

bool find_route(int& used_fuel, int customer_index) {
    pii start_point = init_driver;
    pii goal_point = customer_goals[customer_index];

    bool visited_board[MAX_BOARD_SIZE+1][MAX_BOARD_SIZE+1];
    memset(visited_board, false, sizeof(visited_board));

    deque<pii> qu;
    qu.push_back(start_point);

    visited_board[start_point.first][start_point.second] = true;

    while (!qu.empty()) {
        sort(qu.begin(), qu.end());
        int qu_size = qu.size();
        ++used_fuel;
        while (qu_size--) {
            pii f = qu.front(); qu.pop_front();

            for (int i = 0; i < 4; ++i) {
                int next_row = f.first + dirs[i].first;
                int next_col = f.second + dirs[i].second;

                if (!chk_is_board(next_row, next_col)) continue;
                if (-1 == board[next_row][next_col] || visited_board[next_row][next_col]) continue;
                else if (make_pair(next_row, next_col) == goal_point) {
                    init_driver = { next_row, next_col };

                    return true;
                }
                else {
                    visited_board[next_row][next_col] = true;
                    qu.push_back({next_row, next_col});
                }
            }
        }
    }

    return false;
}

int run() {
    int ret = init_fuel;

    for (int i = 0; i < goal_count; ++i) {
        // find shortest customer
        int customer_index = 0;
        int used_fuel = 0;
        if (!find_customer(used_fuel, customer_index)) return -1;
        ret -= used_fuel;
        if ( ret < 0) return -1;
        
        used_fuel = 0;
        if (!find_route(used_fuel, customer_index)) return -1;
        if (ret - used_fuel < 0) return -1;
        ret += used_fuel;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_size >> goal_count >> init_fuel;

    memset(board, -1, sizeof(board));
    for (int row = 1; row <= board_size; ++row) {
        for (int col = 1; col <= board_size; ++col) {
            cin >> board[row][col];
            board[row][col] *= -1;
        }
    }

    cin >> init_driver.first >> init_driver.second;

    for (int i = 1, row, col; i <= goal_count; ++i) {
        cin >> row >> col >> customer_goals[i].first
                          >> customer_goals[i].second;
        board[row][col] = i;
    }

    cout << run() << "\n";


    return 0;
}
