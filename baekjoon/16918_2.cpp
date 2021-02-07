#include <iostream>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 200;
const pii dirs[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int hi, wi, simulation_count;
int board[MAXN+2][MAXN+2][4];
bool visited[MAXN+2][MAXN+2];

void print_current(int state = 0) {
    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            cout << (board[row][col][state] < 0?'.':'O');
        }
        cout << '\n';
    }
}

void refil(int idx) {
    int prev_index = ( idx + 3 ) % 4;
    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            if (board[row][col][prev_index] == -1) 
                board[row][col][idx] = 3;
            else 
                board[row][col][idx] = board[row][col][prev_index] - 1;
        }
    }
}

void bomb(int idx) {
    for (int row = 1; row <= hi; ++row)
        for (int col = 1; col <= wi; ++col)
            visited[row][col] = false;

    int prev_index = (idx + 3) % 4;
    for (int row = 1; row <= hi; ++row) {
        for (int col = 1; col <= wi; ++col) {
            if (board[row][col][prev_index] == 1) {
                board[row][col][idx] = -1;
                for (int d = 0; d < 4; ++d) {
                    board[row+dirs[d].first][col+dirs[d].second][idx] = -1;
                    visited[row+dirs[d].first][col+dirs[d].second] = true;
                }
            }
            else if (!visited[row][col])
                board[row][col][idx] = board[row][col][prev_index] - 1;
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

    for (int step = 2; step < 6 && step <= simulation_count; ++step) {
        if (step % 2 == 1) bomb(step%4);
        else refil(step%4);
    }

    print_current(simulation_count % 4);

    return 0;
}
