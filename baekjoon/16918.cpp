#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 200;
const pii dirs[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int hi, wi, simulation_count;
int board[MAXN+2][MAXN+2][2];
bool visited[MAXN+2][MAXN+2];
bool current_flag = true;

void print_current(bool flag = current_flag) {
    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            cout << (board[row][col][flag] == -1?'.':'O');
        }
        cout << '\n';
    }
}

void refil() {
    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            if (board[row][col][1] == -1) 
                board[row][col][0] = 3;
            else 
                board[row][col][0] = board[row][col][1] - 1;
        }
    }
}

void bomb() {
    for (int row = 1; row <= hi; ++row)
        for (int col = 1; col <= wi; ++col)
            visited[row][col] = false;

    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            if (board[row][col][0] == 1) {
                board[row][col][1] = -1;
                for (int d = 0; d < 4; ++d) {
                    board[row+dirs[d].first][col+dirs[d].second][1] = -1;
                    visited[row+dirs[d].first][col+dirs[d].second] = true;
                }
            }
            else if (!visited[row][col])
                board[row][col][1] = board[row][col][0] - 1;
            visited[row][col] = true;
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> hi >> wi >> simulation_count;
    char c;
    for (int row = 1; row <= hi; ++row)
        for (int col = 1; col <= wi; ++col) {
            cin >> c;
            if (c == '.') board[row][col][1] = -1;
            else if (c == 'O') board[row][col][1] = 2;
        }

    for (int step = 1; step < simulation_count; ++step, current_flag ^= true) {
        if (current_flag) refil();
        else bomb();
    }

    print_current();

    return 0;
}
